#pragma once
#define ENONE 0
#define EDOM 1
#define ERANGE 2
#define EILSEQ 3
#define EIO 4
#define ENONE_TEXT "No Error"
#define EDOM_TEXT "Parameter outside of function's domain"
#define ERANGE_TEXT "Result outside of function's range"
#define EILSEQ_TEXT "Illegal UTF-8 byte sequence"
#define EIO "I/O Error"

extern int errno_code;
#define errno() (errno_code)
