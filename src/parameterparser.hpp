#pragma once

#include <functional>
#include <string>
#include <string_view>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace GHeadset::utils
{
    class ParameterParser
    {
        public:
            ParameterParser(std::string programName, std::function<void(const std::string)> &&defaultProcessor, bool registerHelp = true);

            inline void registerSwitch(std::string name, const std::function<void(void)> &processor)
            {
                registerSwitch(name, "", "", processor);
            }
            inline void registerSwitch(std::string name, std::string description, const std::function<void(void)> &processor)
            {
                registerSwitch(name, description, "", processor);
            }
            inline void registerSwitch(std::string name, std::string description, std::string category, const std::function<void(void)> &processor)
            {
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                switchMap.emplace(name, processor);
                if (!description.empty()) descriptionMap.emplace(name, description);
                if (!category.empty()) categoryMap.emplace(name, category);
            }   
            inline void registerParameter(std::string name, const std::function<void(std::string)> &processor) 
            { 
                registerParameter(name, "", "", processor); 
            }
            inline void registerParameter(std::string name, std::string description, const std::function<void(std::string)> &processor) 
            { 
                registerParameter(name, description, "", processor); 
            }
            inline void registerParameter(std::string name, std::string description, std::string category, const std::function<void(std::string)> &processor)
            {
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                parameterMap.emplace(name, processor);
                if (!description.empty()) descriptionMap.emplace(name, description);
                if (!category.empty()) categoryMap.emplace(name, category);
            }
            void parse(const std::vector<std::string> &arguments);
            void generateHelp(std::ostream &stream);
            bool helpRequested() const { return helpParsed; };

        private:
            std::string programName;
            std::function<void(const std::string)> defaultProcessor;
            bool helpParsed;
            std::unordered_map<std::string, std::function<void(void)>> switchMap;
            std::unordered_map<std::string, std::function<void(std::string)>> parameterMap;
            std::unordered_map<std::string, std::string> descriptionMap;
            std::unordered_map<std::string, std::string> categoryMap;
    };
}
