#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include "Markup.h"

class XmlFile{

const std::string FILE_NAME;

protected:
    XmlFile(std::string fileName) : FILE_NAME(fileName){};
    bool isFileEmpty();
    std::string getFileName();

};

#endif // XMLFILE_H
