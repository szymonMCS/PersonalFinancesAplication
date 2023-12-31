#include "FinancesFile.h"

OperationNames FinancesFile::namesForFiles(const std::string& filename) {
    OperationNames operationNames;

    if(filename == "incomes.xml") {
        operationNames.objectName = "incomes";
        operationNames.mainFolderName = "INCOMES";
        operationNames.subFolderName = "INCOME";
        operationNames.idContainerName = "incomeId";
    } else if(filename == "outcomes.xml") {
        operationNames.objectName = "outcomes";
        operationNames.mainFolderName = "OUTCOMES";
        operationNames.subFolderName = "OUTCOME";
        operationNames.idContainerName = "outcomeId";
    }
    operationNames.userIdContainerName = "userId";
    operationNames.dateContainerName = "date";
    operationNames.itemContainerName = "item";
    operationNames.amountContainerName = "amount";

    return operationNames;
}

void FinancesFile::loadOperationsFromFile(std::vector <Operation>& input, const std::string& filename, int loggedInUserId, Operation operation) {
    OperationNames names = namesForFiles(filename);
    CMarkup xml;

    bool fileExists = xml.Load(filename.c_str());

    if (!fileExists) {
        std::cout <<"file doesn't exist" << std::endl;
        return;
    } else {
        xml.ResetPos();
        if (!xml.FindElem(names.mainFolderName)) {
            std::cout << "Error during opening file" << std::endl;
            return;
        }
        xml.IntoElem();
    }

    while (xml.FindElem(names.subFolderName)) {
        xml.IntoElem();
        if(xml.FindChildElem(names.userIdContainerName)) {
            int xmlUserId = std::stoi(xml.GetData());

            if(xmlUserId == loggedInUserId) {
                xml.ResetChildPos();
                xml.FindElem(names.idContainerName);
                operation.setOperationId(std::atoi(xml.GetData().c_str()));
                xml.FindElem(names.userIdContainerName);
                operation.setUserId(std::atoi(xml.GetData().c_str()));
                xml.FindElem(names.dateContainerName);
                operation.setDate(std::atoi(xml.GetData().c_str()));
                xml.FindElem(names.itemContainerName);
                operation.setItem(xml.GetData());
                xml.FindElem(names.amountContainerName);
                operation.setAmount(std::stod(xml.GetData().c_str()));
                xml.OutOfElem();
                input.push_back(operation);
            }
        }
    }
}

std::vector <Operation> FinancesFile::loadLoggedInUserIncomes(int loggedInUserId) {
    Operation income;
    std::string filename = "incomes.xml";

    std::vector<Operation> incomes;

    loadOperationsFromFile(incomes,filename,loggedInUserId,income);

    lastIncomeId = getLastOperationIdFromXML(filename);

    return incomes;
}

std::vector<Operation> FinancesFile::loadLoggedInUserOutcomes(int loggedInUserId) {
    Operation outcome;
    std::string filename = "outcomes.xml";

    std::vector<Operation> outcomes;

    loadOperationsFromFile(outcomes,filename,loggedInUserId,outcome);

    lastOutcomeId = getLastOperationIdFromXML(filename);

    return outcomes;
}

void FinancesFile::addOperationToFile(Operation input, const std::string& filename) {
    OperationNames names = namesForFiles(filename);
    CMarkup xml;

    bool fileExists = xml.Load(filename.c_str());

    if (!fileExists) {
        xml.AddElem(names.mainFolderName);
        xml.IntoElem();
    } else {
        xml.ResetPos();
        if (!xml.FindElem(names.mainFolderName)) {
            std::cout << "Error during opening file" << std::endl;
            return;
        }
        xml.IntoElem();
    }

    xml.AddElem(names.subFolderName);
    xml.IntoElem();

    xml.AddElem(names.idContainerName, SupportingMethods::intToStringConversion(input.getOperationId()));
    xml.AddElem(names.userIdContainerName, SupportingMethods::intToStringConversion(input.getUserId()));
    xml.AddElem(names.dateContainerName, SupportingMethods::intToStringConversion(input.getDate()));
    xml.AddElem(names.itemContainerName, input.getItem());
    xml.AddElem(names.amountContainerName, std::to_string(input.getAmount()));

    xml.Save(filename);

    if (filename == "incomes.xml") {
        lastIncomeId ++;
    } else if(filename == "outcomes.xml") {
        lastOutcomeId ++;
    }
}

int FinancesFile::getLastOperationIdFromXML(const std::string& filename) {
    OperationNames names = namesForFiles(filename);
    int lastOperationId = 0;

    CMarkup xml;

    bool fileExists = xml.Load(filename.c_str());

    if (!fileExists) {
        std::cout << filename << " file doesn't exist" << std::endl;
        return 1;
    } else {
        xml.ResetPos();
        if (!xml.FindElem(names.mainFolderName.c_str())) {
            std::cout << "Error during opening file" << std::endl;
            return 0;
        }
        xml.IntoElem();

        while(xml.FindElem(names.subFolderName.c_str())) {
            xml.IntoElem();
            xml.FindElem(names.idContainerName.c_str());
            lastOperationId = std::atoi(xml.GetData().c_str());
            xml.OutOfElem();
        }
    }
    return lastOperationId;
}

int FinancesFile::getLastIncomeId() {
    return lastIncomeId;
}

int FinancesFile::getLastOutcomeId() {
    return lastOutcomeId;
}

std::vector<Operation> FinancesFile::getOperationsFromPeriod(const std::string& filename, std::string startDate, std::string endDate, int loggedInUserId) {
    std::vector<Operation> operations;
    Operation operation;
    OperationNames names = namesForFiles(filename);

    int comparisonStart, comparisonEnd;

    comparisonStart = DatesSupportingMethods::stringDateToInt(startDate);
    comparisonEnd = DatesSupportingMethods::stringDateToInt(endDate);

    CMarkup xml;

    bool fileExists = xml.Load(filename.c_str());

    if (!fileExists) {
        xml.AddElem(names.mainFolderName);
        xml.IntoElem();
    } else {
        xml.ResetPos();
        if (!xml.FindElem(names.mainFolderName)) {
            std::cout << "Error during opening file" << std::endl;
            return operations;
        }
        xml.IntoElem();

        while (xml.FindElem(names.subFolderName)) {
            xml.IntoElem();
            xml.FindElem(names.userIdContainerName);
            int xmlUserId = std::stoi(xml.GetData().c_str());
            if(xmlUserId == loggedInUserId) {
                xml.FindElem(names.dateContainerName);
                int dateToCompare = std::stoi(xml.GetData().c_str());
                xml.ResetMainPos();
                if ((dateToCompare >= comparisonStart) && (dateToCompare <= comparisonEnd)) {
                    xml.FindElem(names.idContainerName);
                    operation.setOperationId(std::atoi(xml.GetData().c_str()));
                    xml.FindElem(names.userIdContainerName);
                    operation.setUserId(std::atoi(xml.GetData().c_str()));
                    xml.FindElem(names.dateContainerName);
                    operation.setDate(std::atoi(xml.GetData().c_str()));
                    xml.FindElem(names.itemContainerName);
                    operation.setItem(xml.GetData());
                    xml.FindElem(names.amountContainerName);
                    operation.setAmount(std::stod(xml.GetData().c_str()));
                    operations.push_back(operation);
                }
            }
            xml.OutOfElem();
        }
        xml.OutOfElem();
    }
    return operations;
}
