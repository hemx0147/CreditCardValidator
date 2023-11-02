// CreditCardValidator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

template<typename T>
std::string vec2str(const std::vector<T>& v)
{
    std::stringstream ss;
    ss << '[';
    for (auto it = v.begin(); it != v.end(); it++)
    {
        ss << *it;
        if (it < (v.end() - 1))
            ss << ", ";
    }
    ss << ']';
    return ss.str();
}

// compute the sum of the digits of an integer value
int digitSum(const int val)
{
    int sum = 0;
    int currentVal = val;
    do { sum += currentVal % 10; } while ((currentVal /= 10) > 0);
    return sum;
}

/**
 * @brief Validate a credit card number check digit via Luhn's algorithm.
 * @param digits The individual digits of the credit card number (including check digit as last digit).
 * @return true, if check digit is valid
 *         false, otherwise.
*/
bool ccnumIsValid(const std::vector<int> digits)
{
    if (digits.empty())
        return false;

    // 1. remove check digit from payload
    std::cout << "checking " << vec2str(digits) << '\n';
    int orgCheckDigit = digits.back();
    std::vector<int> payload{ digits.begin(), digits.end() - 1 };
    std::cout << "provided CD: " << orgCheckDigit << '\n';
    std::cout << "payload " << vec2str(payload) << '\n';

    // 2. from right to left, double value of every second digit (including rightmost digit)
    for (auto rit = payload.rbegin(); rit != payload.rend(); rit += 2)
        *rit = *rit * 2;
    std::cout << "multiplied payload " << vec2str(payload) << '\n';

    // 3. sum values of resulting digits
    int sum = 0;
    std::cout << "sum of digits: ";
    for (auto val : payload)
    {
        int ds = digitSum(val);
        sum += ds;
        std::cout << ds << " + ";
    }
    std::cout << " = " << sum << '\n';

    // 4. calculate check digit
    int checkDigit = 10 - (sum % 10);
    std::cout << "new CD: " << checkDigit << '\n';

    return checkDigit == orgCheckDigit;
}

int main()
{
    std::string ccn = std::to_string(17893729974);
    std::vector<int> digits;
    for (char c : ccn)
        digits.push_back(int(c) - int('0'));

    std::cout << "digits: " << vec2str(digits) << ", size: " << digits.size() << "\n";
    std::string validity = "invalid";
    if (ccnumIsValid(digits))
        validity = "valid";
    std::cout << "CCNum is " << validity << '\n';
}
