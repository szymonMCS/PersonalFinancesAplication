#include "SupportingMethods.h"

std::string SupportingMethods::intToStringConversion(int number) {
    std::ostringstream ss;
    ss << number;
    std::string str = ss.str();
    return str;
}

int SupportingMethods::stringToIntConversion(std::string number) {
    int numberInt;
    std::istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double SupportingMethods::stringToDouble(std::string& input) {
    std::replace(input.begin(), input.end(), ',', '.');

    std::istringstream iss(input);
    double result;
    iss >> std::fixed >> std::setprecision(2) >> result;

    return result;
}

std::string SupportingMethods::readLine() {
    std::string input = "";
    getline(std::cin, input);
    return input;
}

char SupportingMethods::readChar() {
    std::string input = "";
    char character  = {0};

    while (true) {
        getline(std::cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        std::cout << "This is not a single character. Try again. " << std::endl;
    }
    return character;
}

int SupportingMethods::readInt() {
    std::string input = "";
    int number = 0;

    while (true) {
        getline(std::cin, input);

        std::stringstream myStream(input);
        if (myStream >> number)
            break;
        std::cout << "This is not an integer. Try again. " << std::endl;
    }
    return number;
}

bool SupportingMethods::doesHaveOnlyDigits(std::string& input) {
    std::string::iterator it = input.begin();
    while (it != input.end()) {
        if (isalpha(*it)) {
            return false;
        }
        it++;
    }
    return true;
}
