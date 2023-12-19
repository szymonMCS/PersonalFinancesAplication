#ifndef USER_H
#define USER_H

#include <iostream>

class User{
    int userId;
    std::string login;
    std::string password;
    std::string name;
    std::string surname;

public:
    void setUserId(int input);
    void setLogin(std::string input);
    void setPassword(std::string input);
    void setName(std::string input);
    void setSurname(std::string input);

    int getUserId();
    std::string getLogin();
    std::string getPassword();
    std::string getName();
    std::string getSurname();
};

#endif // UZYTKOWNIK_H
