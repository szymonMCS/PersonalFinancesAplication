#include "FinanceManager.h"

void FinanceManager::addIncome() {
    Operation income;

    int newIncomeId = financesFile.getLastIncomeId() + 1;

    std::cout << "Add Income with todays date    - press '1' " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Add Income with different date - press '2' " << std::endl;

    char choice;

    choice = SupportingMethods::readChar();

    switch(choice) {
    case '1' :
        income = setOperationData(DatesSupportingMethods::getCurrentDate(), newIncomeId);
        break;
    case '2' :
        income = setOperationData(DatesSupportingMethods::getDifferentDate(), newIncomeId);
        break;
    default  :
        std::cout << "Invalid choice" << std::endl;
    }

    financesFile.addOperationToFile(income, "incomes.xml");

    std::cout << "Income has been added succesfully... " << std::endl;
    system("pause");
}

void FinanceManager::addOutcome() {
    Operation outcome;

    int newOutcomeId = financesFile.getLastOutcomeId() + 1;

    std::cout << "Add Outcome with todays date    - press '1' " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Add Outcome with different date - press '2' " << std::endl;

    char choice;

    choice = SupportingMethods::readChar();

    switch(choice) {
    case '1' :
        outcome = setOperationData(DatesSupportingMethods::getCurrentDate(), newOutcomeId);
        break;
    case '2' :
        outcome = setOperationData(DatesSupportingMethods::getDifferentDate(), newOutcomeId);
        break;
    default  :
        std::cout << "Invalid choice" << std::endl;
    }

    financesFile.addOperationToFile(outcome, "outcomes.xml");

    std::cout << "Outcome has been added succesfully... " << std::endl;
    system("pause");
}

Operation FinanceManager::setOperationData(int date, int newId) {
    Operation operation;

    operation.setOperationId(newId);
    operation.setUserId(LOGGED_IN_USER_ID);
    operation.setDate(date);

    std::cout << "Enter item: ";
    operation.setItem(SupportingMethods::readLine());

    std::string amount;

    do {
        std::cout << "Enter amount: ";
        amount = SupportingMethods::readLine();

        if (!SupportingMethods::doesHaveOnlyDigits(amount)) {
            std::cout << "It is not number, try again" << std::endl;
        }

    } while(!SupportingMethods::doesHaveOnlyDigits(amount));

    operation.setAmount(SupportingMethods::stringToDouble(amount));

    return operation;
}

void FinanceManager::anyPeriodBalance(){
    std::vector <Operation> balanceIncomes;
    std::vector <Operation> balanceOutcomes;

    std::string startDate = "";
    std::cout << "Enter start date of expenses comparison in yyyy-mm-dd format" << std::endl;
    startDate = SupportingMethods::readLine();
    std::string endDate = "";
    std::cout << "Enter end date of expenses comparison in yyyy-mm-dd format" << std::endl;
    endDate = SupportingMethods::readLine();


    balanceIncomes = financesFile.getOperationsFromPeriod("incomes.xml", startDate, endDate, LOGGED_IN_USER_ID);
    balanceOutcomes = financesFile.getOperationsFromPeriod("outcomes.xml", startDate, endDate, LOGGED_IN_USER_ID);

    system("cls");
    std::cout << "== Incomes == " << std::endl << std::endl;
    double incomesSum = displaySortedVector(balanceIncomes);
    std::cout << std::endl << std::endl << "== Outcomes == " << std::endl << std::endl;
    double outcomesSum = displaySortedVector(balanceOutcomes);

    std::cout << std::endl << "Incomes sum = " << incomesSum << std::endl;
    std::cout << "Outcomes sum = " << outcomesSum << std::endl << std::endl;

    double balance = incomesSum - outcomesSum;

    if (incomesSum < outcomesSum) {
        std::cout << "Balance: -" << -balance << std::endl;
    } else {
        std::cout << "Balance: " << balance << std::endl;
    }

    system("pause");
}

double FinanceManager::displaySortedVector (std::vector <Operation> input){
    double sum = 0.00;
    std::sort(input.begin(), input.end(), Operation::compareByDate);

    for (auto operation : input) {
        std::cout << "Date: " << DatesSupportingMethods::intDateToString(operation.getDate()) << ", "
                  << "Item: " << operation.getItem() << ", "
                  << "Amount: " << operation.getAmount() << std::endl;
                  sum += operation.getAmount();
    }
    return sum;
}
