//
// Created by Adam Szerszeń on 14.03.2018.
//

#include "Number.h"

Number::Number(string sign, int number, int value) :
        romanSign(sign), numberValue(value), asciiNumber(number) {
}

string Number::RomanSign() const {
    return romanSign;
}

int Number::AsciiNumber() const {
    return asciiNumber;
}

int Number::NumberValue() const {
    return numberValue;
}
