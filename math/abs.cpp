#include <math.h>
#include "internal.h"
#define _abs(name, type) \
    type name (type n) { \
        return __abs(n); \
    }

_abs(abs, int);
_abs(labs, long);
_abs(llabs, long long);
_abs(imaxabs, intmax_t);
_abs(fabsf, float);
_abs(fabs, double);
_abs(fabsl, long double);

