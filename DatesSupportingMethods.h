#ifndef DATESSUPPORTINGMETHODS_H
#define DATESSUPPORTINGMETHODS_H

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <conio.h>
#include <sstream>

#include "SupportingMethods.h"


class DatesSupportingMethods{

public:
    static int getCurrentDate();
    static int howManyDays(int year, int month);
    static bool isDateValid(int dateToCheck);
    static int stringDateToInt(std::string& date);
    static bool isStringDateEnteredCorrectly(const std::string& date);
    static int getDifferentDate();

};
#endif // DATESSUPPORTINGMETHODS_H
