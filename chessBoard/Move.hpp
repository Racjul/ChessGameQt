#pragma once
#include<utility>
#include"Position.hpp"
class Move: private std::pair<Position,Position>{
public:
    Move():std::pair<Position,Position>(){}
    Move(Position start, Position end):std::pair<Position,Position>(start,end){}
    Move(int startX, int startY, int endX, int endY):std::pair<Position,Position>(Position(startX,startY),Position(endX,endY)){}

    Position getStart()const{return first;}
    Position getEnd()const{return second;}

    bool isValid()const{return isValid_;}
    void setValid(bool valid){isValid_ = valid;}

    Position difference = getEnd()-getStart();
private:
    bool isValid_ = true;
};


