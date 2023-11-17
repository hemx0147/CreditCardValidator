#include "ConsoleUi.h"
#include <iostream>
#include <sstream>
#include <algorithm>    // max_element, transform
#include <vector>


void ConsoleUi::drawBanner()
{
    const char frameChar = '*';
    const int padLen = 2;
    std::vector<std::string> bannerLines;
    bannerLines.push_back("Credit Card Validator");
    bannerLines.push_back("");
    bannerLines.push_back("Validate credit card numbers");
    bannerLines.push_back("using Luhn's algorithm.");

    auto maxIt = std::max_element(bannerLines.begin(), bannerLines.end(),
        [](const std::string& s1, const std::string& s2) {
            // comparison function definition requires that true is returned if first arg is less than second
            return s1.size() < s2.size();
        }
    );

    const size_t width = 2 * padLen + (*maxIt).size();

    // compute padding for each text line individually - each line should have same length after padding
    std::vector<std::string> paddedLines(bannerLines.size());
    std::transform(bannerLines.begin(), bannerLines.end(), paddedLines.begin(),
        [width](std::string& s) {
            const size_t linePadLen = (width - s.length()) / 2;
            std::string pad(linePadLen, ' ');
            std::string line = pad + s + pad;
            if (line.size() < width)
                line += std::string{ ' ' };
            return line;
        }
    );

    std::string hBorder(width + 2, frameChar);

    std::stringstream ss;
    ss << hBorder << std::endl;
    for (auto line : paddedLines)
        ss << frameChar << line << frameChar << std::endl;
    ss << hBorder << std::endl;

    std::cout << ss.str() << std::endl;
}

std::string ConsoleUi::getUserInput(const std::string& displayText)
{
    std::string userInput;
    std::cout << displayText;
    std::cin >> userInput;
    return userInput;
}
