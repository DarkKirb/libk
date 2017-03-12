#include <errno.h>
#include <stddef.h>
#define FILE int
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
#define getwc(stream) fetwc(stream)

char *fgets(char *str, int count, FILE *stream);
int *fgetws(int *str, int count, FILE *stream);
