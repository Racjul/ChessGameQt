#pragma once
#include"../Game.hpp"
#include"../piece/Piece.hpp"
#include <memory>
//Implementation of RAII class to check if a move is legal 
// or it will put the king in check
class Check{
public:
    Check(Game* game, Move move);
private:
    std::unique_ptr<Piece> deletedPiece_ = nullptr;
    Move move_;
    bool isCheck = false;
    Game* game_;
    
    Position getKingPos();
    void verifyCheck();
    void returnDefaultPos();

};
