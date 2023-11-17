#include "pch.h"
#include "framework.h"
#include "CCValidator.h"


bool ccval::cardNumIsValid(const std::string& cardNumber)
{
    if (cardNumber.empty() || cardNumber.size() < 2)
        return false;

    int digit;
    int sum = 0;
    int parity = cardNumber.size() % 2;
    for (int i = 0; i < cardNumber.size(); i++)
    {
        digit = int(cardNumber[i]) - int('0');
        if (i % 2 == parity)
        {
            digit = 2 * digit;
            if (digit > 9)
                digit = digit - 9;
        }
        sum += digit;
    }
    return 0 == sum % 10;
}