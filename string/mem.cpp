#include <string.h>
void *memset(void* str, int c, size_t n) {
    for(size_t i=0;i<n;i++) {
        *((unsigned char*)(str+i))=c;
    }
    return str;
}
void *memcpy(void* a, const void* b, size_t n) {
    const unsigned char *src = (unsigned char*)b;
    unsigned char *dest = (unsigned char*)a;
    for(int i=0;i<n;i++)
        dest[i]=src[i];
    return dest;
}
void *memmove(void* a, const void * b, size_t n) {
    if(a > b)
        return memcpy(a, b, n);
    else {
        const unsigned char *src = (unsigned char*)b;
        unsigned char *dest = (unsigned char*)a;
        for(int i=n-1;i;--i)
            dest[i]=src[i];
        return dest;
    }
}
int memcmp(const void* str1, const void* str2, size_t n) {
    const unsigned char *a=(unsigned char*)str1, *b=(unsigned char*)str2;
    int diff=0;
    for(int i=0;(i<n) && (!diff); i++) {
        diff = (short)((unsigned short)a[i])-b[i];
    }
    return diff;
}
void *memchr(const void*str, int c, size_t n) {
    const unsigned char* s = (unsigned char*)str;
    unsigned char ch=(unsigned char)c;
    for(int i=0;i<n;i++) {
        if(s[i] == ch)
            return (void*)(s + i);
    }
    return nullptr;
}
