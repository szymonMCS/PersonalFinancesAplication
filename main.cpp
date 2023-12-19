#include <iostream>
#include "PersonalFinancesAplication.h"

using namespace std;

int main()
{
    PersonalFinancesAplication personalFinancesAplication("users.xml");
    personalFinancesAplication.menu();

    return 0;
}
