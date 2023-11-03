#pragma once

#include <string>
#include <vector>
#include <sstream>

namespace ccval
{
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
    std::vector<int> numStrToIntVec(const std::string& s);

    /**
     * @brief Compute the sum of the digits of a positive integer value.
     * @param val               The value to compute the digit sum of.
     * @throw invalid_argument  If the input value is negative.
     * @return                  The digit sum of the input value.
    */
    int digitSum(const int val);

    /**
     * @brief Validate a credit card number check digit via Luhn's algorithm.
     * @param digits The individual digits of the credit card number (including check digit as last digit).
     * @return true, if check digit is valid
     *         false, otherwise.
    */
    bool ccnumIsValid(const std::vector<int> digits);
}
