#pragma once
#ifndef __arm__
typedef unsigned long size_t;
#else
typedef unsigned int size_t;
#endif
#define wchar_t int
#define NULL nullptr
#define EXIT_FAILURE -1
#define EXIT_SUCCESS 0
#define RAND_MAX 0x7FFFFFFF
#define MB_CUR_MAX 4
int atoi(const char*);
long atol(const char*);

void *malloc(size_t size);
void *calloc(size_t nitems, size_t size);
void free(void* ptr);
void *realloc(void* ptr, size_t size);

void abort();
#define atexit(x) (-1)
void exit(int status);
#define getenv(a) (NULL)
#define system(a) (-1)

void *bsearch(const void* key, const void* base, size_t nitems, size_t size, int(*compar)(const void*, const void*));
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
