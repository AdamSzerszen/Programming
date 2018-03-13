//
// Created by Adam Szerszeń on 12.03.2018.
//

#include "NumericParser.h"
#include "../../Exceptions/NumericParser/NumericParserException.h"

const string NumericParser::ROMAN_SIGNS[] =
        {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int NumericParser::ROMAN_VALUES[] =
        {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const int NumericParser::AVAILABLE_ASCII[] =
        {73, 105, 86, 118, 88, 120, 76, 108, 77, 109, 67, 99, 68, 100};

int NumericParser::RomanToArab(string roman) throw() {
    bool containsOnlyRomanSigns = includeOnlyRomanSigns(roman);
    if (!containsOnlyRomanSigns) {
        throw NumericParserException("Input contains not correct signs!");
    }
    int availableAsciiCount = sizeof(AVAILABLE_ASCII) / sizeof(int);
    int romanSignsSum = sumUpRomanSigns(roman, availableAsciiCount);

    bool isInRomanNumberRange(romanSignsSum);
    if (!isInRomanNumberRange) {
        throw NumericParserException("Input out of range!");
    }

    string correctRoman = parseArabToRoman(romanSignsSum);
    if (roman.compare(correctRoman) != 0) {
        throw NumericParserException("Input not in correct roman order!");
    }

    return romanSignsSum;
}

string NumericParser::ArabToRoman(int arab) throw() {
    bool isInRomanNumberRange(arab);
    if (!isInRomanNumberRange) {
        throw NumericParserException("Input out of range!");
    }

    return parseArabToRoman(arab);
}

bool NumericParser::includeOnlyRomanSigns(string roman) {
    bool correctChar;
    int availableAsciiCount = sizeof(AVAILABLE_ASCII) / sizeof(int);

    for (char currentChar : roman) {
        correctChar = isCorrectAscii(currentChar, availableAsciiCount);
        if (!correctChar) {
            return false;
        }
    }
    return true;
}

bool NumericParser::isCorrectAscii(int currentChar, int availableAsciiCount) {
    for (int j = 0; j < availableAsciiCount; ++j) {
        if (currentChar == AVAILABLE_ASCII[j]) {
            return true;
        }
    }
    return false;
}

bool NumericParser::isInRomanNumberRange(int arab) {
    return arab > 0 && arab < 4000;
}

string NumericParser::parseArabToRoman(int arab) {
    string roman = "";
    int availableAsciiCount = sizeof(AVAILABLE_ASCII) / sizeof(int);
    while (arab > 0) {
        for (int i = availableAsciiCount - 1; i >= 0; --i) {
            if (arab - ROMAN_VALUES[i] >= 0) {
                roman += AVAILABLE_ASCII[i];
                arab -= ROMAN_VALUES[i];
                break;
            }
        }
    }

    return roman;
}


int NumericParser::sumUpRomanSigns(string roman, int availableAsciiCount) {
    int sum = 0;
    string tempRoman = roman;

    while (tempRoman.size() > 0) {
        for (int i = availableAsciiCount - 1; i >= 0; --i) {
            string currentSign = ROMAN_SIGNS[i];
            if (tempRoman.find(currentSign) == 0) {
                sum += ROMAN_VALUES[i];
                tempRoman = tempRoman.substr((currentSign.size() - 1), tempRoman.size());
                break;
            }
        }
    }

    return sum;
}
