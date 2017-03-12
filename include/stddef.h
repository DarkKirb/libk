#pragma once
#ifndef __ARM__
typedef unsigned long size_t;
typedef long ptrdiff_t;
#else
typedef unsigned int size_t;
typedef int ptrdiff_t;
#endif
