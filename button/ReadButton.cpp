#include"ReadButton.hpp"
#include"../constant/Color.hpp"
#pragma warning(push,0)
#include<QFont>
#include<QSize>
#include<QPushButton>
#include<QWidget>
#pragma pop()

ReadButton::ReadButton():QPushButton("Load"){

    setAutoFillBackground(true);
    setFixedSize(dimX_,dimY_);
    
    QPalette colorPalette = palette();
    colorPalette.setColor(QPalette::Button, backgroundColor_);
    colorPalette.setColor(QPalette::ButtonText,fontColor_);
    setPalette(colorPalette);
    update();


    //Modifie la taille de la police ainsi que le style
    QFont font =  QFont("Arial",fontSize_,QFont::Bold);
    setFont(font);
}


