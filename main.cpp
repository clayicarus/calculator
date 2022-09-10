#include"Calculator.h"
#include<iostream>
using namespace std;

int main()
{
    Calculator cal;
    string exp;

    while (getline(cin, exp)) {
        cal.calExpr(exp);
        cout << cal.getPostfixStr() << endl;
        cout << cal.getLastResult() << endl;
    }

    return 0;
}