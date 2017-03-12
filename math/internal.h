#pragma once
template <typename T>
T binaryLog(T x, int mantissaBits) {
    T y = 0;
    T b = 0.5;
    while(x < 1) {
        x *= 2;
        y -= 1;
    }
    while(x >= 2) {
        x /= 2;
        y += 1;
    }
    for(int i=0;i < mantissaBits;i++) {
        x*=x;
        if(x>=2) {
            x/=2.0;
            y+=b;
        }
        b/=2;
    }
    return y;
}

template <typename T>
T __abs(T n) {
    if (n < 0)
        return -n;
    return n;
}
template <typename T>
T __remainder(T x, T y) {
    T temp = x / y;
    intmax_t n = 0;
    n = (intmax_t)(temp);
    if(temp < 0)
        n -= 1;
    return x - n * y;
}
template <typename T>
T __mod(T x, T y) {
    T result = __remainder(__abs(x), y = __abs(y));
    if (result < 0)
        result += y;
    if (x < 0)
        return -result;
    return result;
}

#define SP 24
#define DP 53
#define LDP 113
#define E 2.71828182845904523536
template <typename T>
T __log(T n, T x, int precision) {
    if(n != 2)
        return binaryLog(x,precision) / binaryLog(n,precision);
    return binaryLog(x,precision);
}
template <typename T>
T __exp(T n, T x, int precision) {
    if(n==E) {
        T sum = 1.0;
        for (int i = precision; i > 0; --i)
            sum = 1 + x * sum / i;
        return sum;
    }
    return __exp((T)E, x * __log((T)E, n, precision), precision);
}

