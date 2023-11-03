#include "CCValidator.h"
#include <iterator>


std::vector<int> ccval::numStrToIntVec(const std::string& s)
{
    std::vector<int> v;
    for (char c : s)
    {
        if (c < '0' || c > '9')
            throw std::invalid_argument("Input string contains non-numerical characters.");
        v.push_back(int(c) - int('0'));
    }
    return v;
}

int ccval::digitSum(const int val)
{
    if (val < 0)
        throw std::invalid_argument("Digit sum is only defined for non-negative integers.");
    int sum = 0;
    int currentVal = val;
    do { sum += currentVal % 10; } while ((currentVal /= 10) > 0);
    return sum;
}

bool ccval::ccnumIsValid(const std::vector<int> digits)
{
    if (digits.empty())
        return false;

    // 1. remove check digit from payload
    int orgCheckDigit = digits.back();
    std::vector<int> payload{ digits.begin(), digits.end() - 1 };

    // 2. from right to left, double value of every second digit (including rightmost digit)
    for (auto rit = payload.rbegin(); rit != payload.rend(); rit += 2)
        *rit = *rit * 2;

    // 3. sum values of resulting digits
    int sum = 0;
    for (auto val : payload)
        sum += digitSum(val);

    // 4. calculate check digit
    int checkDigit = 10 - (sum % 10);

    // 5. compare original with calculated check digit
    return checkDigit == orgCheckDigit;
}
