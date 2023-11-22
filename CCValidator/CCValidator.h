#pragma once

#include <string>


namespace ccval
{
    // payment card numbers are composed of 8-19 digts https://en.wikipedia.org/wiki/Payment_card_number
    const size_t PCN_MIN_DIGITS = 8;
    const size_t PCN_MAX_DIGITS = 19;

    /**
     * @brief Validate a credit card number check digit via Luhn's algorithm.
     * @param digits The individual digits of the credit card number (including check digit as last digit).
     * @return true, if check digit is valid
     *         false, otherwise.
    */
    bool cardNumIsValid(const std::string& cardNumber);
}
