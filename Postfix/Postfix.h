//
// Created by clay on 22-9-10.
//

#ifndef CALCULATOR_POSTFIX_H
#define CALCULATOR_POSTFIX_H

#include"../Result.h"
#include<string>
#include<vector>
#include<unordered_map>
#include<functional>
#include<memory>
// allow void expr
class Postfix
{
    static const std::string negate_x;
    static const std::unordered_map<std::string, int> prior;
    static const std::unordered_map < std::string, std::function<Result(Result, Result)>> binops;
    static const std::unordered_map < std::string, std::function<Result(Result)>>sinops;

    friend class Tool;
public:
    Postfix() = default;
    Postfix(const std::string& expression) : expr(expression), fixed(false), postfix(), result(0) { fixExpr(); }
    void assign(const std::string& expression) { *this = std::move(Postfix(expression)); }
    void calPostfix(void);
    std::string getPostfixStr(void) const ;
    Result getLastResult(void) const { return result; }
    void toPostfix(void);
private:
    void fixExpr(void);
    int getPrior(const std::string &op) const;
    int getPrior(char ch) const { return getPrior(std::string() + ch); }

    Result result;
    std::string expr;
    std::vector<std::string> postfix;
    bool fixed = false;
};

#endif //CALCULATOR_POSTFIX_H
