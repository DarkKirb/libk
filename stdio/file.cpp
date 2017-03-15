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
int fputc(int ch, FILE* stream) {
    char c=(char)ch;
    fwrite(&c, 1, 1, stream);
    return ch;
}
int fputwc(int ch, FILE* stream) {
    fwrite(&ch, 4, 1, stream);
    return ch;
}
int getc_buffer=EOF;
int getchar() {
    return getwchar();
}
int getwchar() {
    int tmp=getc_buffer;
    getc_buffer=0;
    return tmp;
}
int putchar(int i) {
    return putwchar(i);
}

int putwchar(int i) {
    out.putChar(i);
    return i;
}

int puts(const char* str) {
    out << str;
    return strlen(str);
}
int ungetc(int i) {
    return ungetwc(i);
}
int ungetwc(int i) {
    getc_buffer=i;
    return i;
}
