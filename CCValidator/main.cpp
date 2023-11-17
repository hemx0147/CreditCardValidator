#include <iostream>
#include "CCValidator.h"
#include "ConsoleUi.h"
#include <vector>


int main(int argc, char *argv[])
{
    // put all command line params in vector, check if correct param is given and use its value as card number.
    // -c option checks given number without UI and returns result as success/error program exit code.
    std::string cardNum = "";
    std::vector<std::string> args(argv + 1, argv + argc);
    if (args[0] == "-c")
    {
        if (args.size() > 1)
        {
            cardNum = args[1];
        }
        return !ccval::cardNumIsValid(cardNum);
    }

    // program call with invalid or without parameters use console UI version
    ConsoleUi ui;
    ui.drawBanner();
    bool isValid = false;
    while (true)
    {
        cardNum = ui.getUserInput("Enter credit card number: ");
        isValid = ccval::cardNumIsValid(cardNum);
        std::cout << "Card number is " << (isValid ? "valid" : "invalid") << '.' << std::endl;
    }

}
