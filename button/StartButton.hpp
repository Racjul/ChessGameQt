#pragma once
#include"../constant/Color.hpp"
#include <qnamespace.h>
#include <qtmetamacros.h>
#pragma warning(push(),0)
#include<QObject>
#include<QPushButton>
#include<QWidget>
#pragma pop()
class StartButton: public QPushButton{
    Q_OBJECT

public:
    StartButton();
    ~StartButton() override = default;
    
private:
    QColor backgroundColor_ = Color::QButton;
    QColor fontColor_ = Qt::white;

    static constexpr int fontSize_ = 18;
    static constexpr int dimX_ = 200;
    static constexpr int dimY_ = 100; 
};
