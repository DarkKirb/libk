#!/usr/bin/env python3

import csv
import binascii
fout = open("ctype/unicode.h", "w");
fout.write("// Created by generateUnicodeHeader.py\n")
fout.write("#include <ctype.h>\n")
fout.write("unicodeChar table[] = {\n")
fin = open("unicode.csv", newline='')
unicodeReader=csv.reader(fin, delimiter=";")
types={"Lu":"UPPERCASE", "Ll":"LOWERCASE", "Lt":"TITLECASE", "Mn":"NON_SPACING_MARK", "Mc":"SPACING_COMBINING_MARK", "Me":"ENCLOSING_MARK", "Nd":"DECIMAL_DIGIT", "Nl":"LETTER_NUMBER", "No":"OTHER_NUMBER", "Zs":"SPACE", "Zl":"LINE_SEPARATOR", "Zp":"PARAGRAPH_SEPARATOR", "Cc":"CONTROL", "Cf":"FORMAT", "Cs":"SURROGATE", "Co":"PRIVATE_USE", "Lm":"LETTER_MODIFIER", "Lo":"LETTER_OTHER", "Pc":"PUNCTUATION_CONNECTOR", "Pd":"PUNCTUATION_DASH", "Ps":"PUNCTUATION_OPEN", "Pe":"PUNCTUATION_CLOSE", "Pi":"PUNCTUATION_INITIAL", "Pf":"PUNCTUATION_FINAL", "Po":"PUNCTUATION_OTHER", "Sm":"SYMBOL_MATH", "Sc":"SYMBOL_CURRENCY", "Sk":"SYMBOL_MODIFIER", "So":"SYMBOL_OTHER"}
total=0
for row in unicodeReader:
    total+=1
    if len(row[0]) % 2:
        row[0] = "0" + row[0]
    number=int.from_bytes(binascii.unhexlify(row[0]), byteorder="big")
    t=types[row[2]]
    uppercase, lowercase=0,0
    if row[12] != "":
        if len(row[12]) % 2:
                row[12] = "0" + row[12]
        uppercase = int.from_bytes(binascii.unhexlify(row[12]), byteorder="big")
    if row[13] != "":
        if len(row[13]) % 2:
                row[13] = "0" + row[13]
        lowercase = int.from_bytes(binascii.unhexlify(row[13]), byteorder="big")

    fout.write("{ " + str(number) + ", CC::" + t + ", " + str(uppercase) + ", " + str(lowercase) + "}, // "+(chr(number) if (t != "SURROGATE") and (t != "CONTROL") and (t != "FORMAT") else "")+"\n")

fout.write("{0, CC::UPPERCASE, 0, 0}};\n")
fout.write("#define TABLE_ENTRIES " + str(total) + "\n")
fin.close()
fout.close()
