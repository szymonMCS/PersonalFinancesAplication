#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Markup.h"

#include "XmlFile.h"
#include "User.h"
#include "SupportingMethods.h"

class UsersFile : public XmlFile{

public:
    UsersFile(std::string usersFileName) : XmlFile(usersFileName) {};
    void addUserToFile(User user);
    void editUserPassword(int id, std::string newPassword);
    std::vector <User> readUsersFromFile();
};

#endif // USERSFILE_H
