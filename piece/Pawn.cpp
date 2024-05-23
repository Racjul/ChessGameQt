#include"Pawn.hpp"
#include <iostream>

Pawn::Pawn(const PieceColor color):Piece(color){
    if(color == PieceColor::BLACK)
        pathIcon_ = path::BLACK_PAWN;
    else
        pathIcon_ = path::WHITE_PAWN;
    icon_ = QIcon(pathIcon_);

}
bool Pawn::verifyMove(Move& move, ChessBoard* chessBoard){
    bool isEndEmpty = chessBoard->getTile(move.getEnd())->isEmpty();
    if(color_ == PieceColor::BLACK){
        if(move.difference == Position(0,1) && isEndEmpty)
            return true;
        else if(move.difference == Position(0,2) && chessBoard->getTile(move.getEnd())->isEmpty() && move.getStart().y == 1 && isPathEmpty(move, chessBoard)){
            return true;
        }
        else if((move.difference == Position(1,1) || move.difference == Position(-1,1)) && !isEndEmpty){
            return true;
        }
        else{
            move.setValid(false);
            return false;
        }
    }
    else{
        if(move.difference == Position(0,-1) && isEndEmpty)
            return true;
        else if(move.difference == Position(0,-2) && isEndEmpty && move.getStart().y == 6 && isPathEmpty(move, chessBoard)){
            return true;
        }
        else if((move.difference == Position(1,-1) || move.difference == Position(-1,-1)) && !isEndEmpty && !isSameColor(move, chessBoard)){
            return true;
        }
        else{
            move.setValid(false);
            return false;
        }

    }
    return true;
}

