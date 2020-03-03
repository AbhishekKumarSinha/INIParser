#include "iniparser.h"

INI_Parser::INI_Parser()
{
    cout << "C-tor!" << endl;
}

INI_Parser::~INI_Parser()
{
    cout << "D-tor!" << endl;
}

void INI_Parser::read_ini_file(string file_name)
{
    file_handle.open(file_name, ios::in);

    if(file_handle.is_open()) //OK, File Successfully Opened
    {
        string line, current;

        regex section_test("\\[(.*?)\\]");
        regex value_test("(\\w+)=([^\\+]+(?!\\+{3}))");

        while (getline(file_handle, line))
        {
            if (line.length() > 0)
            {
                smatch match;
                if (regex_search(line, match, section_test))
                {
                    // any key-value pairs from here to be attributed 
                    // to this new name
                    current = match[1];
                }
                else if (regex_search(line, match, value_test))
                {
                    // set this as a key value pair on the current name
                    config[current][match[1]] = match[2];
                }
            }
        }

    }
    else
    {
        cout << "Unable to Open File :( " << endl;
    }
}

int INI_Parser::get_int_value(string section, string key)
{   size_t sz;
    return stoi(config.at(section).at(key),&sz);
}

string INI_Parser::get_string_value(string section, string key)
{
    return config.at(section).at(key);
}
