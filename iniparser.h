///////////////////////////////////////////////////
// Module: INI Parser
// Purpose : Header File for INI Parser Class.
//
// Author : Abhishek Sinha
///////////////////////////////////////////////////

#ifndef INI_PARSER_H
#define INI_PARSER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class INI_Parser
{
public:
    INI_Parser();
    void read_ini_file(string file_name);
    string get_string_value();
    int get_int_value();
    ~INI_Parser();

private:
    map<std::string, std::map<std::string, std::string> > config;

};

#endif //INI_PARSER_H