//
// Created by Adam Szerszeń on 14.03.2018.
//

#include "Number.h"

Number::Number(string sign, int value) :
        romanSign(sign), numberValue(value) {
}

string Number::RomanSign() const {
    return romanSign;
}

int Number::NumberValue() const {
    return numberValue;
}
