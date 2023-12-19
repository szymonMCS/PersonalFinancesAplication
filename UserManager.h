#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>

#include "User.h"
#include "SupportingMethods.h"
#include "UsersFile.h"

class UserManager{
    int loggedInUserId;
    std::vector <User> users;
    UsersFile usersFile;

    User enterNewUserData();
    int setNewUserId();
    bool doesLoginExists(std::string login);


public:
    UserManager(std::string usersFileName) : usersFile(usersFileName) {
        loggedInUserId = 0;
        users = usersFile.readUsersFromFile();
    };
    void userRegistration();
    int getLoggedInUserId();
    void userLoggingIn();
    void printAllUsers();
    void loggedInUserPasswordChange();
    void logOut();
    bool isUserLoggedIn();

};

#endif // USERMANAGER_H
