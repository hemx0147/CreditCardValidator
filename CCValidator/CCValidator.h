#pragma once

#include <string>


namespace ccval
{
    /**
     * @brief Validate a credit card number check digit via Luhn's algorithm.
     * @param digits The individual digits of the credit card number (including check digit as last digit).
     * @return true, if check digit is valid
     *         false, otherwise.
    */
    bool cardNumIsValid(const std::string& cardNumber);
}
