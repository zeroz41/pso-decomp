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

double pow(double x, double y)
{
#ifdef _IEEE_LIBM
  return __ieee754_pow(x, y);
#else
  double z;
  z = __ieee754_pow(x, y);
  if (_LIB_VERSION == _IEEE_ || isnan(y))
    return z;
  if (isnan(x)) {
    if (y == 0.0)
      return __kernel_standard(x, y, 42);
    else
      return z;
  }
  if (x == 0.0) {
    if (y == 0.0)
      return __kernel_standard(x, y, 20);
    if (isfinite(y) && y < 0.0)
      return __kernel_standard(x, y, 23);
    return z;
  }
  if (!isfinite(z)) {
    if (isfinite(x) && isfinite(y)) {
      if (isnan(z))
        return __kernel_standard(x, y, 24);
      else
        return __kernel_standard(x, y, 21);
    }
  }
  if (z == 0.0 && isfinite(x) && isfinite(y))
    return __kernel_standard(x, y, 22);
  return z;
#endif
}
