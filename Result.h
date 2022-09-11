//
// Created by clay on 22-9-10.
//

#ifndef CALCULATOR_RESULT_H
#define CALCULATOR_RESULT_H

#include<string>
#include<cmath>
class Result
{
    friend Result operator-(Result r);
    friend Result operator+(Result r1, Result r2);
    friend Result operator-(Result r1, Result r2);
    friend Result operator*(Result r1, Result r2);
    friend Result operator/(Result r1, Result r2);
public:
    Result() = default;
    Result(long double lld) : res(lld) {}

    Result resSin() const { return Result(sinl(res)); }
    Result resCos() const { return Result(cosl(res)); }
    Result resTan() const { return Result(tanl(res)); }

    explicit Result(const std::string& num) : res(std::stold(num)) {}
    std::string getResStr(void) const { return resStr; }
    void resToString(std::string::size_type bit = 8);
private:
    long double res = 0.0;
    bool strfied = false;
    std::string resStr = "";
};
Result operator+(Result r1, Result r2);
Result operator-(Result r1, Result r2);
Result operator*(Result r1, Result r2);
Result operator/(Result r1, Result r2);

#endif //CALCULATOR_RESULT_H
