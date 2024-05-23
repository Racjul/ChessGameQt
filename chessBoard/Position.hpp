#pragma  once 
#include <ostream>
#include<utility>
class Position: private std::pair<int,int>{
public:
    Position():std::pair<int,int>(0,0){}
    Position(int x, int y):std::pair<int,int>(x,y){}
    int x=first,y=second;
    Position operator+(Position pos){return Position(x+pos.x, y+pos.y);}
    Position operator-(Position pos){return Position(x-pos.x, y-pos.y);}
    bool operator<=(Position pos){return x<=pos.x && y<=pos.y;}
    bool operator<=(int number){return x<=number && y<=number;}
    bool operator>=(Position pos){return x>=pos.x && y>=pos.y;}
    bool operator>=(int number){return x>=number && y>=number;}
    bool operator==(Position pos){return x==pos.x && y==pos.y;}
    Position reverse(){return Position(y,x);}
    Position changeSign(){return Position(-x,-y);}
    
};

inline std::ostream& operator<<(std::ostream& os, const Position& pos){
    os << "Position(" << pos.x << "," << pos.y << ")";
    return  os;
}

