#pragma once
#include"../constant/Color.hpp"
#include"../chessBoard/Position.hpp"
#include"../chessBoard/Move.hpp"
#include"../chessBoard/ChessBoard.hpp"
#include <qobject.h>
#include <qtmetamacros.h>
#pragma warning(push(),0)
#include <qicon.h>
#pragma pop()
class ChessBoard;
class Tile;
class Piece:QObject{
    Q_OBJECT
public:
    Piece(const PieceColor color);
    virtual ~Piece() = default;
    virtual bool verifyMove(Move& move,ChessBoard* chessBoard)=0;
    QIcon getIcon() const {return icon_;}
    Position getPosition(){return position_;}
    void setPosition(Position position){position_ = position; }
    QString getPathIcon(){return pathIcon_;}
    PieceColor getColor(){return color_;}
    
    bool isPathEmpty(Move move, ChessBoard* chessBoard);
    bool isSameColor(Move move, ChessBoard* chessBoard);
    virtual bool isKing(){return false;}
protected:
    QString pathIcon_;
    Position position_ = {8,8};
    QIcon icon_; 
    PieceColor color_;
};



