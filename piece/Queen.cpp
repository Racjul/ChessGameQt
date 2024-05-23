#include"Queen.hpp"
Queen::Queen(const PieceColor color):Piece(color){
    if(color == PieceColor::BLACK)
        pathIcon_ = path::BLACK_QUEEN;
    else
        pathIcon_ = path::WHITE_QUEEN;
    icon_ = QIcon(pathIcon_);
}
bool Queen::verifyMove(Move& move,ChessBoard* chessBoard){
    bool isEndEmpty = chessBoard->getTile(move.getEnd())->isEmpty();
    if((move.difference.x == 0 || move.difference.y == 0 || move.difference.x == move.difference.y || move.difference.x == -move.difference.y) && isPathEmpty(move, chessBoard) && (!isSameColor(move, chessBoard) || isEndEmpty))
        return true;
    move.setValid(false);
    return false;
}



