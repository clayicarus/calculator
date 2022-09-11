//
// Created by clay on 22-9-10.
//

#include "Postfix.h"
#include"Tool.h"
using namespace std;
// operator not begin with number or sign.

const std::string Postfix::negate_x = "~";
const std::unordered_map<std::string, int> Postfix::prior = {
        // another function is 0.
        {negate_x, -1},
        {"*", -2}, {"/", -2},
        {"+", -3}, {"-", -3},
        {"(", -4}
};
const std::unordered_map < std::string, std::function<Result(Result, Result)>>Postfix::binops = {
        {"+", std::plus<Result>()}, {"-", std::minus<Result>()},
        {"*", std::multiplies<Result>()}, {"/", std::divides<Result>()},
};
const std::unordered_map < std::string, std::function<Result(Result)>>Postfix::sinops = {
        {negate_x, std::negate<Result>()},
};

void Postfix::fixExpr()
{
    string exp;
    char pst('\0');
    if (!fixed) {
        for (auto i : expr) {
            if (i == ' ')
                continue;
            // +, - x
            if (i == '-' && !Tool::isNum(pst) && pst != ')') {
                exp += negate_x;
            }
            else if (i == '+' && !Tool::isNum(pst) && pst != ')') {
                continue;
            }
            else{
                exp.push_back(i);
            }
            pst = i;
        }

        expr = exp;
        fixed = true;
    }
}

// #include<iostream>
void Postfix::toPostfix()
{
    int i;
    vector<string> ostack;
    string num;
    string op;

    if(!fixed){
        // throw
    }

    i = 0;
    // cout << expr << endl;
    while(i < expr.size()){
        //match num then func
        if(Tool::isNum(expr[i])){
            while(i < expr.size() && Tool::isNum(expr[i])){
                num.push_back(expr[i++]);
            }
            // cout << "test1" << endl;
            postfix.push_back(num);
            num.clear();
            continue;
        }else if(Tool::isBracket(expr[i])){
            // cout << "test4" << endl;
            if(expr[i] == '('){
                ostack.push_back(string(1, '('));
            }else if(expr[i] == ')'){
                while(!ostack.empty() && ostack.back() != "("){
                    postfix.push_back(ostack.back());
                    ostack.pop_back();
                }
                if(ostack.empty()){
                    // throw
                }else{  // ostack.back() == "("
                    ostack.pop_back();
                }
            }
            ++i;
        }else if(Tool::isOperator(expr[i])){
            // cout << "test3" << endl;
            while(i < expr.size() && Tool::isOperator(expr[i])){
                op.push_back(expr[i++]);
            }
            while(!op.empty()){
                if(ostack.empty() || getPrior(ostack.back()) < getPrior(op)){
                    ostack.push_back(op);
                    op.clear();
                }else{
                    postfix.push_back(ostack.back());
                    ostack.pop_back();
                }
            }
            continue;
        }else if(Tool::isFunc_or_var(expr[i])){
            while(i < expr.size() && Tool::isFunc_or_var(expr[i])){
                op.push_back(expr[i++]);
            }
            while(!op.empty()){
                if(ostack.empty() || getPrior(ostack.back()) < getPrior(op)){
                    ostack.push_back(op);
                    op.clear();
                }else{
                    postfix.push_back(ostack.back());
                    ostack.pop_back();
                }
            }
            continue;
        }else{
            // throw
        }
    }
    while(!ostack.empty()){
        postfix.push_back(ostack.back());
        ostack.pop_back();
    }
}

int Postfix::getPrior(const std::string& op) const
{
    unordered_map<string, int>::const_iterator i;
    if ((i = prior.find(op)) != prior.end()) {
        return i->second;
    }
    // another function
    return 0;
}

// #include<iostream>
void Postfix::calPostfix()
{
    vector<Result> res;
    Result temp;
    for (const auto& s : postfix) {
        // s is num or op
        if (Tool::isStrNum(s)) {
            res.push_back(Result(s));
        }
        else {
            // binops
            if(res.empty()){
                // cerr << "end of res." << endl;
                // throw end of res.
            }
            if (binops.find(s) != binops.end()) {
                temp = res.back();
                res.pop_back();
                if(res.empty()){
                    // cerr << "end of res." << endl;
                    // throw end of res.
                }
                res.back() = binops.at(s)(res.back(), temp);
            }
            else if (sinops.find(s) != sinops.end()) {
                res.back() = sinops.at(s)(res.back());
            }
            else {
                // throw func or op not found.
            }
        }
    }
    result = res.empty() ? 0 : res.back();
}

string Postfix::getPostfixStr() const
{
    string res;
    for (const auto& i : postfix) {
        res += i + " ";
    }
    return res;
}
