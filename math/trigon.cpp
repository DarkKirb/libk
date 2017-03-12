#include <math.h>
#include "internal.h"

template <typename T>
T __sin(T x) {
    //Taylor series expansion
    //First, get x into the range [0, PI]
   int period=0;
   while(x < 0) {
        x+=PI;
        period--;
   }
   while(x >= PI) {
        x-=PI;
        period++;
   }
   if(period < 0)
       period=-period;
   period%=4; //Determines the sign
   T y = x;
   for(int i=1; i<10; i++) {
        T temp=__pow(x,2*i+1);
        temp/=__fac(2*i+1);
        if(i%2)
            temp=-temp;
        y+=temp;
   }
   if((period == 1) || (period == 3))
       y = -y;
   return y;
}
template <typename T>
T __cos(T x) {
    return __sin(x + PI/2);
}
template <typename T>
T __tan(T x) {
    int period = 0;
    while(x < -(PI/2)) {
        x+=PI;
        period--;
    }
    while(x >= PI/2) {
        x-=PI;
        period++;
    }
    if(period < 0)
        period = -period;
    period%=4;
    int zagNumbers[] = {1,2,16,272,7936,353792, 22368256, 1903757312};
//    x = (T) (x * 180.0/PI);
    T y = x;
    for(int i=1; i<8; i++) {
        T temp = zagNumbers[i]*__pow(x, 2*i+1);
        temp/=__fac(2*i+1);
        y+=temp;
    }
//    y=(T)(y * PI/180.0);
    if((period == 1) || (period == 3))
        y = -y;
    return y;
}
template <typename T>
T __arcsin(T x) {
    T y = x;
    for(int i=1; i<10; i++) {
        int exponent=2*i+1;
        T top = 1;
        T bottom = 1;
        for(int j=1; j <= i; j++) {
            top*=j*2-1;
            bottom*=j*2;
        }
        y+=(top*__pow(x, exponent))/(exponent*bottom);
    }
    return y;
}
template <typename T>
T __arccos(T x) {
    return (T)(PI/2) - __arcsin(x);
}
template <typename T>
T __arctan(T x) {
    if((x<=1) && (x >= -1)) {
        T y=x;
        for(int i=1;i<10;i++) {
            T tmp=__pow(x,2*i+1)/(2*i+1);
            if(i%2)
                y-=tmp;
            else
                y+=tmp;
        }
        return y;
    } else {
        if(x<0) {
            return -__arctan(1/x)-(T)(PI/2);
        } else {
            return -__arctan(1/x)+(T)(PI/2);
        }
    }
}

template <typename T>
T __cosh(T x, int precision) {
    return (__exp((T)E, x, precision) + __exp((T)E, -x, precision))/2;
}
template <typename T>
T __tanh(T x, int precision) {
    return __sinh(x, precision) / __cosh(x, precision);
}
template <typename T>
T __arcsinh(T x, int precision) {
    return __log((T)E, x + __exp(x*x+1, (T)0.5 , precision), precision);
}
template <typename T>
T __arccosh(T x, int precision) {
    return __log((T)E, x + __exp(x*x-1, (T)0.5, precision), precision);
}
template <typename T>
T __arctanh(T x, int precision) {
    return 0.5*__log((T)E,(1+x)/(1-x), precision);
}
template <typename T>
#define gentrig(name, type, function) \
    type name ( type x ) { \
        return function ( x ); \
    }

#define genhyp(name, type, function, prec) \
    type name ( type x ) { \
        return function ( x , prec ); \
    }

gentrig(sinf, float, __sin);
gentrig(sin, double, __sin);
gentrig(sinl, long double, __sin);

gentrig(cosf, float, __cos);
gentrig(cos, double, __cos);
gentrig(cosl, long double, __cos);

gentrig(tanf, float, __tan);
gentrig(tan, double, __tan);
gentrig(tanl, long double, __tan);

gentrig(asinf, float, __arcsin);
gentrig(asin, double, __arcsin);
gentrig(asinl, long double, __arcsin);

gentrig(acosf, float, __arccos);
gentrig(acos, double, __arccos);
gentrig(acosl, long double, __arccos);

gentrig(atanf, float, __arctan);
gentrig(atan, double, __arctan);
gentrig(atanl, long double, __arctan);

genhyp(sinhf, float, __sinh, SP);
genhyp(sinh, double, __sinh, DP);
genhyp(sinhl, long double, __sinh, LDP);

genhyp(coshf, float, __cosh, SP);
genhyp(cosh, double, __cosh, DP);
genhyp(coshl, long double, __cosh, LDP);

genhyp(tanhf, float, __tanh, SP);
genhyp(tanh, double, __tanh, DP);
genhyp(tanhl, long double, __tanh, LDP);

genhyp(asinhf, float, __arcsinh, SP);
genhyp(asinh, double, __arcsinh, DP);
genhyp(asinhl, long double, __arcsinh, LDP);

genhyp(acoshf, float, __arccosh, SP);
genhyp(acosh, double, __arccosh, DP);
genhyp(acoshl, long double, __arccosh, LDP);

genhyp(atanhf, float, __arctanh, SP);
genhyp(atanh, double, __arctanh, DP);
genhyp(atanhl, long double, __arctanh, LDP);
