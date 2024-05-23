#include"ExitButton.hpp"
#include"../constant/Color.hpp"
#pragma warning(push,0)
#include<QFont>
#include<QSize>
#include<QPushButton>
#pragma pop()

ExitButton::ExitButton(QWidget* parent):QPushButton("Exit",parent){

    setAutoFillBackground(true);
    setFixedSize(QSize(dimX_,dimY_));

    //Modifie la couleur
    QPalette colorPalette = palette();
    colorPalette.setColor(QPalette::Button, backgroundColor_);
    colorPalette.setColor(QPalette::ButtonText,fontColor_);
    setPalette(colorPalette);
    update();

    //Modifie la taille de la police ainsi que le style
    QFont font =  QFont("Arial",fontSize_,QFont::Bold);
    setFont(font);
}


