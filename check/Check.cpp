#include"Check.hpp"
#include"../Errors.hpp"
#include <cppitertools/range.hpp>
#include <memory>
Check::Check(Game* game, Move move):move_(move),game_(game){
    game_->setPiece(game_->getPiece(move_.getStart()), move_.getEnd());
    verifyCheck();
    returnDefaultPos();
    if(isCheck)
        throw InvalidMoveError("King will be in check");
    
}

void Check::returnDefaultPos(){
    game_->setPiece(game_->getPiece(move_.getEnd()), move_.getStart());
    if(deletedPiece_)
        game_->setPiece(std::move(deletedPiece_), move_.getEnd());
}

Position Check::getKingPos(){
    for(int i: iter::range(8)){
        for(int j: iter::range(8)){
            Position position = Position(i,j);
            if(!game_->isPositionEmpty(Position(i,j))){
                std::unique_ptr<Piece> temp = game_->getPiece(position);
                if(temp->isKing() && temp->getColor() == game_->getCurrentPlayerColor()){
                    game_->setPiece(std::move(temp), position);
                    return position;
                }
                game_->setPiece(std::move(temp), position);
            }
        }
    }
    return {};
}
 void Check::verifyCheck(){
    Position kingPosition = getKingPos();
    for(int i: iter::range(8)){
        for(int j: iter::range(8)){
            Position tempPosition(i,j);        
            bool isNotSamePosition = tempPosition !=kingPosition;
            bool isTileEmpty = game_->isPositionEmpty(tempPosition);
            if(!isTileEmpty && isNotSamePosition){
                Move move(tempPosition,kingPosition);
                std::unique_ptr<Piece> tempPiece = game_->getPiece(tempPosition);
                bool isMoveValid = tempPiece->verifyMove(move, game_->getChessBoard());
                if(isMoveValid){
                    game_->setPiece(std::move(tempPiece), tempPosition);
                    isCheck = true;
                    return;
                }
                game_->setPiece(std::move(tempPiece), tempPosition);
            }
             
                
        }
    }

}
   
