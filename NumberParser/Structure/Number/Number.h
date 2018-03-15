//
// Created by Adam Szerszeń on 14.03.2018.
//

#ifndef NUMBERPARSER_NUMBER_H
#define NUMBERPARSER_NUMBER_H

#include <string>

using std::string;

class Number {
private:
    string romanSign;
    int numberValue;
public:
    Number(string sign, int value);

    string RomanSign() const;

    int NumberValue() const;
};


#endif //NUMBERPARSER_NUMBER_H
