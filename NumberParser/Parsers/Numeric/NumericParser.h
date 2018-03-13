//
// Created by Adam Szerszeń on 12.03.2018.
//

#ifndef NUMBERPARSER_NUMERICPARSER_H
#define NUMBERPARSER_NUMERICPARSER_H

#include <string>

using std::string;

class NumericParser {
private:
    static const string ROMAN_SIGNS[] =
            {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    static const int ROMAN_VALUES[] =
            {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    static const int AVAILABLE_ASCII[] =
            {73, 105, 86, 118, 88, 120, 76, 108, 77, 109, 67, 99, 68, 100};

    static bool includeOnlyRomanSigns(string roman);

    static bool isInRomanNumberRange(int arab);

    static int parseRomanToArab(string roman);

    static string parseArabToRoman(int arab);

    static bool isCorrectAscii(int currentChar, int availableAsciiCount);

    static int sumUpRomanSigns(string roman, int availableAsciiCount);

public:
    static int RomanToArab(string roman) throw();

    static string ArabToRoman(int arab) throw();
};


#endif //NUMBERPARSER_NUMERICPARSER_H
