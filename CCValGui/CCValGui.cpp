#include "CCValGui.h"
#include <QString>
#include "CCValidator.h"
#include <QIntValidator>
#include <QRegularExpression>

CCValGui::CCValGui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    resetState();

    connect(ui.checkButton, &QAbstractButton::clicked, this, &CCValGui::checkCardNumValidity);
    connect(ui.clearButton, &QAbstractButton::clicked, this, &CCValGui::resetState);
    connect(ui.cardInput, &QLineEdit::returnPressed, this, &CCValGui::checkCardNumValidity);
    connect(ui.cardInput, &QLineEdit::textChanged, this, &CCValGui::removeErrorMessage);

    // TODO: react to QLineEdit::inputRejected() signal to inform user when an invalid input char is entered
}

CCValGui::~CCValGui()
{}

void CCValGui::resetState()
{
    removeErrorMessage();
    ui.isValidIcon->clear();
    ui.cardInput->clear();
    ui.cardInput->setFocus();
}

void CCValGui::addErrorMessage(const QString& msg)
{
    errorLabel.setText(msg);
    ui.gridLayout->addWidget(&errorLabel, 1, 0, 3, 0);
    errorLabel.setVisible(true);
}

void CCValGui::removeErrorMessage()
{
    if (ui.gridLayout->rowCount() > 1)
    {
        ui.gridLayout->removeWidget(&errorLabel);
        errorLabel.setVisible(false);
    }
}

void CCValGui::checkCardNumValidity()
{
    QString cardNum = ui.cardInput->text();

    // verify that input consists of digit characters only
    const QRegularExpression re_NonDigitChars("[^0-9]");
    if (cardNum.contains(re_NonDigitChars))
    {
        addErrorMessage("Only digit characters (0-9) are allowed.");
        return;
    }

    // verify input length
    const qsizetype pcnLen = cardNum.length();
    if (pcnLen < ccval::PCN_MIN_DIGITS || pcnLen > ccval::PCN_MAX_DIGITS)
    {
        QString minDigits = QString::number(ccval::PCN_MIN_DIGITS);
        QString maxDigits = QString::number(ccval::PCN_MAX_DIGITS);
        QString msg = QString("Credit Card Number must be between %1 and %2 digits long.").arg(minDigits, maxDigits);
        addErrorMessage(msg);
        return;
    }


    bool numIsValid = ccval::cardNumIsValid(cardNum.toStdString());

    ui.isValidIcon->setPixmap(invalidIcon);
    if (numIsValid)
        ui.isValidIcon->setPixmap(validIcon);
}
