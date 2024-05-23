
#pragma once
#include"Piece.hpp"
#include"../constant/Color.hpp"
#include"../constant/Path.hpp"
#pragma warning(push(),0)
#include <qicon.h>
#pragma pop()

class Knight:public Piece{
public:
    Knight(const PieceColor color);
    ~Knight() override = default;
    bool verifyMove(Move& move, ChessBoard* chessBoard) override;
private:
};
