#pragma once

#include <string>
#include <vector>
#include <map>

class ConfigureManager
{
public:
    static ConfigureManager* Instance();

    static bool readFile(const std::string configureFileName);

    static bool readBool(const std::string &variableName, const bool defaultVal, bool alertIfError = true);
    static int readInt(const std::string& variableName, const int defaultVal, bool alertIfError = true);
    static std::string readString(const std::string & variableName, const  std::string & defaultVal, bool alertIfError = true);
    static std::vector<std::string> readStringList(const std::string & variableName, const char splitChar, bool alertIfError = true);

    static std::string getErrors();
private:
    ConfigureManager();

    bool m_readFile(const std::string & configureFileName);
    bool m_readBool(const std::string &variableName, const bool defaultVal, bool alertIfError);
    int m_readInt(const std::string& variableName, const int defaultVal, bool alertIfError);
    std::string m_readString(const std::string& variableName, const std::string & defaultVal, bool alertIfError);
    std::vector<std::string> m_readStringList(const std::string & variableName, const char splitChar, bool alertIfError);
    std::string m_getErrors();
//    void sort();
//    static bool comparator(const NameValuePair& a, const NameValuePair& b);

private:
    static ConfigureManager* m_pInstance;
    std::string errors;
    std::string className;
    std::map<std::string, std::string> data;
};
