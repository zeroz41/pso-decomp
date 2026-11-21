#ifndef _FDLIBM_H
#define _FDLIBM_H

/**
 * ====================================================
 * Copyright (C) 2004 by Sun Microsystems, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

#if defined(i386) || defined(i486) || defined(intel) || defined(x86) || defined(i86pc) || defined(__alpha) || \
    defined(__osf__)
#define __LITTLE_ENDIAN
#endif

#ifdef __LITTLE_ENDIAN
#define __HI(x) *(1 + (int*)&x)
#define __LO(x) *(int*)&x
#define __HIp(x) *(1 + (int*)x)
#define __LOp(x) *(int*)x
#else
#define __HI(x) *(int*)&x
#define __LO(x) *(1 + (int*)&x)
#define __HIp(x) *(int*)x
#define __LOp(x) *(1 + (int*)x)
#endif

#define _IEEE_LIBM

#define __P(p) p

extern int signgam;

#define MAXFLOAT ((f32)3.40282346638528860e+38)

enum fdversion { fdlibm_ieee = -1, fdlibm_svid, fdlibm_xopen, fdlibm_posix };

#define _LIB_VERSION_TYPE enum fdversion
#define _LIB_VERSION _fdlib_version

extern _LIB_VERSION_TYPE _LIB_VERSION;

#define _IEEE_ fdlibm_ieee
#define _SVID_ fdlibm_svid
#define _XOPEN_ fdlibm_xopen
#define _POSIX_ fdlibm_posix

struct exception {
    int type;
    char* name;
    double arg1;
    double arg2;
    double retval;
};

#define HUGE MAXFLOAT

#define X_TLOSS 1.41484755040568800000e+16

#define DOMAIN 1
#define SING 2
#define OVERFLOW 3
#define UNDERFLOW 4
#define TLOSS 5
#define PLOSS 6

extern double acos __P((double));
extern double asin __P((double));
extern double atan __P((double));
extern double atan2 __P((double, double));
extern double cos __P((double));
extern double sin __P((double));
extern double tan __P((double));

extern double cosh __P((double));
extern double sinh __P((double));
extern double tanh __P((double));

extern double exp __P((double));
extern double frexp __P((double, int*));
extern double ldexp __P((double, int));
extern double scalbn __P((double, int));
extern double log __P((double));
extern double log10 __P((double));
extern double modf __P((double, double*));

extern double pow __P((double, double));
extern double sqrt __P((double));

extern double ceil __P((double));
extern double fabs __P((double));
extern double fabs__Fd(double);
extern double floor __P((double));
extern double fmod __P((double, double));

extern double erf __P((double));
extern double erfc __P((double));
extern double gamma __P((double));
extern double hypot __P((double, double));
extern int isnan __P((double));
extern int finite __P((double));
extern double j0 __P((double));
extern double j1 __P((double));
extern double jn __P((int, double));
extern double lgamma __P((double));
extern double y0 __P((double));
extern double y1 __P((double));
extern double yn __P((int, double));

extern double acosh __P((double));
extern double asinh __P((double));
extern double atanh __P((double));
extern double cbrt __P((double));
extern double logb __P((double));
extern double nextafter __P((double, double));
extern double remainder __P((double, double));
#ifdef _SCALB_INT
extern double scalb __P((double, int));
#else
extern double scalb __P((double, double));
#endif

extern int matherr __P((struct exception*));

extern double significand __P((double));

extern double copysign __P((double, double));
extern int ilogb __P((double));
extern double rint __P((double));
extern double scalbn __P((double, int));

extern double expm1 __P((double));
extern double log1p __P((double));

#ifdef _REENTRANT
extern double gamma_r __P((double, int*));
extern double lgamma_r __P((double, int*));
#endif

extern double __ieee754_sqrt __P((double));
extern double __ieee754_acos __P((double));
extern double __ieee754_acosh __P((double));
extern double __ieee754_log __P((double));
extern double __ieee754_atanh __P((double));
extern double __ieee754_asin __P((double));
extern double __ieee754_atan2 __P((double, double));
extern double __ieee754_exp __P((double));
extern double __ieee754_cosh __P((double));
extern double __ieee754_fmod __P((double, double));
extern double __ieee754_pow __P((double, double));
extern double __ieee754_lgamma_r __P((double, int*));
extern double __ieee754_gamma_r __P((double, int*));
extern double __ieee754_lgamma __P((double));
extern double __ieee754_gamma __P((double));
extern double __ieee754_log10 __P((double));
extern double __ieee754_sinh __P((double));
extern double __ieee754_hypot __P((double, double));
extern double __ieee754_j0 __P((double));
extern double __ieee754_j1 __P((double));
extern double __ieee754_y0 __P((double));
extern double __ieee754_y1 __P((double));
extern double __ieee754_jn __P((int, double));
extern double __ieee754_yn __P((int, double));
extern double __ieee754_remainder __P((double, double));
extern int __ieee754_rem_pio2 __P((double, double*));
#ifdef _SCALB_INT
extern double __ieee754_scalb __P((double, int));
#else
extern double __ieee754_scalb __P((double, double));
#endif

extern double __kernel_standard __P((double, double, int));
extern double __kernel_sin __P((double, double, int));
extern double __kernel_cos __P((double, double));
extern double __kernel_tan __P((double, double, int));
extern int __kernel_rem_pio2 __P((double*, double*, int, int, int, const int*));

#ifndef FABS_DECLARED
#define FABS_DECLARED
inline double fabs(double x) {
    return __fabs(x);
}
#endif

extern unsigned int __float_nan[];
extern unsigned int __float_huge[];
#ifndef INFINITY
#define INFINITY (*(float*)__float_huge)
#endif
#ifndef NAN
#define NAN (*(float*)__float_nan)
#endif
#ifndef HUGE_VALF
#define HUGE_VALF (*(float*)__float_huge)
#endif

#ifdef __cplusplus
};
#endif

#endif
