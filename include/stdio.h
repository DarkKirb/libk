#include <errno.h>
#include <stddef.h>
#include <stdarg.h>
#define FILE int
#define EOF 0
#define SEEK_SET 0
#define SEEK_END 1
#define SEEK_CUR 2
#define NULL 0
FILE *fopen(const char* filename, const char *mode);
int fopen_s(FILE ** streamptr, const char *filename, const char *mode);

FILE *freopen(const char *filename, const char *mode, FILE *stream);
int freopen_s(FILE ** newstreamptr, const char *filename, const char *mode, FILE *stream);

static int fflush(FILE *stream) {return 0;}
static int fclose(FILE *stream) {return 0;}

#define BUFSIZ 4096
static void setbuf(FILE *stream, char *buffer) {}
static int setvbuf(FILE *stream, char *buffer, int mode, size_t size) {return 0;}
static int fwide(FILE *stream, int mode) {return 0;}

static size_t fread(void * buffer, size_t size, size_t count, FILE *stream) {return 0;}
static size_t fwrite(const void * buffer, size_t size, size_t count, FILE *stream) {return 0;}

int fgetc(FILE * stream);
#define getc(stream) fgetc(stream)
int fgetwc(FILE * stream);
#define getwc(stream) fgetwc(stream)

char *fgets(char *str, int count, FILE *stream);
int *fgetws(int *str, int count, FILE *stream);

int fputc(int ch, FILE* stream);
int fputwc(int ch, FILE* stream);
#define putc(ch, str) fputc(ch, str)
#define putwc(ch, str) fputwc(ch, str)

int getchar();
int getwchar();

int putchar(int);
int putwchar(int);

int puts(const char* str);

int ungetc(int);
int ungetwc(int);

int printf(const char * format, ...);
int fprintf(FILE* stream, const char * format, ...);
int sprintf(char* buffer, const char * format, ...);
int snprintf(char * buffer, int length, const char * format, ...);

int vprintf(const char * format, va_list ap);
int vfprintf(FILE* stream, const char * format, va_list ap);
int vsprintf(char* buffer, const char * format, va_list ap);
int vsnprintf(char * buffer, int length, const char * format, va_list ap);
