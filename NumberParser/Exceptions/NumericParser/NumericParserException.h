//
// Created by Adam Szerszeń on 12.03.2018.
//

#ifndef NUMBERPARSER_NUMERICPARSEREXCEPTION_H
#define NUMBERPARSER_NUMERICPARSEREXCEPTION_H

#include <stdexcept>

using std::runtime_error;

class NumericParserException : runtime_error {
public:
    NumericParserException(char const *const message) throw();

    virtual char const *what() const throw();
};


#endif //NUMBERPARSER_NUMERICPARSEREXCEPTION_H
