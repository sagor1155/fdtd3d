#include "CallBack.h"
#include "PhysicsConst.h"
#include "Settings.h"

#include <cmath>

#ifndef COMPLEX_FIELD_VALUES

FieldValue CallBack::polinom1_ez (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * SQR (coord.getX ()) * t;
}

FieldValue CallBack::polinom1_hy (GridCoordinateFP3D coord, FPValue t)
{
  return PhysicsConst::Eps0 * polinom1_ez (coord, t);
}

FieldValue CallBack::polinom1_jz (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * PhysicsConst::Eps0 * (-2 * coord.getX () * t + SQR (coord.getX ()));
}

FieldValue CallBack::polinom1_my (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * (-2 * coord.getX () * t
    + SQR (coord.getX ()) * PhysicsConst::Eps0 * PhysicsConst::Mu0);
}

FieldValue CallBack::polinom2_ex (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * t * (SQR (coord.getY ()) + SQR (coord.getZ ()));
}

FieldValue CallBack::polinom2_ey (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * t * (SQR (coord.getX ()) + SQR (coord.getZ ()));
}

FieldValue CallBack::polinom2_ez (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * t * (SQR (coord.getX ()) + SQR (coord.getY ()));
}

FieldValue CallBack::polinom2_hx (GridCoordinateFP3D coord, FPValue t)
{
  return PhysicsConst::Eps0 * polinom2_ex (coord, t);
}

FieldValue CallBack::polinom2_hy (GridCoordinateFP3D coord, FPValue t)
{
  return PhysicsConst::Eps0 * polinom2_ey (coord, t);
}

FieldValue CallBack::polinom2_hz (GridCoordinateFP3D coord, FPValue t)
{
  return PhysicsConst::Eps0 * polinom2_ez (coord, t);
}

FieldValue CallBack::polinom2_jx (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * PhysicsConst::Eps0 * (2 * t * (coord.getZ () - coord.getY ()) + SQR (coord.getY ()) + SQR (coord.getZ ()));
}

FieldValue CallBack::polinom2_jy (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * PhysicsConst::Eps0 * (2 * t * (coord.getX () - coord.getZ ()) + SQR (coord.getX ()) + SQR (coord.getZ ()));
}

FieldValue CallBack::polinom2_jz (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * PhysicsConst::Eps0 * (2 * t * (coord.getY () - coord.getX ()) + SQR (coord.getX ()) + SQR (coord.getY ()));
}

FieldValue CallBack::polinom2_mx (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * (2 * t * (coord.getY () - coord.getZ ())
    + PhysicsConst::Eps0 * PhysicsConst::Mu0 * (SQR (coord.getY ()) + SQR (coord.getZ ())));
}

FieldValue CallBack::polinom2_my (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * (2 * t * (coord.getZ () - coord.getX ())
    + PhysicsConst::Eps0 * PhysicsConst::Mu0 * (SQR (coord.getX ()) + SQR (coord.getZ ())));
}

FieldValue CallBack::polinom2_mz (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * (2 * t * (coord.getX () - coord.getY ())
    + PhysicsConst::Eps0 * PhysicsConst::Mu0 * (SQR (coord.getX ()) + SQR (coord.getY ())));
}

FieldValue CallBack::polinom3_ez (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * SQR (coord.getX () * t);
}

FieldValue CallBack::polinom3_hy (GridCoordinateFP3D coord, FPValue t)
{
  return PhysicsConst::Eps0 * polinom3_ez (coord, t);
}

FieldValue CallBack::polinom3_jz (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * 2 * PhysicsConst::Eps0 * coord.getX () * t * (coord.getX () - t);
}

FieldValue CallBack::polinom3_my (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight) * 2 * coord.getX () * t
    * (PhysicsConst::Eps0 * PhysicsConst::Mu0 * coord.getX () - t);
}

FieldValue CallBack::sin1_ez (GridCoordinateFP3D coord, FPValue t)
{
  return SQR (PhysicsConst::SpeedOfLight)
         * sin (2 * PhysicsConst::Pi * (PhysicsConst::SpeedOfLight / solverSettings.getSourceWaveLength ()) * t
                - 2 * PhysicsConst::Pi / solverSettings.getSourceWaveLength () * coord.getX ());
}

FieldValue CallBack::sin1_hy (GridCoordinateFP3D coord, FPValue t)
{
  return -1 * SQR (PhysicsConst::SpeedOfLight) / (PhysicsConst::Mu0 * PhysicsConst::SpeedOfLight)
         * sin (2 * PhysicsConst::Pi * (PhysicsConst::SpeedOfLight / solverSettings.getSourceWaveLength ()) * t
                - 2 * PhysicsConst::Pi / solverSettings.getSourceWaveLength () * coord.getX ());
}

#endif /* COMPLEX_FIELD_VALUES */