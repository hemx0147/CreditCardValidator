#include "pch.h"
#include "CppUnitTest.h"
#include "CCValidator.h"
#include <vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace ccval;

namespace CCValidatorTests
{
    TEST_CLASS(CreditNumIsValidTests)
    {
        TEST_METHOD(ValidCC_ReturnsTrue)
        {
            std::vector<bool> actual;
            std::vector<bool> expected(4, true);
            std::vector<std::string> cardNumbers = {
                "17893729974",
                "79927398713",
                "446667651",
                "18937"
            };

            for (auto& cardNum : cardNumbers)
                actual.push_back(cardNumIsValid(cardNum));

            Assert::IsTrue(expected == actual);
        }

        TEST_METHOD(InvalidCC_ReturnsFalse)
        {
            std::string baseNum = "1893";
            std::vector<std::string> cardNumbers;
            for (int i = 0; i < 10; i++)
            {
                if (i == 7)
                    continue;
                cardNumbers.push_back(baseNum + std::to_string(i));
            }
            std::vector<bool> expected(cardNumbers.size(), false);
            std::vector<bool> actual;

            for (auto& cardNum : cardNumbers)
                actual.push_back(cardNumIsValid(cardNum));

            Assert::IsTrue(expected == actual);
        }

        TEST_METHOD(EmptyCC_ReturnsFalse)
        {
            const std::string emptyCardNum{ "" };
            bool actual = cardNumIsValid(emptyCardNum);
            Assert::IsFalse(actual);
        }

        TEST_METHOD(SingleDigitCC_ReturnsFalse)
        {
            std::string cardNum;
            const int numSingleDigits = 10;
            std::vector<bool> expected(numSingleDigits, false);
            std::vector<bool> actual;

            for (int i = 0; i < numSingleDigits; i++)
                actual.push_back(cardNumIsValid(std::to_string(i)));

            Assert::IsTrue(expected == actual);
        }
    };
}
