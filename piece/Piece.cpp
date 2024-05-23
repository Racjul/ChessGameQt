#include"Piece.hpp"
#include<iostream>
#include <cppitertools/range.hpp>
#include <qobject.h>
Piece::Piece(PieceColor color):QObject(){
    color_ = color;
}
bool Piece::isPathEmpty(Move move, ChessBoard* chessBoard){
    Position difference = move.difference;
    if(difference <=0){
        difference = difference.changeSign();
        if(difference.x == difference.y){
            for(int i = 1;i <difference.x;i++){
                if(!chessBoard->getTile( getPosition()-Position(i,i))->isEmpty())
                    return false;
            }
        }
        else if(difference.x == 0){
            std::cout<< "Position difference:" << difference<<std::endl;
            for(int i = 1;i <difference.y;i++){
                if(!chessBoard->getTile(getPosition()-Position(0,i)) ->isEmpty())
                    return false;
            }
        }
        else if(difference.y ==0){
            for(int i = 1;i <difference.x;i++){
                if(!chessBoard->getTile(getPosition()-Position(i,0))->isEmpty())
                    return false;
            } 
        }
        return true;
    }


    else{

        if(difference.x == difference.y ){
            for(int i = 1;i <difference.x;i++){
                if(!chessBoard->getTile(Position(i,i)+ getPosition())->isEmpty())
                    return false;
            }
        }
        if(difference.x == -difference.y){
            if(difference.x < difference.y){
                for(int i = 1;i <difference.y;i++){
                    if(!chessBoard->getTile(getPosition() - Position(i,-i))->isEmpty())
                        return false;
                }
            }
            else{
                for(int i = 1;i <difference.x;i++)
                    if(!chessBoard->getTile(getPosition() -Position(-i,i) )->isEmpty())
                        return false;
            }
        }


        else if(difference.x == 0){
            std::cout<< "Position difference:" << difference<<std::endl;
            for(int i = 1;i <difference.y;i++){
                if(!chessBoard->getTile(Position(0,i)+ getPosition())->isEmpty())
                    return false;
            }
        }
        else if(difference.y ==0){
            for(int i = 1;i <difference.x;i++){
                if(!chessBoard->getTile(Position(i,0)+ getPosition())->isEmpty())
                    return false;
            } 
        }
        return true;
    }
}

bool Piece::isSameColor(Move move, ChessBoard* chessBoard){
    if(chessBoard->getTile(move.getEnd())->getPieceColor() == this->getColor()) 
        return true;
    std::cout<<"test"<<std::endl;
    return false;
}
