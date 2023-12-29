#ifndef PERSONALFINANCESAPLICATION_H
#define PERSONALFINANCESAPLICATION_H

#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"
#include "SupportingMethods.h"


class PersonalFinancesAplication{
    UserManager userManager;
    FinanceManager *financeManager;


    void userRegistration();
    void userLogin();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void addIncome();
    void addOutcome();
    //void currentMonthBalance();
    //void previousMonthBalance();
    void anyPeriodBalance();
    void userLogOut();
    void passwordChange();
    bool isUserLoggedIn();

public:
    PersonalFinancesAplication(std::string usersFileName) : userManager(usersFileName) {};

    void menu();
};

#endif // PERSONALFINANCESAPLICATION_H
