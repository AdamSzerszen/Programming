//
// Created by Adam Szerszeń on 14.03.2018.
//

#ifndef NUMBERPARSER_NUMERICSERVICE_H
#define NUMBERPARSER_NUMERICSERVICE_H

#include <vector>
#include <memory>
#include "../../Structure/Number/Number.h"

using std::vector;
using std::unique_ptr;

class NumericService {
private:
    vector<unique_ptr<Number>> availableNumbers;

    unique_ptr<Number> createNumber(string sign, int value);

public:
    NumericService();

    bool ContainsOnlyRomanSigns(string roman);

    bool CorrectRomanRange(int arab);

    string ParseArabToRoman(int arab);

    bool CorrectAscii(int currentChar);

    int SumUpRomanSigns(string roman);
};


#endif //NUMBERPARSER_NUMERICSERVICE_H
