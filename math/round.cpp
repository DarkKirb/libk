#include <math.h>

template <typename T>
T __floor(T x) {
    return (T)((intmax_t)x);
}
#define deffloor(name, type) \
    type name ( type x ) { \
        return __floor(x); \
    }
#define defceil(name, type) \
    type name ( type x ) { \
        return __floor(x)+1; \
    }
#define deftrunc(name, type) \
    type name ( type x ) { \
        if ( x < 0 ) return __floor(x) + 1; \
        return __floor(x); \
    }
#define defround(name, type1, type2) \
    type1 name ( type2 x ) { \
        if ( x < 0 ) return (type1)(__floor(x-0.5)); \
        return (type1)(__floor(x+0.5)); \
    }

deffloor(floorf, float);
deffloor(floor, double);
deffloor(floorl, long double);

defceil(ceilf, float);
defceil(ceil, double);
defceil(ceill, long double);

deftrunc(truncf, float);
deftrunc(trunc, double);
deftrunc(truncl, long double);

defround(roundf, float, float);
defround(round, double, double);
defround(roundl, long double, long double);

defround(lroundf, long, float);
defround(lround, long, double);
defround(lroundl, long, long double);

defround(llroundf, long long, float);
defround(llround, long long, double);
defround(llroundl, long long, long double);

