#include"Knight.hpp"
Knight::Knight(const PieceColor color):Piece(color){
    if(color == PieceColor::BLACK)
        pathIcon_ = path::BLACK_KNIGHT;
    else
        pathIcon_ = path::WHITE_KNIGHT;
    icon_ = QIcon(pathIcon_);
}
bool Knight::verifyMove(Move& move, ChessBoard* chessBoard){
    Position listPosition[] = {Position(1,2),Position(2,1),Position(-1,-2),Position(-2,-1),Position(-1,2),Position(1,-2),Position(2,-1),Position(-2,1)};
    for(Position position : listPosition){
        if(position == move.difference && !isSameColor(move, chessBoard))
            return true;
    }
    move.setValid(false);
    return false;
}

  
