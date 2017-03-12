double tan(double);
double tanh(double);
double atan(double);
double atanh(double);
#define PI 3.141592653589793
#include <iostream>

int main() {
    double o = PI/6;

    double t1 = tan(o);
    double t2 = tanh(o);

    double i1 = atan(t1);
    double i2 = atanh(t2);

    double d1 = i1 - o;
    double d2 = i2 - o;
    std::cout << d1 << std::endl << d2 << std::endl;
    return 0;
}
