//
// Created by clay on 22-9-10.
//

#ifndef CALCULATOR_TOOL_H
#define CALCULATOR_TOOL_H

#include<string>
#include"Postfix.h"
class Tool
{
public:
    static bool isStrNum(const std::string& s) {
        return s.at(0) <= '9'
               && s.at(0) >= '0'
               || s.at(0) == '.';
    }

    static bool isCharNum(const char c) {
        return c <= '9'
               && c >= '0'
               || c == '.';
    }
    static bool isBracket(const char c){
        return c == '(' || c == ')';
    }
    static bool isOperator(const char c){
        return !isCharNum(c) && !isBracket(c);
    }
};

#endif //CALCULATOR_TOOL_H
