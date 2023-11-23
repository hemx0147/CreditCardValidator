#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CCValGui.h"
#include <QPixMap>

class CCValGui : public QMainWindow
{
    Q_OBJECT

public:
    CCValGui(QWidget *parent = nullptr);
    ~CCValGui();

    void addErrorMessage(const QString& msg);

private:
    Ui::CCValGuiClass ui;
    QPixmap validIcon = QPixmap("rsc/checked.png", "PNG");
    QPixmap invalidIcon = QPixmap("rsc/unchecked.png", "PNG");
    QLabel errorLabel;
    const QString appTitle{ "Credit Card Validator" };


public slots:
    void checkCardNumValidity();
    void resetState();
    void removeErrorMessage();
};
