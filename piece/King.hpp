#pragma once
#include"Piece.hpp"
#include"../constant/Color.hpp"
#include"../constant/Path.hpp"
#pragma warning(push(),0)
#include <qicon.h>
#pragma pop()

class King:public Piece{
public:
    King(const PieceColor color);
    ~King() override {numberKing--;}
    bool verifyMove(Move& move,ChessBoard* chessBoard) override;
    bool isKing() override{return true;}

private:
    static int numberKing;
    const int maxKing =2;
};
