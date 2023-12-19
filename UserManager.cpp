#include "UserManager.h"

void UserManager::userRegistration(){
    User user = enterNewUserData();

    users.push_back(user);
    usersFile.addUserToFile(user);

    std::cout << std::endl << "Account has been succesfully created" << std::endl << std::endl;
    system("pause");
}

User UserManager::enterNewUserData(){
    User user;
    user.setUserId(setNewUserId());

    do
    {
        std::cout << "Enter login: ";
        user.setLogin(SupportingMethods::readLine());
    } while (doesLoginExists(user.getLogin()) == true);

    std::cout << "Enter password: ";
    user.setPassword(SupportingMethods::readLine());

    std::cout << "Enter name: ";
    user.setName(SupportingMethods::readLine());

    std::cout << "Enter surname: ";
    user.setSurname(SupportingMethods::readLine());

    return user;
}

int UserManager::setNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::doesLoginExists(std::string login){
    for (std::string::size_type i = 0; i < users.size(); i++){
        if (users[i].getLogin() == login){

            std::cout << std::endl << "This login is already in use." << std::endl;
            return true;
        }
    }
    return false;
}

void UserManager::printAllUsers(){
    for (std::string::size_type i = 0; i < users.size(); i++){

            std::cout << users[i].getUserId() << std::endl;
            std::cout << users[i].getLogin() << std::endl;
            std::cout << users[i].getPassword() << std::endl;
            std::cout << users[i].getName() << std::endl;
            std::cout << users[i].getSurname() << std::endl;
    }
}

void UserManager::userLoggingIn(){
    User user;
    std::string login = "";
    std::string password = "";

    std::cout << std::endl << "Enter login: ";
    login = SupportingMethods::readLine();

    for (std::string::size_type i = 0; i < users.size(); i++){
        if (users[i].getLogin() == login){
            for (int attempts = 3; attempts > 0; attempts--)
            {
                std::cout << "Enter password. Attempts left: " << attempts << ": ";
                password = SupportingMethods::readLine();

                if (users[i].getPassword() == password)
                {
                    std::cout << std::endl << "You have logged in." << std::endl << std::endl;
                    loggedInUserId = users[i].getUserId();
                    return;
                }
            }
            std::cout << "You have entered wrong password 3 times." << std::endl;
            system("pause");
            return;
        }
    }
    std::cout << "User with following login doesn't exist" << std::endl << std::endl;
    system("pause");
}

void UserManager::loggedInUserPasswordChange(){
    std::string newPassword = "";
    std::cout << "Enter new password: ";
    newPassword = SupportingMethods::readLine();

    for (std::string::size_type i = 0; i < users.size(); i++){

        if (users[i].getUserId() == getLoggedInUserId()){
            users[i].setPassword(newPassword);
            std::cout << "Password has been changed." << std::endl << std::endl;
            system("pause");
        }
    }
    usersFile.editUserPassword(getLoggedInUserId(), newPassword);
}

void UserManager::logOut(){
    loggedInUserId = 0;
}

int UserManager::getLoggedInUserId(){
        return loggedInUserId;
    }

bool UserManager::isUserLoggedIn(){
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}
