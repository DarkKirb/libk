#pragma once
#include <stdint.h>
#define NULL 0
#ifndef __arm__
#define __PTRDIFF_TYPE__ long
#else
#define __PTRDIFF_TYPE__ int
#endif
typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef long long max_align_t;
#define offsetof(st, m) __builtin_offsetof(st, m)
