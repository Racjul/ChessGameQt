
#pragma once
#include"Piece.hpp"
#include"../constant/Color.hpp"
#pragma warning(push(),0)
#include <qicon.h>
#pragma pop()


class Rook : public Piece {
public:
    Rook(const PieceColor color); 
    ~Rook()override = default;
    bool verifyMove(Move& move,ChessBoard* chessBoard) override;
private:
};




