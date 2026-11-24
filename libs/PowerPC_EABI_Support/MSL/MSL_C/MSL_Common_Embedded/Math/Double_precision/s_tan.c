/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#include "MSL_C/MSL_Common_Embedded/Math/fdlibm.h"

double tan(double x)
{
  double y[2], z = 0.0;
  int n, ix;

  ix = __HI(x);

  ix &= 0x7fffffff;
  if (ix <= 0x3fe921fb)
    return __kernel_tan(x, z, 1);

  else if (ix >= 0x7ff00000)
    return x - x;

  else {
    n = __ieee754_rem_pio2(x, y);
    return __kernel_tan(y[0], y[1], 1 - ((n & 1) << 1));
  }
}
