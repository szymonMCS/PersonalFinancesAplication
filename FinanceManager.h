#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Operation.h"
#include "SupportingMethods.h"
#include "DatesSupportingMethods.h"
#include "FinancesFile.h"

class FinanceManager {
    const int LOGGED_IN_USER_ID;
    std::vector <Operation> incomes;
    std::vector <Operation> outcomes;
    FinancesFile financesFile;

    void sumBalanceFromPeriod(int startDate, int endDate);
    Operation setOperationData(int date, int newId);
    double displaySortedVector(std::vector <Operation> input);
    void balance(std::string startDate, std::string endDate);

public:
    FinanceManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = financesFile.loadLoggedInUserIncomes(LOGGED_IN_USER_ID);
        outcomes = financesFile.loadLoggedInUserOutcomes(LOGGED_IN_USER_ID);
    }
    void addIncome();
    void addOutcome();
    void anyPeriodBalance();
    void currentMontBalance();
    void previousMonthBalance();
};

#endif // FINANCEMANAGER_H
