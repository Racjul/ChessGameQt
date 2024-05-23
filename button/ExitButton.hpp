#pragma once
#include"../constant/Color.hpp"
#pragma warning(push(),0)
#include<QWidget>
#include <qcolor.h>
#include <qpushbutton.h>
#include <qtmetamacros.h>
#pragma pop()
class ExitButton: public QPushButton{
Q_OBJECT
    public:
    ExitButton(QWidget* parent = nullptr);
    ~ExitButton() override = default;
private:
    QColor backgroundColor_ = Color::QButton;
    QColor fontColor_ = Qt::white;

    static constexpr int fontSize_ = 18;
    static constexpr int dimX_ = 200;
    static constexpr int dimY_ = 100; 

};
