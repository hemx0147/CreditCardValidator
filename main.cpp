#include <iostream>
#include "CCValidator.h"


int main()
{
    std::cout << "Hello World" << std::endl;
    std::string ccn {"17893729974"};
    std::vector<int> digits = ccval::numStrToIntVec(ccn);

    std::cout << "digits: " << ccval::vec2str(digits) << ", size: " << digits.size() << "\n";
    std::string validity = "invalid";
    if (ccval::ccnumIsValid(digits))
        validity = "valid";
    std::cout << "CCNum is " << validity << '\n';
}
