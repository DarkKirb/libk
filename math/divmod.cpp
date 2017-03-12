#include <math.h>
#include "internal.h"
#define intdiv(name, type1, type2) \
    type1 name (type2 x, type2 y) { \
        type1 result; \
        result.quot = x / y; \
        result.rem = x % y; \
        return result; \
    }

intdiv(div, div_t, int);
intdiv(ldiv, ldiv_t, long);
intdiv(lldiv, lldiv_t, long long);
intdiv(imaxdiv, imaxdiv_t, intmax_t);

#define floatmod(name, type) \
    type name (type x, type y) { \
        return __mod(x, y); \
    }

#define floatrem(name, type) \
    type name (type x, type y) { \
        return __remainder(x, y); \
    }

#define floatquo(name, type) \
    type name (type x, type y, int* quot) { \
        type temp = x / y; \
        *quot = *((int*)(&temp)); \
        *quot = abs(*quot); \
        if(temp < 0) *quot = -*quot; \
        return __remainder(x,y); \
    }

#define floatma(name, type) \
    type name (type x, type y, type z) { \
        return (x*y) + z; \
    }

floatmod(fmodf, float);
floatmod(fmod, double);
floatmod(fmodl, long double);

floatrem(remainderf, float);
floatrem(remainder, double);
floatrem(remainderl, long double);

floatquo(remquof, float);
floatquo(remquo, double);
floatquo(remquol, long double);

floatma(fmaf, float);
floatma(fma, double);
floatma(fmal, long double);
