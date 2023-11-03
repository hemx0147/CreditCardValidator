#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>


// String representation of a vector
template<typename T> std::string vec2str(const std::vector<T>& v)
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

/**
 * @brief Transform a numerical string into a vector of corresponding integers (e.g. "123" -> [1, 2, 3]).
 * @param s                 The input string consisting of digit-characters only.
 * @throw invalid_argument  If the input string contains non-digit characters.
 * @return                  A vector containing individual integer digits of the input string.
*/
std::vector<int> numStrToIntVec(const std::string& s)
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

/**
 * @brief Compute the sum of the digits of a positive integer value.
 * @param val               The value to compute the digit sum of.
 * @throw invalid_argument  If the input value is negative.
 * @return                  The digit sum of the input value.
*/
int digitSum(const int val)
{
    if (val < 0)
        throw std::invalid_argument("Digit sum is only defined for non-negative integers.");
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


int main()
{
    std::string ccn {"17893729974"};
    std::vector<int> digits = numStrToIntVec(ccn);

    std::cout << "digits: " << vec2str(digits) << ", size: " << digits.size() << "\n";
    std::string validity = "invalid";
    if (ccnumIsValid(digits))
        validity = "valid";
    std::cout << "CCNum is " << validity << '\n';
}
