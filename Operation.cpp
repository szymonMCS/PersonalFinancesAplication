#include "Operation.h"

void Operation::setOperationId(int input){
    operationId = input;
}

void Operation::setUserId(int input){
    userId = input;
}

void Operation::setDate(int input){
    date = input;
}

void Operation::setItem(std::string input){
    item = input;
}

void Operation::setAmount(double input){
    amount = input;
}

int Operation::getOperationId(){
    return operationId;
}

int Operation::getUserId(){
    return userId;
}

int Operation::getDate(){
    return date;
}

std::string Operation::getItem(){
    return item;
}

double Operation::getAmount(){
    return amount;
}

bool Operation::compareByDate (const Operation& first, const Operation& second){
    return first.getDate() < second.getDate();
}
