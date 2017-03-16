#include <stdlib.h>
#include <string.h>
#include <base.hpp>
void abort() {
    panic("abort() was called in Kernel!");
}
void exit(int status) {
    panic("exit() was called!");
}
void *bsearch(const void* key, const void* base, size_t nitems, size_t size, int(*compar)(const void*, const void*)) {
    int i=0;
    int comp=0;
    while(((comp=compar(key,base+i*size)) < 0) && (i<nitems)) {
        i++;
    }
    if(comp)
        return NULL;
    return base + i * size;
}
void partition(void *base, size_t size, int (*compar)(const void*, const void*), int lo, int hi) {
    void *pivot = malloc(size);
    memcpy(pivot, base + hi * size, size);
    int i = lo-1;
    for(int j = lo; j < hi; j++) {
        if(compar(base + j * size, pivot) <= pivot) {
            i++;
            void *temp = malloc(size);
            memcpy(temp, base + i * size, size);
            memcpy(base + i * size, base + j * size, size);
            memcpy(base + j * size, temp, size);
            free(temp);
        }
       void *temp = malloc(size);
       memcpy(temp, base + (i+1) * size, size);
       memcpy(base + (i+1) *size, base + hi * size, size);
       memcpy(base + hi * size, temp, size);
       free(temp);
    }
    free(pivot);
    return i + 1;
}
void qs(void * base, size_t size, int (*compar)(const void*, const void*), int lo, int hi) {
    if(lo < hi) {
        int p = partition(base, size, compar, lo, hi);
        quicksort(base, size, compar, lo, p-1);
        quicksort(base, size, compar, p+1, hi);
    }
}
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
    qs(base, size, compar, 1, nitems-1);
}
