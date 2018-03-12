//
// Created by owaat on 12.03.2018.
//

#ifndef NUMBERPARSER_NUMERICPARSER_H
#define NUMBERPARSER_NUMERICPARSER_H

#include <string>

using std::string;

class NumericParser {
private:
    static string roman_signs[] =
            {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
public:
    static int RomanToArab(string roman) throw();
};


#endif //NUMBERPARSER_NUMERICPARSER_H
