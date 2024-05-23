#pragma once
#include "Position.hpp"
#include "Tile.hpp"
#include"../piece/Piece.hpp"
#include<memory>
#pragma warning(push(),0)
#include <qgridlayout.h>
#include <qicon.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include<QSize>
#pragma pop()
class Piece;
class Tile;
class ChessBoard: public  QGridLayout{
    Q_OBJECT
    public:
    ChessBoard(QWidget* parent=nullptr);

    Tile* getTile(const Position pos);
    void setPiece(std::unique_ptr<Piece> piece, Position position);
    void deletePiece(const Position position);
    std::unique_ptr<Piece> getPiece(const Position position);
    bool isOccupied(Position position);
    void movePiece(const Position initialPos, const Position finalPos);
private:
};
