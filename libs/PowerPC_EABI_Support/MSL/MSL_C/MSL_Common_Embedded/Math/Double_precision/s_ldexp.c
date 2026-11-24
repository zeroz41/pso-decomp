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
#include "MSL_C/MSL_Common/float.h"

static const double
two54   =  1.80143985094819840000e+16,
twom54  =  5.55111512312578270212e-17,
huge   = 1.0e+300,
tiny   = 1.0e-300;

	double ldexp(double value, int exp)
{
	int  k,hx,lx;

	if(!isfinite(value)||value==0.0) return value;

	hx = __HI(value);
	lx = __LO(value);
    k = (hx&0x7ff00000)>>20;
    if (k==0) {
        if ((lx|(hx&0x7fffffff))==0) return value;
    value *= two54;
    hx = __HI(value);
    k = ((hx&0x7ff00000)>>20) - 54;
        if (exp< -50000) return tiny*value;
    }
    if (k==0x7ff) return value+value;
    k = k+exp;
    if (k >  0x7fe) return huge*copysign(huge,value);
    if (k > 0)
    {__HI(value) = (hx&0x800fffff)|(k<<20); return value;}
    if (k <= -54)
        if (exp > 50000)
    return huge*copysign(huge,value);
    else return tiny*copysign(tiny,value);
    k += 54;
    __HI(value) = (hx&0x800fffff)|(k<<20);
    return value*twom54;

	return value;
}
