#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

class Operation{

    int operationId;
    int userId;
    int date;
    std::string item;
    double amount;

public:
    Operation(int operationId = 0, int userId = 0, int date = 0, std::string item = "", double amount = 0.0){
        this -> operationId = operationId;
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;
    }

    void setOperationId(int input);
    void setUserId(int input);
    void setDate(int input);
    void setItem(std::string input);
    void setAmount(double input);
    int getOperationId();
    int getUserId();
    int getDate();
    std::string getItem();
    double getAmount();
    static bool compareByDate(const Operation& first, const Operation& second);

};
#endif // OPERATION_H
