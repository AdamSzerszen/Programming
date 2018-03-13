//
// Created by Adam Szerszeń on 12.03.2018.
//

#ifndef NUMBERPARSER_NUMERICPARSER_H
#define NUMBERPARSER_NUMERICPARSER_H

#include <string>

using std::string;

class NumericParser {
private:
    static const string ROMAN_SIGNS[];
    static const int ROMAN_VALUES[];
    static const int AVAILABLE_ASCII[];

    static bool includeOnlyRomanSigns(string roman);

    static bool isInRomanNumberRange(int arab);

    static string parseArabToRoman(int arab);

    static bool isCorrectAscii(int currentChar, int availableAsciiCount);

    static int sumUpRomanSigns(string roman, int availableAsciiCount);

public:
    static int RomanToArab(string roman) throw();

    static string ArabToRoman(int arab) throw();
};


#endif //NUMBERPARSER_NUMERICPARSER_H
