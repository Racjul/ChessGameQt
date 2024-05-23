#pragma once
#include"../constant/Color.hpp"
#include"../constant/Path.hpp"
#include "Position.hpp"
#include"../piece/Piece.hpp"
#include <memory>

#pragma warning(push,0)
#include <qsize.h>
#include <qicon.h>
#include <qpalette.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include<QPushButton>
#pragma pop()
class Piece;
class Tile:public QPushButton
{
    Q_OBJECT

    public:
    Tile(TileColor color,int x,int y);

    void changeColor(const TileColor color);

    Position getPosition(){return position_;}
    TileColor getColor(){return color_;}
    
    void setPiece(std::unique_ptr<Piece> piece);
    void deletePiece();
    std::unique_ptr<Piece> getPiece();
    PieceColor getPieceColor();
    bool isEmpty(){return isEmpty_;}

public slots:
    void onTileClick();

signals:
    void tileClicked(Tile* tile);

private:
    std::unique_ptr<Piece> piece_;
    bool isEmpty_ = true;
    Position position_;
    TileColor color_;
    const QSize iconSize_ = QSize(120,120);
    static constexpr int dimX_ = 125;
    static constexpr int dimY_ = 125;
};
