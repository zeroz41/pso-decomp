/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

#include "MSL_C/MSL_Common_Embedded/Math/fdlibm.h"

double asin(double x)
{
#ifdef _IEEE_LIBM
  return __ieee754_asin(x);
#else
  double z;
  z = __ieee754_asin(x);
  if (_LIB_VERSION == _IEEE_ || isnan(x))
    return z;
  if (fabs(x) > 1.0) {
    return __kernel_standard(x, x, 2);
  } else
    return z;
#endif
}
