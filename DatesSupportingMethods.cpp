#include "DatesSupportingMethods.h"

int DatesSupportingMethods::getCurrentDate() {
    std::string stringDate;

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    stringDate += std::to_string(now->tm_year + 1900);
    stringDate += (now -> tm_mon + 1 < 10 ? "0" : "") + std::to_string(now -> tm_mon + 1);
    stringDate += (now -> tm_mday < 10 ? "0" : "") + std::to_string(now -> tm_mday);

    int currentDate = std::atoi(stringDate.c_str());

    return currentDate;
}

int DatesSupportingMethods::howManyDays(int year, int month) {
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int calculatedDaysAmount = daysInMonth[month - 1];

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        calculatedDaysAmount = 29;
    }
    return calculatedDaysAmount;
}

int DatesSupportingMethods::stringDateToInt(std::string& input) {
    std::string stringDate = "";

    for (char character : input) {
        if(std::isdigit(character)) {
            stringDate += character;
        }
    }
    int convertedDate = std::atoi(stringDate.c_str());

    return convertedDate;
}

bool DatesSupportingMethods::isDateValid(int dateToCheck) {

    if ((dateToCheck >= 20000101) && (dateToCheck <= getCurrentDate())) {
        return true;
    } else
        std::cout << "Date is out of the range." << std::endl;
    return false;
}

bool DatesSupportingMethods::isStringDateEnteredCorrectly(const std::string &date) {
    std::string dateWithoutLines;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        std::cout << "date is invalid, try again" << std::endl;
        return false;
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    int yearInt = std::stoi(year);
    int monthInt = std::stoi(month);
    int dayInt = std::stoi(day);

    if (!((monthInt >= 1) && (monthInt <= 12))) {
        std::cout << "Invalid value of given month." << std::endl;
        return false;
    }
    if (!(dayInt <= howManyDays(yearInt, monthInt))) {
        std::cout << "Invalid day for the given month and year." << std::endl;
        return false;
    }
    return true;
}

int DatesSupportingMethods::getDifferentDate() {
    std::string dateString;
    int date;

    do {
        std::cout << "enter date in the following format yyyy-mm-dd: " << std::endl;
        dateString = SupportingMethods::readLine();

        if (!isStringDateEnteredCorrectly(dateString)) {
            std::cout << "date has been entered incorrectly 1" << std::endl;
            continue;
        }

        date = stringDateToInt(dateString);

        if (!isDateValid(date)) {
            std::cout << "date has been entered incorrectly 2" << std::endl;
            continue;
        }
        break;
    } while(true);

    return date;
}

std::vector<int> DatesSupportingMethods::stringDateToVector(std::string inputDate) {
    std::vector <int> dateIntVector;
    char del = '-';

    std::stringstream ss(inputDate);
    std::string datePart;

    while (!ss.eof()) {
        getline(ss, datePart, del);
        dateIntVector.push_back(std::atoi(datePart.c_str()));
    }
    return dateIntVector;
}

std::string DatesSupportingMethods::intDateToString (int inputDate) {
    std::stringstream ss;
    std::string stringDate = "";
    std::string modifiedStringDate = "";

    ss << inputDate;
    stringDate = ss.str();

    for (size_t i = 0; i < stringDate.size(); i++) {
        if (i <= 3 || i == 5 || i > 6) {
            modifiedStringDate += stringDate[i];
        } else if (i == 4 || i == 6) {
            modifiedStringDate += '-';
            modifiedStringDate += stringDate[i];
        }
    }
    return modifiedStringDate;
}
