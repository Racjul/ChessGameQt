#include"Bishop.hpp"

Bishop::Bishop(const PieceColor color):Piece(color){
    if(color == PieceColor::BLACK)
        pathIcon_= path::BLACK_BISHOP;
    else
        pathIcon_ = path::WHITE_BISHOP;
    icon_ = QIcon(pathIcon_);
        
}

bool Bishop::verifyMove(Move& move,ChessBoard* chessBoard){
    bool isEndEmpty = chessBoard->getTile(move.getEnd())->isEmpty();
    bool isValidBishopMove = move.difference.x == move.difference.y || move.difference.x == -move.difference.y;
    if(isValidBishopMove && (isEndEmpty || !isSameColor(move, chessBoard)) && isPathEmpty(move, chessBoard))
        return true;
    move.setValid(false);
    return false;

}









