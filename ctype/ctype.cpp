#include <ctype.h>
#include "unicode.h"
int errno_code;
unicodeChar* getEntry(int codepoint) {
    for(int i=0;i<TABLE_ENTRIES; i++) {
        if(table[i].codepoint == codepoint)
            return &(table[i]);
    }
    return nullptr;
}

int iswalpha(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return false;
    CC cat=cp->category;
    return iswlower(c) || iswalpha(c) || (cat == CC::LETTER_NUMBER) || (cat == CC::LETTER_MODIFIER) || (cat == CC::LETTER_OTHER);
}

int iswlower(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return false;
    CC cat=cp->category;
    return cat == CC::LOWERCASE;
}

int iswupper(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return false;
    CC cat=cp->category;
    return (cat == CC::UPPERCASE) || (cat == CC::TITLECASE);
}

int iswdigit(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return false;
    CC cat=cp->category;
    return (cat == CC::DECIMAL_DIGIT) || (cat == CC::LETTER_NUMBER) || (cat == CC::OTHER_NUMBER);
}

int iswcntrl(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return false;
    CC cat=cp->category;
    return (cat == CC::CONTROL) || (cat == CC::FORMAT) || (cat == CC::SURROGATE);
}

int iswspace(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return false;
    CC cat=cp->category;
    return (cat == CC::SPACING_COMBINING_MARK) || (cat == CC::SPACE) || (cat == CC::LINE_SEPARATOR) || (cat == CC::PARAGRAPH_SEPARATOR);
}

int iswprint(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return false;
    CC cat=cp->category;
    return iswalpha(c) || iswdigit(c) || (cat == CC::SPACING_COMBINING_MARK) || (cat == CC::SPACE) || (cat == CC::NON_SPACING_MARK) || (cat == CC::ENCLOSING_MARK) || (cat == CC::PRIVATE_USE) || ispunct(c);
}

int iswpunct(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return false;
    CC cat=cp->category;
    return (cat == CC::PUNCTUATION_CONNECTOR) || (cat == CC::PUNCTUATION_DASH) || (cat == CC::PUNCTUATION_OPEN) || (cat == CC::PUNCTUATION_CLOSE) || (cat == CC::PUNCTUATION_INITIAL) || (cat == CC::PUNCTUATION_FINAL) || (cat == CC::PUNCTUATION_OTHER) || (cat == CC::SYMBOL_MATH) || (cat == CC::SYMBOL_CURRENCY) || (cat == CC::SYMBOL_MODIFIER) || (cat == CC::SYMBOL_OTHER);
}

int towlower(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return c;
    if(cp->lowercase)
        return cp->lowercase;
    return c;
}
int towupper(int c) {
    auto cp = getEntry(c);
    if(!cp)
        return c;
    if(cp->uppercase)
        return cp->uppercase;
    return c;
}
