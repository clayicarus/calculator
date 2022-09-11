//
// Created by clay on 22-9-10.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include"Postfix/Postfix.h"
#include"Result.h"
#include<string>
class Calculator
{
public:
    void calExpr(const std::string& expr);
    std::string getLastResult() const { return resStr; }
    std::string getPostfixStr() const { return postfix.getPostfixStr(); }
private:
    Postfix postfix;
    Result result = 0;
    std::string resStr = "";
};

#endif //CALCULATOR_CALCULATOR_H
