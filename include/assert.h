#pragma once
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
#define assert(e) ((e) ? ((void)0) : __assert_fail(__FILE__, __LINE__, #e))
#endif

void __assert_fail(const char* file, int line, const char* code);
