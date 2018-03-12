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

    //TODO: finish this method
    return 0;
}

string NumericParser::parseArabToRoman(int arab) {
    return std::__cxx11::string();
}

string NumericParser::ArabToRoman(int arab) {
    return std::__cxx11::string();
}
