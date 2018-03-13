//
// Created by Adam Szerszeń on 12.03.2018.
//

#include "NumericParserException.h"

NumericParserException::NumericParserException(char const *const message) throw():
        runtime_error(message) {

}

char const *NumericParserException::what() const throw() {
    return runtime_error::what();
}
