///////////////////////////////////////////////////
// Module: INI Parser
// Purpose : Header File for INI Parser Class.
//
// Author : Abhishek Sinha
///////////////////////////////////////////////////

#ifndef __INI_PARSER_H__
#define __INI_PARSER_H__

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <map>

using namespace std;

class INI_Parser
{
public:
    INI_Parser();// {cout << "Test-1" << endl;}
    void read_ini_file(string file_name);
    string get_string_value(string section, string key);
    int get_int_value(string section, string key);
    ~INI_Parser();// {cout << "Test-1" << endl;}

private:
    map<std::string, std::map<std::string, std::string> > config;
    fstream file_handle;

};

#endif //INI_PARSER_H