#include "User.h"

    void User::setUserId(int newId){
        if (newId >= 0)
            userId = newId;
    }

    void User::setLogin(std::string newLogin){
        login = newLogin;
    }

    void User::setPassword(std::string newPassword){
        password = newPassword;
    }

     void User::setName(std::string newName){
        name = newName;
    }

     void User::setSurname(std::string newSurname){
        surname = newSurname;
    }

    int User::getUserId(){
        return userId;
    }

    std::string User::getLogin(){
        return login;
    }

    std::string User::getPassword(){
        return password;
    }

    std::string User::getName(){
        return name;
    }

    std::string User::getSurname(){
        return surname;
    }
