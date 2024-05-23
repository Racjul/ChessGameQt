#include"ChessBoard.hpp"

#include<cppitertools/range.hpp>

#include <iostream>
#include <memory>

#include "Position.hpp"
#include"Tile.hpp"

#pragma warning(push, 0)
#include <qicon.h>
#include <qgridlayout.h>
#include <qwidget.h>
#pragma pop() 

ChessBoard::ChessBoard(QWidget* parent):QGridLayout(parent){
    Tile* c;
    for(int i: iter::range(8)) {
        for(int j: iter::range(8)){
            if((i+j)%2 == 0)
                c = new Tile(TileColor::BLACK,i,j);
            else
                c = new Tile(TileColor::WHITE,i,j);
            addWidget(c, i,j);
        }
    }
    //Réduit l'espace entre les cases à 0 pour qu'elles soient collées
    setSpacing(0);
    setContentsMargins(0,0,0,0);
}


Tile* ChessBoard::getTile(const Position pos){
    return qobject_cast<Tile*>(itemAtPosition(pos.y, pos.x)->widget());
}


void ChessBoard::setPiece(std::unique_ptr<Piece> piece, Position position){
    getTile(position)->setPiece(std::move(piece));
}


void ChessBoard::deletePiece(const Position position){
    return getTile(position)->deletePiece();
}


std::unique_ptr<Piece> ChessBoard::getPiece(const Position position){
    return getTile(position)->getPiece();
}

void ChessBoard::movePiece(const Position initialPos, const Position finalPos){
    std::cout<< "Piece moved from " <<initialPos<< "to " << finalPos<< std::endl;
    setPiece(getPiece(initialPos),finalPos);
}

