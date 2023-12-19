#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

class SupportingMethods{

public:
    static std::string intToStringConversion(int number);
    static int stringToIntConversion(std::string number);
    static std::string readLine();
    static std::string changeFirstLetterToCapitalRestToLowercase(std::string text);
    static char readChar();
    static std::string getNumber(std::string text, int charPos);
    static int readInt();
    static double stringToDouble(std::string& input);
};

#endif // SUPPORTINGMETHODS_H
