#include "XmlFile.h"

bool XmlFile::isFileEmpty(){

    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists) {
        std::cout << "File is empty" << std::endl;
        return true;
    }

    if (xml.FindElem()){
        std::cout << "File is not empty" << std::endl;
        return false;
    } else {
        std::cout << "File is empty" << std::endl;
        return true;
    }
}

std::string XmlFile::getFileName(){
    return FILE_NAME;
}
