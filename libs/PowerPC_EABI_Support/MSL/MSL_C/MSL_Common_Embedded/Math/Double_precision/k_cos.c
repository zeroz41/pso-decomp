/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#include "MSL_C/MSL_Common_Embedded/Math/fdlibm.h"

static const double
    one = 1.00000000000000000000e+00,
    C1 = 4.16666666666666019037e-02,
    C2 = -1.38888888888741095749e-03,
    C3 = 2.48015872894767294178e-05,
    C4 = -2.75573143513906633035e-07,
    C5 = 2.08757232129817482790e-09,
    C6 = -1.13596475577881948265e-11;

double __kernel_cos(double x, double y)
{
    double a, hz, z, r, qx;
    int ix;
    ix = __HI(x) & 0x7fffffff;
    if (ix < 0x3e400000) {
        if (((int)x) == 0)
            return one;
    }
    z = x * x;
    r = z * (C1 + z * (C2 + z * (C3 + z * (C4 + z * (C5 + z * C6)))));
    if (ix < 0x3FD33333)
        return one - (0.5 * z - (z * r - x * y));
    else {
        if (ix > 0x3fe90000) {
            qx = 0.28125;
        } else {
            __HI(qx) = ix - 0x00200000;
            __LO(qx) = 0;
        }
        hz = 0.5 * z - qx;
        a = one - qx;
        return a - (hz - (z * r - x * y));
    }
}
