#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
template <typename T>
char* intToChar(T i, int base) {
    T x=(T)i;
    char buf[sizeof(T)*8+1];
    buf[sizeof(T)*8]=0;
    char* ptr=buf+sizeof(T)*8-1;
    char chars[]="0123456789ABCDEF";
    do {
        *ptr=chars[x%base];
        x/=base;
        ptr--;
    } while((x) && (ptr!=buf));
    char* nbuf=(char*)malloc(strlen(ptr)+1);
    strncpy(nbuf, ptr, strlen(ptr)+1);
    return nbuf;
}
template <typename T, typename T1, typename T2>
int puti(T1 put, T2 sput, T i, bool alwaysSign, bool noSignSpace, int base) {
    int written=0;
    char *b = intToChar(i, base);
    if(i < 0) {
        put('-');
        written++;
    } else if(alwaysSign) {
        put('+');
        written++;
    } else if(noSignSpace) {
        put(' ');
        written++;
    }
    written+=sput(b);
    free(b);
    return written;
}
template <typename T1, typename T2>
int put(T1 put, T2 sput, const char* format, va_list ap) {
    int written=0;
    int i=0;
    while(format[i]) {
        if(format[i] != '%') {
            put(format[i++]);
            continue;
        }
        i++;
        int curr_char;
        bool parsingFinished=false;
        bool alwaysSign=false;
        bool noSignSpace=false;
        bool alternative=false;
        int width=0; //0=default, -1=h, -2=hh, 1=l, 2=ll, 3=j, 4=z, 5=t, 6=L
        while(!parsingFinished) {
            switch(format[i]) {
                case '+':
                    alwaysSign=true;
                    break;
                case ' ':
                    if(!alwaysSign)
                        noSignSpace=true;
                    break;
                case '#':
                    alternative=true;
                    break;
                case 'h':
                    width--;
                    break;
                case 'l':
                    width++;
                    break;
                case 'j':
                    width=3;
                    break;
                case 'z':
                    width=4;
                    break;
                case 't':
                    width=5;
                    break;
                case 'L':
                    width=6;
                    break;
                default:
                    parsingFinished=true;
                    i--;
                    break;
            }
            i++;
            if(!format[i]) {
                return written;
            }
        }

        //Parse the format argument
        switch(format[i]) {
            case '%':
                put('%');
                written++;
                break;
            case 'c': {
                int c = va_arg(ap, int);
                put(c);
                written++;
                break; }
            case 's':
                if(width==1) {
                    int* s = va_arg(ap, int*);
                    for(int i=0; s[i]; i++) {
                        put(s[i]);
                        written++;
                    }
                } else {
                    char* s = va_arg(ap, char*);
                    written+=sput(s);
                }
                break;
            case 'd':
            case 'i':
                switch(width) {
#define puti_case(i, t, b) \
                    case i : { \
                                 t p = va_arg(ap, t); \
                                 written+=puti(put, sput, p, alwaysSign, noSignSpace, b); \
                                 break; \
                             }
                    puti_case(-2, char, 10);
                    puti_case(-1, short, 10);
                    puti_case(0, int,10);
                    puti_case(1, long,10);
                    puti_case(2, long long,10);
                    puti_case(3, intmax_t,10);
                    puti_case(4, long,10);
                    puti_case(5, ptrdiff_t,10);
                }
                break;
            case 'o':
                switch(width) {
                    puti_case(-2, unsigned char, 8);
                    puti_case(-1, unsigned short, 8);
                    puti_case(0, unsigned int, 8);
                    puti_case(1, unsigned long, 8);
                    puti_case(2, unsigned long long, 8);
                    puti_case(3, uintmax_t, 8);
                    puti_case(4, size_t, 8);
                    puti_case(5, unsigned ptrdiff_t, 8);
                }
                break;
            case 'x':
            case 'X':
#define hexa_case(i, t) \
            case i: { \
                        t p = va_arg(ap, t); \
                        if(alternative) \
                            written+=sput("0x"); \
                        written+=puti(put, sput, p, alwaysSign, noSignSpace, 16); \
                        break; \
                    }
                switch(width) {
                    hexa_case(-2, unsigned char);
                    hexa_case(-1, unsigned short);
                    hexa_case(0, unsigned int);
                    hexa_case(1, unsigned long);
                    hexa_case(2, unsigned long long);
                    hexa_case(3, uintmax_t);
                    hexa_case(4, size_t);
                    hexa_case(5, unsigned ptrdiff_t);
                }
                break;
            case 'u':
                switch(width) {
                    puti_case(-2, unsigned char, 10);
                    puti_case(-1, unsigned short, 10);
                    puti_case(0, unsigned int, 10);
                    puti_case(1, unsigned long, 10);
                    puti_case(2, unsigned long long, 10);
                    puti_case(3, uintmax_t, 10);
                    puti_case(4, size_t, 10);
                    puti_case(5, unsigned ptrdiff_t, 10);
                }
                break;
            case 'n':
#define writen_case(i, t) \
            case i: { \
                        t *p = va_arg(ap, t*);\
                        *p=(t)written; \
                        break; \
                    }
                switch(width) {
                    writen_case(-2, char);
                    writen_case(-1, short);
                    writen_case(0, int);
                    writen_case(1, long);
                    writen_case(2, long long);
                    writen_case(3, intmax_t);
                    writen_case(4, long);
                    writen_case(5, ptrdiff_t);
                }
                break;
            default:
                put('%');
                put(format[i]);
                written+=2;
                break;
        }
        i++;
    }
    return written;
}
int vprintf(const char* format, va_list ap) {
    int written=put([](int x) -> int {
                return putchar(x);
            },
            [](const char* s) -> int {
                return puts(s); 
            }, format, ap);
    return written;
}
int printf(const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    int w = vprintf(format,ap);
    va_end(ap);
    return w;
}
int vfprintf(FILE *stream, const char* format, va_list ap) {
    int written = put([stream](int x) -> int { 
                return putc(x, stream);
            },
            [stream](const char* s) -> int {
                int i=0;
                while(s[i])
                    putc(s[i++], stream);
                return i-1;
            }, format, ap);
    return written;
}
int fprintf(FILE *stream, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    int v = vfprintf(stream, format, ap);
    va_end(ap);
    return v;
}
int vsprintf(char* buffer, const char* format, va_list ap) {
    int written = put([&buffer](int x) -> int {
                *buffer = x;
                buffer++;
                return x;
            },
            [&buffer](const char * s) -> int {
                int i=0;
                while(s[i]) {
                    *(buffer++) = s[i++];
                }
                return i-1;
            }, format, ap);
    *buffer=0;
    return written;
}
int sprintf(char* buffer, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    int v = vsprintf(buffer, format, ap);
    va_end(ap);
    return v;
}
int vsnprintf(char* buffer, int bufsz, const char * format, va_list ap) {
    char* endbuf=buffer+bufsz;
    int mw=0;
    int written = put([&mw, &buffer, endbuf](int x) -> int {
                if(buffer == endbuf) {
                    mw--;
                    return 0;
                }
                *(buffer++) = x;
                return x;
            },
            [&buffer, endbuf](const char* s) -> int {
                int i=0;
                while(s[i]) {
                    if(buffer == endbuf) {
                        i++;
                        break;
                    }
                    *(buffer++) = s[i++];
                }
                return i - 1;
            }, format, ap);
    if(buffer==endbuf)
        buffer--;
    *buffer=0;
    return written+mw;
}
int snprintf(char* buffer, int bufsz, const char * format, ...) {
    va_list ap;
    va_start(ap, format);
    int v = vsnprintf(buffer, bufsz, format, ap);
    va_end(ap);
    return v;
}
