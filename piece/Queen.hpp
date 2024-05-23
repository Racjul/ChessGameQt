#pragma once
#include"Piece.hpp"
#include"../constant/Color.hpp"
#include"../constant/Path.hpp"
#pragma warning(push(),0)
#include <qicon.h>
#pragma pop()

class Queen:public Piece{
public:
    Queen(const PieceColor color);
    ~Queen() override = default;
    bool verifyMove(Move& move,ChessBoard* chessBoard) override;
private:
};


