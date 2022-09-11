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

    static bool isNum(const char c) {
        return c <= '9'
               && c >= '0'
               || c == '.';
    }
    static bool isBracket(const char c){
        return c == '(' || c == ')';
    }
    static bool isChar(const char c){
        return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
    }
    static bool isFunc_or_var(const char c){
        // need to match num firstly.
        return isNum(c) || isChar(c) || c == '_';
    }
    static bool isOperator(const char c){
        return !isFunc_or_var(c) && !isBracket(c) && !isNum(c);
    }
};

#endif //CALCULATOR_TOOL_H
