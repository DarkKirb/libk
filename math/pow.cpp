#include <math.h>
#include "internal.h"

#define defpower(name, type, power, prec) \
    type name ( type x ) { \
        return __exp(x, power, prec); \
    }

#define defhypot(name, type, prec) \
    type name ( type x, type y ) { \
        return __exp(x*x+y*y, (type)0.5, prec); \
    }

#define defpow(name, type, prec) \
    type name (type x, type y) { \
        return __exp(x, y, prec); \
    }

defpower(sqrtf, float, 0.5f, SP);
defpower(sqrt, double, 0.5, DP);
defpower(sqrtl, long double, 0.5l, LDP);

defpower(cbrtf, float, 1.0f/3, SP);
defpower(cbrt, double, 1.0/3, SP);
defpower(cbrtl, long double, 1.0l/3, LDP);

defhypot(hypotf, float, SP);
defhypot(hypot, double, DP);
defhypot(hypotl, long double, LDP);

defpow(powf, float, SP);
defpow(pow, double, DP);
defpow(powl, long double, LDP);
