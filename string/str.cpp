#include <string.h>
char *strcat(char *dest, const char* src) {
    int start=0;
    int i=0;
    while(dest[start++]);
    while(src[i]) {
        dest[start+i]=src[i++];
    }
    dest[start+i]=src[i];
    return dest;
}
char *strncat(char *dest, const char* src, size_t n) {
    int start=0;
    int i=0;
    while(dest[start++]);
    while((src[i]) && (i < n)) {
        dest[start+i]=src[i++];
    }
    if(i!=n)
        dest[start+i]=0;
    return dest;
}
char *strchr(const char *str, int c) {
    return (char*)memchr(str, c, strlen(str));
}
int strcmp(const char *s1, const char *s2) {
    size_t len1 = strlen(s1), len2=strlen(s2);
    if(len1!=len2)
        return len1-len2;
    return memcmp(s1, s2, len1);
}
#define MIN(x,y) ((x) < (y) ? (x) : (y))
int strncmp(const char *s1, const char *s2, size_t len) {
    size_t len1 = strlen(s1), len2=strlen(s2);
    if((len1 <= len) && (len1 != len2))
        return len1 - len2;
    return memcmp(s1, s2, MIN(len, len2));
}
char *strcpy(char *dest, const char *src) {
    return (char*)memmove(dest, src, strlen(src));
}
char *strncpy(char *dest, const char *src, size_t n) {
    return (char*)memmove(dest, src, MIN(strlen(src),n));
}
size_t strcspn(const char *str1, const char* str2) {
    size_t length=0;
    for(int i=0; str1[i]; i++) {
        for(int j=0; str2[j]; j++) {
            if(str1[i] == str2[j])
                return length;
        }
        length++;
    }
    return length;
}
size_t strlen(const char *str) {
    size_t len=0;
    while(str[len])
        len++;
}
char *strpbrk(const char *str1, const char *str2) {
    for(int i=0; str1[i]; i++) {
        for(int j=0; str2[j]; j++) {
            if(str1[i] == str2[j])
                return (char*)(str1+i);
        }
    }
    return NULL;
}
size_t strspn(const char *str1, const char *str2) {
    size_t len=0;
    for(int i=0; str1[i]; i++) {
        for(int j=0; str2[j]; j++) {
            if(str1[i] != str2[j])
                return len;
        }
        len++;
    }
    return len;
}

