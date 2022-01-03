#include "parameterparser.hpp"

using namespace GHeadset::utils;

ParameterParser::ParameterParser(std::string programName, std::function<void(const std::string)> &&defaultProcessor, bool registerCoutHelp)
    : programName(programName)
    , defaultProcessor(defaultProcessor)
    , helpParsed(false)
{
    if (registerCoutHelp)
    {
        registerSwitch("help", [this]() { helpParsed = true; generateHelp(std::cout); });
    }
}

void ParameterParser::parse(const std::vector<std::string> &arguments)
{
    size_t argumentCount = arguments.size();
    auto SwitchMapEnd = switchMap.end();
    auto ParameterMapEnd = parameterMap.end();
    for (size_t i = 0; i < argumentCount; i++)
    {
        std::string argument = arguments[i];
        if (argument[0] == '-' && argument[1] == '-')
        {
            argument = argument.substr(2);
            std::transform(argument.begin(), argument.end(), argument.begin(), ::tolower);
            if (switchMap.find(argument) != SwitchMapEnd)
            {
                switchMap[argument]();
                continue;
            }
            else
            {
                if ((i + 1) < argumentCount)
                {
                    if (parameterMap.find(argument) != ParameterMapEnd)
                    {
                        parameterMap[argument](arguments[++i]);
                        continue;
                    }
                }
            }
        }
        else
        {
            defaultProcessor(argument);
        }
    }
}

void ParameterParser::generateHelp(std::ostream &stream)
{
    // Classification
    std::unordered_map<std::string, std::vector<std::string>> optionGroups;
    for (auto &entry : categoryMap)
    {
        if (optionGroups.find(entry.second) != optionGroups.end())
        {
            optionGroups.at(entry.second).emplace_back(entry.first);
        }
        else
        {
            optionGroups.emplace(entry.second, std::vector<std::string>{ entry.first });
        }
    }
    for (auto &entry : parameterMap)
    {
        if (categoryMap.find(entry.first) == categoryMap.end())
        {
            if (optionGroups.find("Unknown") == optionGroups.end())
            {
                optionGroups.emplace("Unknown", std::vector<std::string>{ entry.first });
            }
            else
            {
                optionGroups.at("Unknown").emplace_back(entry.first);
            }
        }
    }

    // Order
    std::vector<std::string> categories;
    for (auto &group : optionGroups)
    {
        categories.emplace_back(group.first);
        std::sort(group.second.begin(), group.second.end());
    }
    std::sort(categories.begin(), categories.end());

    // Streaming
    stream << programName << std::endl << std::endl;
    for (auto &category : categories)
    {
        stream << category << ":" << std::endl ;
        for (auto &item : optionGroups.at(category))
        {
            stream << "\t--" << item << std::endl;
            if (descriptionMap.find(item) != descriptionMap.end())
            {
                stream << "\t\t" << descriptionMap[item] << std::endl;
            }
        }
        stream << std::endl;
    }    
}
