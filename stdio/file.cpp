#include <stdio.h>
FILE *fopen(const char* filename, const char *mode) {
    return NULL;
}
int fopen_s(FILE ** streamptr, const char* filename, const char *mode) {
    *streamptr=NULL;
    return EIO;
}
FILE *freopen(const char *filename, const char *mode, FILE *stream) {
    return NULL;
}
int fopen_s(FILE ** streamptr, const char *filename, const char* mode, FILE *stream) {
    *streamptr=NULL;
    return EIO;
}
int fgetc(FILE * stream) {
    char c;
    fread(&c, 1, 1, stream);
}
char *fgets(char *str, int count, FILE *stream) {
    fread(str, count-1, 1, stream);
    str[count-1] = 0;
}
int *fgetws(int *str, int count, FILE *stream) {
    fread(str, count-1, 4, stream);
    str[count-1] = 0;
}

