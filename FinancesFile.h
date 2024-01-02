#ifndef FINANCESFILE_H
#define FINANCESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Markup.h"

#include "XmlFile.h"
#include "Operation.h"
#include "SupportingMethods.h"
#include "DatesSupportingMethods.h"

struct OperationNames {
        std::string objectName;
        std::string mainFolderName;
        std::string subFolderName;
        std::string idContainerName;
        std::string userIdContainerName;
        std::string dateContainerName;
        std::string itemContainerName;
        std::string amountContainerName;
};

class FinancesFile{
        OperationNames namesForFiles(const std::string& filename);
        void loadOperationsFromFile(std::vector <Operation>& input, const std::string& filename, int loggedInUserId, Operation operation);
public:
    int lastIncomeId;
    int lastOutcomeId;

    FinancesFile(){
        lastIncomeId = getLastOperationIdFromXML("incomes.xml");
        lastOutcomeId = getLastOperationIdFromXML("outcomes.xml");
    }

    std::vector<Operation> loadLoggedInUserIncomes(int loggedInUserId);
    std::vector<Operation> loadLoggedInUserOutcomes(int loggedInUserId);
    void addOperationToFile(Operation input, const std::string& filename);
    int getLastOperationIdFromXML(const std::string& filename);
    int getLastIncomeId();
    int getLastOutcomeId();
    std::vector<Operation> getOperationsFromPeriod(const std::string& filename, std::string startDate, std::string endDate, int loggedInUserId);
};

#endif // FINANCESFILE_H
