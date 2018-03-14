//
// Created by Adam Szerszeń on 14.03.2018.
//

#include "NumericService.h"

NumericService::NumericService() {

    string ROMAN_SIGNS[] =
            {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int ROMAN_VALUES[] =
            {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int AVAILABLE_ASCII[] =
            {73, 105, 86, 118, 88, 120, 76, 108, 77, 109, 67, 99, 68, 100};

    availableNumbers = unique_ptr<vector<unique_ptr>>(new vector<unique_ptr>);
}

unique_ptr<Number> NumericService::createNumber(string sign, int number, int value) {
    return unique_ptr<Number>(new Number(sign, number, value));
}
