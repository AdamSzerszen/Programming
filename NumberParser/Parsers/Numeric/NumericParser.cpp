//
// Created by Adam Szerszeń on 12.03.2018.
//

#include "NumericParser.h"
#include "../../Exceptions/NumericParser/NumericParserException.h"

int NumericParser::RomanToArab(string roman) {

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

int NumericParser::parseRomanToArab(string roman) {
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

string NumericParser::ArabToRoman(int arab) {
    bool isInRomanNumberRange(arab);
    if (!isInRomanNumberRange) {
        throw NumericParserException("Input out of range!");
    }

    return parseArabToRoman(arab);
}

int NumericParser::sumUpRomanSigns(string roman, int availableAsciiCount) {
    int sum = 0;

    while (roman.size() > 0) {
        for (int i = availableAsciiCount - 1; i >= 0; --i) {
            if (roman.find(AVAILABLE_ASCII[i]) == 0) {
                sum += ROMAN_VALUES[i];
                roman.erase(AVAILABLE_ASCII[i]);
                break;
            }
        }
    }

    return sum;
}
