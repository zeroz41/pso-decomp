#ifndef _MATH_H_
#define _MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

double acos(double x);
double asin(double x);
double atan(double x);
double atan2(double y, double x);
double ceil(double x);
double cos(double x);
double floor(double x);
double log(double x);
double pow(double x, double y);
double sin(double x);
double tan(double x);

// MSL defines fabs inline, on the compiler's __fabs.
inline double fabs(double x) { return __fabs(x); }

float cosf(float x);
float powf(float x, float y);
float sinf(float x);
float tanf(float x);

#ifdef __cplusplus
}
#endif

#endif
