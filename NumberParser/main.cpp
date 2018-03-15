#include <iostream>
#include "Parsers/Numeric/NumericParser.h"

using std::string;
using std::cout;
using std::endl;

int main() {
    string myNumber = "MCMXCIX";
    int number = NumericParser::RomanToArab(myNumber);
    cout << "Roman: " << myNumber << " Arabic: " << number << endl;
    string parsedAgain = NumericParser::ArabToRoman(number);
    cout << "Arabic: " << number << " Roman: " << parsedAgain << endl;

    try {
        int number = NumericParser::RomanToArab("abc");
    } catch (NumericParserException ex) {
        cout << ex.what() << endl;
    }

    try {
        int number = NumericParser::RomanToArab("MMMMMMMMMMM");
    } catch (NumericParserException ex) {
        cout << ex.what() << endl;
    }

    try {
        int number = NumericParser::RomanToArab("MXMX");
    } catch (NumericParserException ex) {
        cout << ex.what() << endl;
    }

    return 0;
}