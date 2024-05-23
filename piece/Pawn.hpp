#pragma once
#include"Piece.hpp"
#include"../constant/Color.hpp"
#include"../constant/Path.hpp"
#pragma warning(push(),0)
#include <qicon.h>
#pragma pop()

class Pawn:public Piece{
public:
    Pawn(const PieceColor color);
    ~Pawn() override = default;
    bool verifyMove(Move& move, ChessBoard* chessBoard) override;
private:
};
