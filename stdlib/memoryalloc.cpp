#include <stdlib.h>
#include <string.h>
void *malloc(size_t size) {
    char* buf=new char[size+sizeof(size_t)];
    size_t* length=(size_t*)buf;
    *length=size;
    return buf+sizeof(size_t);
}
void *calloc(size_t nitems, size_t size) {
    char* buf=malloc(nitems*size);
    memset(buf, 0, nitems*size);
    return buf;
}
void free(void* ptr) {
    delete[] (ptr-sizeof(size_t));
}
void *realloc(void* ptr, size_t size) {
    size_t* length=(size_t*)buf;
    length--;
    void* buf=malloc(size);
    memcpy(buf, ptr, (*length < size)?*length:size);
    free(ptr);
}
