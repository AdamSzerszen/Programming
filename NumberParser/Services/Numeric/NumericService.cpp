//
// Created by Adam Szerszeń on 14.03.2018.
//

#include "NumericService.h"

using std::move;

NumericService::NumericService() {
    availableNumbers = vector<unique_ptr<Number>>();
    string ROMAN_SIGNS[] =
            {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int ROMAN_VALUES[] =
            {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int availableNumbersCount = sizeof(ROMAN_VALUES) / sizeof(int);
    for (int i = 0; i < availableNumbersCount; i++) {
        auto tempNumber = unique_ptr<Number>(new Number(ROMAN_SIGNS[i], ROMAN_VALUES[i]));
        availableNumbers.push_back(move(tempNumber));
    }
}

unique_ptr<Number> NumericService::createNumber(string sign, int value) {
    return unique_ptr<Number>(new Number(sign, value));
}

bool NumericService::ContainsOnlyRomanSigns(string roman) {
    bool correctChar;
    for (char currentChar : roman) {
        correctChar = CorrectAscii(currentChar);
        if (!correctChar) {
            return false;
        }
    }
    return true;
}

bool NumericService::CorrectRomanRange(int arab) {
    return arab > 0 && arab < 4000;
}

string NumericService::ParseArabToRoman(int arab) {
    string roman = "";
    while (arab > 0) {
        for (int i = availableNumbers.size() - 1; i >= 0; --i) {
            Number tempNumber = *availableNumbers.at(i);
            if (arab - tempNumber.NumberValue() >= 0) {
                roman += tempNumber.RomanSign();
                arab -= tempNumber.NumberValue();
                break;
            }
        }
    }

    return roman;
}

bool NumericService::CorrectAscii(int currentChar) {
    int AVAILABLE_ASCII[] =
            {73, 86, 88, 76, 77, 67, 68};
    int availableAsciiCount = sizeof(AVAILABLE_ASCII) / sizeof(int);

    for (int j = 0; j < availableAsciiCount; ++j) {
        if (currentChar == AVAILABLE_ASCII[j]) {
            return true;
        }
    }
    return false;
}

int NumericService::SumUpRomanSigns(string roman) {
    int sum = 0;
    string tempRoman = roman;

    while (tempRoman.size() > 0) {
        for (int i = availableNumbers.size() - 1; i >= 0; --i) {
            Number tempNumber = *availableNumbers.at(i);
            string currentSign = tempNumber.RomanSign();
            if (tempRoman.find(currentSign) == 0) {
                sum += tempNumber.NumberValue();
                tempRoman.erase(0, currentSign.size());
                break;
            }
        }
    }

    return sum;
}