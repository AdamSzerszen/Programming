//
// Created by Adam Szerszeń on 12.03.2018.
//

#include "NumericParser.h"

int NumericParser::RomanToArab(string roman) throw(NumericParserException) {
    unique_ptr<NumericService> service = unique_ptr<NumericService>(new NumericService);

    bool containsOnlyRomanSigns = service->ContainsOnlyRomanSigns(roman);
    if (!containsOnlyRomanSigns) {
        throw NumericParserException("Input contains not correct signs!");
    }
    int romanSignsSum = service->SumUpRomanSigns(roman);

    bool isInRomanNumberRange = service->CorrectRomanRange(romanSignsSum);
    if (!isInRomanNumberRange) {
        throw NumericParserException("Input out of range!");
    }

    string correctRoman = service->ParseArabToRoman(romanSignsSum);
    if (roman.compare(correctRoman) != 0) {
        throw NumericParserException("Input not in correct roman order!");
    }

    return romanSignsSum;
}

string NumericParser::ArabToRoman(int arab) throw(NumericParserException) {
    unique_ptr<NumericService> service = unique_ptr<NumericService>(new NumericService);
    bool isInRomanNumberRange = service->CorrectRomanRange(arab);
    if (!isInRomanNumberRange) {
        throw NumericParserException("Input out of range!");
    }

    return service->ParseArabToRoman(arab);
}