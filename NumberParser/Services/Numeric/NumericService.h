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
    unique_ptr<vector<unique_ptr>> availableNumbers;

    unique_ptr<Number> createNumber(string sign, int number, int value);

public:
    NumericService();
};


#endif //NUMBERPARSER_NUMERICSERVICE_H
