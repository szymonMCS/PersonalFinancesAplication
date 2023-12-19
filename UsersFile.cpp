#include "UsersFile.h"

void UsersFile::addUserToFile(User user){

    CMarkup xml;

    bool fileExists = xml.Load(XmlFile::getFileName().c_str());

    if (!fileExists) {
        xml.AddElem("USERS");
        xml.IntoElem();
    } else {
        xml.ResetPos();
        if (!xml.FindElem("USERS")) {
            std::cout << "Error during opening file" << std::endl;
            return;
        }
        xml.IntoElem();
    }

    xml.AddElem("USER");
    xml.IntoElem();

    xml.AddElem("userId", SupportingMethods::intToStringConversion(user.getUserId()));
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());

    xml.Save("users.xml");
}

void UsersFile::editUserPassword(int id, std::string newPassword){
    CMarkup xml;

    bool fileExists = xml.Load("users.xml");

    if(!fileExists){
        std::cout << "File doesn't exist" << std::endl;
    } else {
        xml.ResetPos();
        if (!xml.FindElem("USERS")) {
            std::cout << "Error during opening file" << std::endl;
            return;
      }
      xml.IntoElem();
    }

    while (xml.FindElem("USER")){
        xml.FindChildElem("userId");
        if (std::atoi(xml.GetChildData().c_str()) == id){
                if (xml.FindChildElem("password")){
                    xml.SetChildData(newPassword);
                    std::cout << "Password updated succesfully" << std::endl;
                    return;
                } else {
                    std::cout << "Error: Password element not found" << std::endl;
                    return;
                }
        }
        xml.OutOfElem();
    }
    xml.Save("users.xml");
}

std::vector <User> UsersFile::readUsersFromFile(){
    User user;
    std::vector <User> users;

    CMarkup xml;

    bool fileExists = xml.Load("users.xml");

    if (!fileExists) {
        xml.AddElem("USERS");
        xml.IntoElem();
    } else {
        xml.ResetPos();
        if (!xml.FindElem("USERS")) {
            std::cout << "Error during opening file" << std::endl;
            return;
        }
        xml.IntoElem();
    }

    while (xml.FindElem("USER"))
        {
            xml.IntoElem();
            xml.FindElem("userId");
            user.setUserId(std::atoi(xml.GetData().c_str()));
            xml.FindElem("login");
            user.setLogin(xml.GetData());
            xml.FindElem("password");
            user.setPassword(xml.GetData());
            xml.FindElem("name");
            user.setName(xml.GetData());
            xml.FindElem("surname");
            user.setSurname(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }
    return users;
}
