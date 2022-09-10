//
// Created by clay on 22-9-10.
//

#include "Postfix.h"
#include"Tool.h"
using namespace std;
// operator not begin with number and sign.

const std::string Postfix::ende = "$";
const std::string Postfix::negate_x = "~";
const std::unordered_map<std::string, int> Postfix::prior = {
        {negate_x, 3},
        {"*", 2}, {"/", 2},
        {"+", 1}, {"-", 1},
        {"(", 0}
};
const std::unordered_map < std::string, std::function<Result(Result, Result)>>Postfix::binops = {
        {"+", std::plus<Result>()}, {"-", std::minus<Result>()},
        {"*", std::multiplies<Result>()}, {"/", std::divides<Result>()},
};
const std::unordered_map < std::string, std::function<Result(Result)>>Postfix::sinops = {
        {negate_x, std::negate<Result>()},
};

void Postfix::fixExpr(void)
{
    string exp;
    char pst('\0');
    if (!fixed) {
        for (auto i : expr) {
            if (i == ' ')
                continue;
            // +, - x
            if (i == '-' && !(pst <= '9' && pst >= '0' || pst == ')' || pst == '.')) {
                exp += negate_x;
            }
            else if (i == '+' && !(pst <= '9' && pst >= '0' || pst == ')' || pst == '.')) {
                continue;
            }
            else {
                exp.push_back(i);
            }
            pst = i;
        }
        exp += ende;
        expr = exp;
        fixed = true;
    }
}

void Postfix::toPostfix(void)
{
    // chstack to vector<string>
    string num;
    string oprtr;
    vector<char> chstack;

    if (!fixed) {
        // throw
    }

    for (const auto& ch : this->expr) {
        if (ch <= '9' && ch >= '0' || ch == '.') {
            num.push_back(ch);
        }
        else {
            if (!num.empty()) {
                postfix.push_back(num);
                num.clear();
            }
            if (string(1, ch) == ende) {
                break;
            }
            else if (ch == '(') {
                chstack.push_back(ch);
            }
            else if (ch == ')') {
                while (!chstack.empty() && chstack.back() != '(') {
                    oprtr.clear();
                    oprtr.push_back(chstack.back());
                    postfix.push_back(oprtr);

                    chstack.pop_back();
                }
                if (chstack.empty()) {
                    // syntax error: ()
                }
                else {  // chastack.back() == '('
                    chstack.pop_back(); // pop '('
                }
            }
            else { // ch is +-*/
                while (1) {
                    if (chstack.empty() || getPrior(chstack.back()) < getPrior(ch)) {
                        chstack.push_back(ch);
                        break;
                    }
                    else {  // ch_prior <= stack.back()
                        oprtr.clear();
                        oprtr.push_back(chstack.back());
                        postfix.push_back(oprtr);

                        chstack.pop_back();
                    }
                }
            }
        }
    }
    while (!chstack.empty()) {
        oprtr.clear();
        oprtr.push_back(chstack.back());
        postfix.push_back(oprtr);

        chstack.pop_back();
    }
}

int Postfix::getPrior(const std::string& oprtr) const
{
    unordered_map<string, int>::const_iterator i;
    if ((i = prior.find(oprtr)) != prior.end()) {
        return i->second;
    }
    // throw
    return -1;
}

void Postfix::calPostfix()
{
    // function class
    vector<Result> res;
    Result temp;
    for (const auto& s : postfix) {
        // s is num or oprtr
        if (Tool::isStrNum(s)) {
            res.push_back(Result(s));
        }
        else {
            // binops
            if (binops.find(s) != binops.end()) {
                temp = res.back();
                res.pop_back();
                res.back() = binops.at(s)(res.back(), temp);
            }
            else if (sinops.find(s) != sinops.end()) {
                res.back() = sinops.at(s)(res.back());
            }
            else {
                // throw
            }
        }
    }
    // empty throw
    result = res.empty() ? 0 : res.back();
}

string Postfix::getPostfixStr(void) const
{
    string res;
    for (const auto& i : postfix) {
        res += i + " ";
    }
    return res;
}
