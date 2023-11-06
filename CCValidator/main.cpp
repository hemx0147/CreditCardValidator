#include <iostream>
#include "CCValidator.h"


int main()
{
    std::cout << "Hello World" << std::endl;
    std::string cardNum {"17893729974"};

    std::cout << "cardNum: " << cardNum << ", size: " << cardNum.length() << "\n";
    bool v1 = ccval::cardNumIsValid(cardNum);
    std::cout << "CCNum is " << (v1 ? "valid" : "invalid") << '\n';
}
