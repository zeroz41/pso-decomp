#ifndef _MATH_H_
#define _MATH_H_

#define NAN       (0.0f / 0.0f)
#define HUGE_VALF (1.0f / 0.0f)
#define INFINITY  (1.0f / 0.0f)

double fabs(double x);
double sin(double x);
double cos(double x);

float sinf(float x);
float cosf(float x);
float tanf(float x);
float acosf(float x);
float powf(float x, float y);

double ldexp(double x, int exp);

double scalbn(double x, int n);

double copysign(double x, double y);

#pragma cplusplus on

double floor(double x);

#ifdef PSO_SDK_COMPACT_MATH
#define PSO_MATH_LOCAL_CONST const
#else
#define PSO_MATH_LOCAL_CONST static const
#endif

extern inline float sqrtf(float x)
{
    PSO_MATH_LOCAL_CONST double _half = .5;
    PSO_MATH_LOCAL_CONST double _three = 3.0;
    volatile float y;
    if (x > 0.0f)
    {
        double guess = __frsqrte((double)x);
        guess = _half*guess*(_three - guess*guess*x);
        guess = _half*guess*(_three - guess*guess*x);
        guess = _half*guess*(_three - guess*guess*x);
        y = (float)(x*guess);
        return y ;
    }
    return x;
}

extern inline float sqrt(float x)
{
    PSO_MATH_LOCAL_CONST double _half = .5;
    PSO_MATH_LOCAL_CONST double _three = 3.0;
    volatile float y;
    if (x > 0.0f)
    {
        double guess = __frsqrte((double)x);
        guess = _half*guess*(_three - guess*guess*x);
        guess = _half*guess*(_three - guess*guess*x);
        guess = _half*guess*(_three - guess*guess*x);
        y = (float)(x*guess);
        return y ;
    }
    return x;
}

#undef PSO_MATH_LOCAL_CONST

#define fabs(x) __fabs(x)
#define fabsf(x) __fabsf(x)

long __fpclassifyf(float __value);
long __fpclassifyd(double __value);

#define FP_NAN       1
#define FP_INFINITE  2
#define FP_ZERO      3
#define FP_NORMAL    4
#define FP_SUBNORMAL 5

#define fpclassify(x) (sizeof(x) == sizeof(float) ? __fpclassifyf((float)(x)) : __fpclassifyd((double)(x)))
#define isfinite(x) ((fpclassify(x) > FP_INFINITE))

inline float fmodf(float x, float m)
{
    float a = fabsf(m);
    float b = fabsf(x);
    if (a > b)
        return x;
    else
    {
        long long c = (long long)(x / m);
        return x - m * c;
    }
}

#pragma cplusplus reset

#endif
