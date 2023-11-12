#include <iostream>
#include "CCValidator.h"
#include "ConsoleUi.h"


int main()
{
    ConsoleUi ui;
    ui.drawBanner();

    std::string cardNum;
    bool isValid = false;
    while (true)
    {
        cardNum = ui.getUserInput("Enter credit card number: ");
        isValid = ccval::cardNumIsValid(cardNum);
        std::cout << "Card number is " << (isValid ? "valid" : "invalid") << '.' << std::endl;
    }

}
