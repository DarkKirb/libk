// Calculates log(2, x) with a precision of mantissaBits bits.
#include <math.h>
#include "internal.h"
#define defexp(name, type, base, prec, add) \
    type name (type x) { \
        return __exp((type)(base), x, prec) + add; \
    }

#define deflog(name, type, base, prec, add) \
    type name (type x) { \
        return __log((type)(base), x+add, prec); \
    }

defexp(expf, float, E, SP, 0);
defexp(exp, double, E, DP, 0);
defexp(expl, long double, E, LDP, 0);

defexp(exp2f, float, 2, SP, 0);
defexp(exp2, double, 2, DP, 0);
defexp(exp2l, long double, 2, LDP, 0);

defexp(expm1f, float, E, SP, -1);
defexp(expm1, double, E, DP, -1);
defexp(expm1l, long double, E, LDP, -1);

deflog(logf, float, E, SP, 0);
deflog(log, double, E, DP, 0);
deflog(logl, long double, E, LDP, 0);

deflog(log2f, float, 2, SP, 0);
deflog(log2, double, 2, DP, 0);
deflog(log2l, long double, 2, LDP, 0);

deflog(log10f, float, 10, SP, 0);
deflog(log10, double, 10, DP, 0);
deflog(log10l, long double, 10, LDP, 0);

deflog(log1pf, float, E, SP, 1);
deflog(log1p, double, E, DP, 1);
deflog(log1pl, long double, E, LDP, 1);


