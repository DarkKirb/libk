#include <stdlib.h>
long atol(const char* str) {
    int i=0;
    int j=0;
    if((str[j] < '0') || (str[j] > '9'))
        return 0;
    do {
        i*=10;
        i+=str[j]-'0';
        j++;
    } while((str[j] >= '0') && (str[j] <= '9'));
    return i;
}
int atoi(const char* str) {
    return (int)atol(str);
}
