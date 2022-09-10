//
// Created by clay on 22-9-10.
//

#include "Result.h"
#include<sstream>
#include<iomanip>
using namespace std;

Result operator-(Result r)
{
    return Result(-r.res);
}

Result operator+(Result r1, Result r2)
{
    return Result(r1.res + r2.res);
}

Result operator-(Result r1, Result r2)
{
    return Result(r1.res - r2.res);
}

Result operator*(Result r1, Result r2)
{
    return Result(r1.res * r2.res);
}

Result operator/(Result r1, Result r2)
{
    return Result(r1.res / r2.res);
}

void Result::resToString(std::string::size_type bit)
{
    string rs;
    stringstream ss;
    if (!strfied) {
        ss << setiosflags(ios::fixed) << setprecision(bit) << res;
        ss >> rs;
        resStr = rs;
        strfied = true;
    }
}
