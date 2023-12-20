#ifndef FINANCESFILE_H
#define FINANCESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Markup.h"

#include "Operation.h"
#include "SupportingMethods.h"

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

class FinancesFile {
        OperationNames namesForFiles(const std::string& filename);
        std::vector <Operation> loadOperationsFromFile(std::vector <Operation>& input, const std::string& filename, int loggedInUserId, const Operation& operation);
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

    template<typename T>
    int getNewOperationIdFromVECTOR(const std::vector <T>& operations);



};


#endif // FINANCESFILE_H