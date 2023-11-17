#pragma once

#include <string>

class ConsoleUi
{

public:
    void drawBanner();
    std::string getUserInput(const std::string& displayText);
};

