//
// Created by clay on 22-9-10.
//

#include "Calculator.h"

void Calculator::calExpr(const std::string& expr)
{
    postfix.assign(expr);
    postfix.toPostfix();
    postfix.calPostfix();
    result = postfix.getLastResult();
    result.resToString();
    resStr = result.getResStr();
}
