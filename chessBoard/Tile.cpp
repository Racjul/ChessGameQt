#include"Tile.hpp"
#include <iostream>
#include"../constant/Color.hpp"
#pragma warning(push,0)
#include <qicon.h>
#include <qnamespace.h>
#include <qpalette.h>
#include <qwidget.h>
#pragma pop()

Tile::Tile(TileColor color,int x , int y): QPushButton(){
    
    color_ = color;
    changeColor(color_);

    //Exchange position to match the array
    position_ = Position(y,x);

    setFixedSize(dimX_,dimY_);
    setContentsMargins(0,0,0,0);
    setAutoFillBackground(true);
    setIconSize(iconSize_);

    connect(
        this,SIGNAL(clicked()),
        this,SLOT(onTileClick()));
}
    
void Tile::changeColor(TileColor color){
    QPalette colorPalette = palette();
    switch (color) {
        case TileColor::BLACK:
            this->color_ = color;
            colorPalette.setColor(QPalette::Button,Color::QWhite);
            break;
        case TileColor::WHITE:
            this->color_ = color;
            colorPalette.setColor(QPalette::Button,Color::QBlack);
            break;
        case TileColor::RED:
            colorPalette.setColor(QPalette::Button,Color::QRed);
            break;
        case TileColor::BLUE:
            colorPalette.setColor(QPalette::Button,Color::QBlue);
            break;
    }
    setPalette(colorPalette);
    update();
}

void Tile::onTileClick(){
    std::cout<<"Tile clicked at position: " <<  this->getPosition() <<std::endl;
    emit tileClicked(this);
}

void Tile::setPiece(std::unique_ptr<Piece> piece){
    isEmpty_ = false;
    piece_ = std::move(piece);
    piece_->setPosition(getPosition());
    setIcon(piece_->getIcon());
}
std::unique_ptr<Piece> Tile::getPiece(){
    if(piece_.get()){
        isEmpty_ = true;
        setIcon(QIcon());
        return std::move(piece_);
    }
    return nullptr;
}
PieceColor Tile::getPieceColor(){
    if(piece_)
        return piece_->getColor();
    else 
        return PieceColor();
}
void Tile::deletePiece(){
    isEmpty_ = true;
    piece_.reset();
    setIcon(QIcon());
    changeColor(getColor());
}


