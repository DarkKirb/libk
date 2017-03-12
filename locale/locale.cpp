#include <locale.h>
lconv c_locale = {
    ".",
    ",",
    "3",
    "CUR ",
    "¤",
    ".",
    ",",
    "3",
    "+",
    "-",
    2,
    8,
    0,
    1,
    0,
    0,
    0,
    0
};

char *setlocale(int category, const char *locale) {
    return "C";
}
lconv *localeconv(void) {
    return &c_locale;
}
