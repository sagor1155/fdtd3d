#!/bin/bash

set -e

BASE_DIR=$1
SOURCE_DIR=$2

function launch ()
{
  output_file=$(mktemp /tmp/fdtd3d.vacuum1D.XXXXXXXX)

  ./fdtd3d --cmd-from-file ${SOURCE_DIR}/Examples/vacuum1D_EzHx.txt &> $output_file

  local ret=$?

  val_max=$(cat previous-1_[timestep=100]_[pid=0]_[name=Ez]_[mod].txt | awk '{print $1}')
  val_min=$(cat previous-1_[timestep=100]_[pid=0]_[name=Ez]_[mod].txt | awk '{print $2}')
  is_ok=$(echo $val_max $val_min | awk '
            {
              if (1.01 <= $1 && $1 <= 1.02 && 0.0 == $2)
              {
                print 1;
              }
              else
              {
                print 0;
              }
            }')
  if [ "$is_ok" != "1" ]; then
    echo "Test result is incorrect for Examples/vacuum1D_EzHx.txt"
    ret=$((2))
  fi

  if [ "$ret" != "0" ]; then
    return $ret
  fi

  ./fdtd3d --cmd-from-file ${SOURCE_DIR}/Examples/vacuum1D_EzHx_scattered.txt &> $output_file

  ret=$?

  val_max=$(cat previous-1_[timestep=100]_[pid=0]_[name=Ez]_[mod].txt | awk '{print $1}')
  val_min=$(cat previous-1_[timestep=100]_[pid=0]_[name=Ez]_[mod].txt | awk '{print $2}')
  is_ok=$(echo $val_max $val_min | awk '
            {
              if (0.0 <= $1 && $1 <= 1e-14 && 0.0 == $2)
              {
                print 1;
              }
              else
              {
                print 0;
              }
            }')
  if [ "$is_ok" != "1" ]; then
    echo "Test result is incorrect for Examples/vacuum1D_EzHx_scattered.txt"
    ret=$((2))
  fi

  return $ret
}

CUR_DIR=`pwd`
TEST_DIR=$(dirname $(readlink -f $0))
cd $TEST_DIR

retval=$((0))
launch
if [ $? -ne 0 ]; then
  retval=$((1))
fi

cd $CUR_DIR

exit $retval
