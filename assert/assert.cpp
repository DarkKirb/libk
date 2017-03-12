#include <assert.h>
#include <base.hpp>
void __assert_fail(const char* file, int line, const char* code) {
    out << "Assertion " << code << " failed in " << file << ":" << (uint64_t)((unsigned int)line) << "\n";
    panic("Assertion failed!");
}
