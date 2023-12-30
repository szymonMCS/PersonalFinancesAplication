#include "Operation.h"

void Operation::setOperationId(int input) {
    operationId = input;
}

void Operation::setUserId(int input) {
    userId = input;
}

void Operation::setDate(int input) {
    date = input;
}

void Operation::setItem(std::string input) {
    item = input;
}

void Operation::setAmount(double input) {
    amount = input;
}

int Operation::getOperationId() const {
    return operationId;
}

int Operation::getUserId() const {
    return userId;
}

int Operation::getDate() const {
    return date;
}

std::string Operation::getItem() const {
    return item;
}

double Operation::getAmount() const {
    return amount;
}

bool Operation::compareByDate (const Operation& first, const Operation& second) {
    return first.getDate() < second.getDate();
}
