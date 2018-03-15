//
// Created by Adam Szerszeń on 12.03.2018.
//

#ifndef NUMBERPARSER_NUMERICPARSER_H
#define NUMBERPARSER_NUMERICPARSER_H

#include <string>
#include "../../Services/Numeric/NumericService.h"
#include "../../Exceptions/NumericParser/NumericParserException.h"

using std::string;

class NumericParser {
public:
    static int RomanToArab(string roman) throw(NumericParserException);

    static string ArabToRoman(int arab) throw(NumericParserException);
};


#endif //NUMBERPARSER_NUMERICPARSER_H
