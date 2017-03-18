#pragma once

#define isalnum(c) (iswalnum(c))
#define isalpha(c) (iswalpha(c))
#define islower(c) (iswlower(c))
#define isupper(c) (iswupper(c))
#define isdigit(c) (iswdigit(c))
#define isxdigit(c) (iswxdigit(c))
#define iscntrl(c) (iswcntrl(c))
#define isgraph(c) (iswgraph(c))
#define isspace(c) (iswspace(c))
#define isblank(c) (iswblank(c))
#define isprint(c) (iswprint(c))
#define ispunct(c) (iswpunct(c))
#define tolower(c) (wtolower(c))
#define toupper(c) (wtoupper(c))
enum class CC { //Character class
    UPPERCASE,
    LOWERCASE,
    TITLECASE,
    NON_SPACING_MARK,
    SPACING_COMBINING_MARK,
    ENCLOSING_MARK,
    DECIMAL_DIGIT,
    LETTER_NUMBER,
    OTHER_NUMBER,
    SPACE,
    LINE_SEPARATOR,
    PARAGRAPH_SEPARATOR,
    CONTROL,
    FORMAT,
    SURROGATE,
    PRIVATE_USE,
    LETTER_MODIFIER,
    LETTER_OTHER,
    PUNCTUATION_CONNECTOR,
    PUNCTUATION_DASH,
    PUNCTUATION_OPEN,
    PUNCTUATION_CLOSE,
    PUNCTUATION_INITIAL,
    PUNCTUATION_FINAL,
    PUNCTUATION_OTHER,
    SYMBOL_MATH,
    SYMBOL_CURRENCY,
    SYMBOL_MODIFIER,
    SYMBOL_OTHER
};
struct unicodeChar {
    int codepoint;
    CC category;
    int uppercase;
    int lowercase;
};

#define iswalnum(c) (iswalpha(c) || iswdigit(c))
int iswalpha(int c);
int iswlower(int c);
int iswupper(int c);
int iswdigit(int c);
#define iswxdigit(c) (isdigit(c) || ((c) >= 'A') || ((c) >= 'a') || ((c) <= 'F') || ((c) <= 'f'))
int iswcntrl(int c);
#define iswgraph(c) (isprint(c) && !iswspace(c))
int iswspace(int c);
#define iswblank(c) (((c) == 0x09) || ((c) == 0x20))
int iswprint(int c);
int iswpunct(int c);
int towlower(int c);
int towupper(int c);
