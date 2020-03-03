#include <iostream>
#include "iniparser.h"

//g++ command to test
// g++ test.cpp ../iniparser.cpp -o test -I ../ -std=c++1z

int main()
{
    INI_Parser *obj = new INI_Parser();
    obj->read_ini_file("settings.ini");
    cout << obj->get_string_value("section", "key2") << endl;
    cout << obj->get_int_value("section", "key3") << endl;
    delete obj;
    return 0;
}