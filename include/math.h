#pragma once
#include <stdint.h>
int abs(int n);
long labs(long n);
long long llabs(long long n);
intmax_t imaxabs(intmax_t n);
float fabsf(float n);
double fabs(double n);
long double fabsl(long double n);

struct div_t { int quot; int rem; };
struct ldiv_t { long quot; long rem; };
struct lldiv_t { long long quot; long long rem; };
struct imaxdiv_t { intmax_t quot; intmax_t rem; };

div_t div(int x, int y);
ldiv_t ldiv(long x, long y);
lldiv_t lldiv(long long x, long long y);
imaxdiv_t imaxdiv(intmax_t x, intmax_t y);

float fmodf(float x, float y);
double fmod(double x, double y);
long double fmodl(long double x, long double y);

float remainderf(float x, float y);
double remainder(double x, double y);
long double remainderl(long double x, long double y);

float remquof( float x, float y, int *quo);
double remquo( double x, double y, int *quo);
long double remquol( long double x, long double y, int *quo);

float fmaf(float x, float y, float z);
double fma(double x, double y, double z);
long double fmal(long double x, long double y, long double z);

#define fmaxf(x, y) fmax(x, y)
#define fmax(x, y) ((x) > (y) ? (x) : (y))
#define fmaxl(x, y) fmax(x, y)

#define fminf(x, y) fmin(x, y)
#define fmin(x, y) ((x) > (y) ? (y) : (x))
#define fminl(x, y) fmin(x, y)

#define fdimf(x, y) fdim(x, y)
#define fdim(x, y) fmax((x)-(y),0)
#define fdiml(x, y) fdim(x, y)

#define nanf(x) (0.0f)
#define nan(x) (0.0)
#define nanl(x) (0.0l)

float expf(float v);
double exp(double v);
long double expl(long double v);

float exp2f(float v);
double exp2(double v);
long double exp2l(long double v);

float expm1f(float v);
double expm1(double v);
long double expm1l(long double v);

float logf(float v);
double log(double v);
long double logl(double v);

float log2f(float v);
double log2(double v);
long double log2l(long double v);

float log10f(float v);
double log10(double v);
long double log10l(long double v);

float log1pf(float v);
double log1p(double v);
long double log1pl(long double v);

float sqrtf(float x);
double sqrt(double x);
long double sqrtl(long double x);

float cbrtf(float x);
double cbrt(double x);
long double cbrtl(long double x);

float hypotf(float x, float y);
double hypot(double x, double y);
long double hypotl(long double x, long double y);

#define PI 3.141592653589793

float sinf(float x);
double sin(double x);
long double sinl(long double x);

float cosf(float x);
double cos(double x);
long double cosl(long double x);

float tanf(float x);
double tan(double x);
long double tanl(long double x);

float asinf(float x);
double asin(double x);
long double asinl(long double x);

float acosf(float x);
double acos(double x);
long double acosl(long double x);

float atanf(float x);
double atan(double x);
long double atanl(long double x);

float sinhf(float x);
double sinh(double x);
long double sinhl(long double x);

float coshf(float x);
double cosh(double x);
long double coshl(long double x);

float tanhf(float x);
double tanh(double x);
long double tanhl(long double x);

float asinhf(float x);
double asinh(double x);
long double asinhl(long double x);

float acoshf(float x);
double acosh(double x);
long double acoshl(long double x);

float atanhf(float x);
double atanh(double x);
long double atanhl(long double x);
