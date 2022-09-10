//
// Created by clay on 22-9-10.
//

#ifndef CALCULATOR_TOOL_H
#define CALCULATOR_TOOL_H

#include<string>
class Tool
{
public:
    static bool isStrNum(const std::string& s) {
        return s.at(0) <= '9'
               && s.at(0) >= '0'
               || s.at(0) == '.';
    }

};

#endif //CALCULATOR_TOOL_H
