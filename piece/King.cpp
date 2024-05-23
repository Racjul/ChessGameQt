#include"King.hpp"
#include"../Errors.hpp"
#include<iostream>
int King::numberKing = 0;
King::King(const PieceColor color):Piece(color){
    numberKing++;
    if(color == PieceColor::BLACK)
        pathIcon_ = path::BLACK_KING;

    else
        pathIcon_ = path::WHITE_KING;
    icon_ = QIcon(pathIcon_);
    if(numberKing > maxKing)
        throw ExcessivePieceError("Too much King");
}
bool King::verifyMove(Move& move, ChessBoard* chessBoard){
    bool isEndEmpty = chessBoard->getTile(move.getEnd())->isEmpty();
    Position listePositions[] = {Position(1,1),Position(-1,-1),Position(-1,1),Position(1,-1),Position(1,0),Position(0,1),Position(-1,0),Position(0,-1)};
    for(Position position : listePositions)
        if(position == move.difference && (!isSameColor( move, chessBoard) ||isEndEmpty) )
            return true;
    move.setValid(false);
    return false;
}

