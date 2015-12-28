#include <configurer/include/configurer.h>

#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <iostream>

ConfigureManager* ConfigureManager::m_pInstance = nullptr;

ConfigureManager* ConfigureManager::Instance()
{
    if (!m_pInstance)
    {
        m_pInstance = new ConfigureManager();
    }
    return m_pInstance;

}

ConfigureManager::ConfigureManager()
{
    className = "ConfigureManager";
}

bool ConfigureManager::readFile(const std::string configureFileName)
{
    return Instance()->m_readFile(configureFileName);
}

bool ConfigureManager::readBool(const std::string & variableName, const bool defaultVal, bool alertIfError)
{
    return Instance()->m_readBool(variableName, defaultVal, alertIfError);
}

int ConfigureManager::readInt(const std::string &variableName, const int defaultVal, bool alertIfError)
{
    return Instance()->m_readInt(variableName, defaultVal, alertIfError);
}

std::string ConfigureManager::readString(const std::string & variableName, const  std::string & defaultVal, bool alertIfError)
{
    return Instance()->m_readString(variableName, defaultVal, alertIfError);
}

std::vector<std::string> ConfigureManager::readStringList(const std::string & variableName, const char splitChar, bool alertIfError)
{
    return Instance()->m_readStringList(variableName, splitChar, alertIfError);
}

std::vector<std::string> ConfigureManager::m_readStringList(const std::string & variableName, const char splitChar, bool alertIfError)
{
    std::vector<std::string> tokens;

    std::map<std::string, std::string>::iterator it = data.find(variableName);
    if(it == data.end())
    {
        if(alertIfError){
            std::cout << className << __func__<< "cannot find variable:" << variableName << std::endl;
        }
        return tokens;
    }
    else
    {
        return split(it->second, splitChar);
    }
}

std::string ConfigureManager::m_readString(const std::string & variableName, const  std::string & defaultVal, bool alertIfError)
{
    std::map<std::string, std::string>::iterator it = data.find(variableName);
    if(it == data.end())
    {
        if(alertIfError){
            std::cout << className << __func__<< "cannot find variable:" << variableName << "! The default value will be used:" << defaultVal << std::endl;
        }
        return defaultVal;
    }
    else
    {
        return it->second;
    }
}

int ConfigureManager::m_readInt(const std::string &variableName, const int defaultVal, bool alertIfError)
{
    std::map<std::string, std::string>::iterator it = data.find(variableName);
    if(it == data.end())
    {
        if(alertIfError){
            std::cout << className << __func__<< "cannot find variable:" << variableName << "! The default value will be used:" << defaultVal << std::endl;
        }
        return defaultVal;
    }
    else
    {
        try
        {
            return std::stoi(it->second);
        }
        catch(std::exception &e)
        {
            if(alertIfError){
                std::cout << className << __func__<<  "Exception:" << e.what() << "! The default value will be used:" << defaultVal << std::endl;
            }
            return defaultVal;
        }
    }
}

bool ConfigureManager::m_readBool(const std::string &variableName, const bool defaultVal, bool alertIfError)
{
    std::map<std::string, std::string>::iterator it = data.find(variableName);
    if(it == data.end())
    {
        if(alertIfError)
        {
            std::cout << className << __func__<< "cannot find variable:" << variableName << "! The default value will be used:" << defaultVal << std::endl;
        }
        return defaultVal;
    }
    else
    {
        return it->second.compare("true") == 0;
    }
}

bool ConfigureManager::m_readFile(const std::string & configureFileName)
{
    errors.clear();
    std::ifstream configureFile (configureFileName);
    if (configureFile.is_open())
    {
        std::string line;
        std::string name;
        std::string value;
        while (std::getline(configureFile, line))
        {
            trim(line);
            if(line.length() == 0)
                continue;
            else if(line.at(0) == '#')
                continue;
            else
            {
                std::vector<std::string> pair = split(line, '=');
                if(pair.size() < 2)
                {
                    errors += ("Bad line:" + line + "\n");
                    std::cout << "Bad line!" << line << std::endl;
                }
                else
                {
                    name = trim(pair.at(0));
                    if(pair.size() == 2)
                    {
                        value = trim(pair.at(1));
                    }
                    else
                    {
                        for(int i = 1; i < pair.size(); i++)
                        {
                            value = value + "=" + pair.at(i);
                        }
                        trim(value);
                    }
                    data[name] = value;
                }
            }
        }
        return true;
    }
    else
    {
        errors += ("File cannot be found:" + configureFileName + "\n");
        return false;
    }
}

std::string ConfigureManager::getErrors()
{
    return Instance()->m_getErrors();
}

std::string ConfigureManager::m_getErrors()
{
    return errors;
}


//bool ConfigureManager::comparator(const NameValuePair& a, const NameValuePair& b)
//{
//    return a.name.compare(b.name) < 0;
//}

//void ConfigureManager::sort()
//{
//    std::sort(data.begin(), data.end(), comparator);
//}
