#include "PersonalFinancesAplication.h"

void PersonalFinancesAplication::userRegistration() {
    userManager.userRegistration();
}
void PersonalFinancesAplication::userLogin() {
    userManager.userLoggingIn();
    if (isUserLoggedIn()) {
        financeManager = new FinanceManager(userManager.getLoggedInUserId());
    }
}
char PersonalFinancesAplication::chooseOptionFromMainMenu() {
    system("cls");

    char choice;

    std::cout << "== PERSONAL FINANCES APLICATION ==" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "==     1. register new user     ==" << std::endl;
    std::cout << "==     2. user log in           ==" << std::endl;
    std::cout << "==     9. exit program          ==" << std::endl;

    choice = SupportingMethods::readChar();

    return choice;
}
char PersonalFinancesAplication::chooseOptionFromUserMenu() {
    system("cls");

    char choice;

    std::cout << "=========== USER MENU ===========" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "==  1. add income              ==" << std::endl;
    std::cout << "==  2. add outcome             ==" << std::endl;
    std::cout << "==  3. current month balance   ==" << std::endl;
    std::cout << "==  4. previous month balance  ==" << std::endl;
    std::cout << "==  5. any period balance      ==" << std::endl;
    std::cout << "==  6. change password         ==" << std::endl;
    std::cout << "==  7. sign out                ==" << std::endl;

    choice = SupportingMethods::readChar();

    return choice;
}
void PersonalFinancesAplication::addIncome() {
    financeManager -> addIncome();
}
void PersonalFinancesAplication::addOutcome() {
    financeManager -> addOutcome();
}
void PersonalFinancesAplication::currentMonthBalance() {
    financeManager -> currentMontBalance();
}

void PersonalFinancesAplication::previousMonthBalance() {
    financeManager -> previousMonthBalance();
}

void PersonalFinancesAplication::anyPeriodBalance() {
    financeManager -> anyPeriodBalance();
}

void PersonalFinancesAplication::userLogOut() {
    userManager.logOut();
}
void PersonalFinancesAplication::passwordChange() {
    userManager.loggedInUserPasswordChange();
}
bool PersonalFinancesAplication::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

void PersonalFinancesAplication::menu() {
    char choice;

    while(true) {
        if(!isUserLoggedIn()) {

            choice = chooseOptionFromMainMenu();

            switch(choice) {
            case '1' : userRegistration(); break;
            case '2' : userLogin();        break;
            case '9' : exit(0);            break;
            default:
                std::cout << std::endl << "Incorrect choice, try again." << std::endl << std::endl;
                system("pause");
                break;
            }
        } else {
            choice = chooseOptionFromUserMenu();

            switch(choice) {
            case '1' : addIncome();            break;
            case '2' : addOutcome();           break;
            case '3' : currentMonthBalance();  break;
            case '4' : previousMonthBalance(); break;
            case '5' : anyPeriodBalance();     break;
            case '6' : passwordChange();       break;
            case '7' : userLogOut();           break;
            default:
                std::cout << std::endl << "Incorrect choice, try again." << std::endl << std::endl;
                system("pause");
                break;
            }
        }
    }
}
