
#include"Rook.hpp"
#include"../constant/Path.hpp"
Rook::Rook(const PieceColor color):Piece(color){
    if(color == PieceColor::BLACK)
        pathIcon_ = path::BLACK_ROOK;
    else
        pathIcon_ = path::WHITE_ROOK;
    icon_ = QIcon(pathIcon_);
}
bool Rook::verifyMove(Move& move,ChessBoard* chessBoard){

    bool isEndEmpty = chessBoard->getTile(move.getEnd())->isEmpty();
    if((move.difference.x == 0 || move.difference.y == 0) && isPathEmpty(move, chessBoard) && (!isSameColor(move, chessBoard) || isEndEmpty))
        return true;
    move.setValid(false);
    return false;

    

}


