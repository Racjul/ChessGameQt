#include"Game.hpp"

#include"button/StartButton.hpp"
#include"button/CleanButton.hpp"
#include"button/ReadButton.hpp"
#include"button/ExitButton.hpp"

#include "check/Check.hpp"
#include "constant/Color.hpp"

#include"chessBoard/ChessBoard.hpp"
#include "chessBoard/Position.hpp"

#include"piece/King.hpp"
#include"piece/Queen.hpp"
#include"piece/Bishop.hpp"
#include"piece/Knight.hpp"
#include"piece/Rook.hpp"
#include"piece/Pawn.hpp"

#include"Errors.hpp"

#include <cppitertools/range.hpp>

#include <iostream>
#include <memory>

#pragma warning(push,0)
#include <QFileSelector>
#include<QFileDialog>
#include<QMessageBox>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <QVBoxLayout>
#pragma pop()

Game::Game(QWidget* parent):QMainWindow(parent){

    //Change color of the window
    QPalette  palette = this->palette();
    palette.setColor(QPalette::Window, Color::QBackground);
    setPalette(palette);

    //Change window icon
    QMainWindow::setWindowIcon(QIcon("img/favicon.ico"));

    //Set window title
    QMainWindow::setWindowTitle("Chess.com");

    //Create layout and widget of the page
    centralWidget_ = new QWidget(this);
    horizontalLayout_ = new QHBoxLayout(centralWidget_); 
    listButton_ = new QVBoxLayout();
    chessBoard_ = new ChessBoard();

    setCentralWidget(centralWidget_);

    //Add widget and layout to the page
    horizontalLayout_->addLayout(listButton_);
    horizontalLayout_->addLayout(chessBoard_);

    //Create and add button to the list of buttons
    startButton_ = new StartButton();
    cleanButton_ = new CleanButton();
    readButton_ = new ReadButton();
    exitButton_ = new ExitButton();
    listButton_->addWidget(startButton_);
    listButton_->addWidget(cleanButton_);
    listButton_->addWidget(readButton_);
    listButton_->addWidget(exitButton_);

    connectMenu();

}
void Game::setPiece(std::unique_ptr<Piece> piece, Position position){
    chessBoard_->setPiece(std::move(piece),position);
}
void Game::movePiece(const Move& move ){
    chessBoard_->movePiece(move.getStart(), move.getEnd());
}

void Game::verifyMove(Move& move){
    std::unique_ptr<Piece> temp =  chessBoard_->getPiece(move.getStart()); 
    temp->verifyMove(move,chessBoard_);
    setPiece(std::move(temp), move.getStart());
    if(!move.isValid() || move.getStart() == move.getEnd())
        throw InvalidMoveError("Mauvais coup");
}
//Clean methods 
//---------------------------------------------------------------
void Game::cleanBoard(){
    for(const int& i: iter::range(8))
    for(const int& j : iter::range(8))
    chessBoard_->deletePiece(Position(i,j)); 

}
void Game::cleanColor(){
    for(const int& i: iter::range(8))
    for(const int& j : iter::range(8)){
        Tile* temp = chessBoard_->getTile(Position(i,j)); 
        temp->changeColor(temp->getColor());
    }

}


//Connect Methods
//-------------------------------------------------------------------------------
void Game::connectStartMove(){
    disconnectAllTiles();
    for(int i : iter::range(8)){
        for(int j : iter::range(8)){
            Position tempPos  = Position(i,j);
            if(!chessBoard_->getTile(tempPos)->isEmpty()){
                std::unique_ptr<Piece> tempPiece = chessBoard_->getPiece(tempPos);
                Tile* tempTile = chessBoard_->getTile(tempPos);

                if(tempPiece->getColor() == PieceColor::WHITE && isPlayerWhite_){
                    connect(tempTile,                   &Tile::tileClicked,
                            this,                       &Game::onMoveStart);
                }

                else if(tempPiece->getColor() == PieceColor::BLACK && !isPlayerWhite_){
                    connect(tempTile,  &Tile::tileClicked,
                            this,      &Game::onMoveStart);
                }

                setPiece(std::move(tempPiece),tempPos);
            }
        }
    }
}
void Game::connectEndMove(){

    disconnectAllTiles();
    std::unique_ptr<Piece> tempPiece= initTile_->getPiece();

    for(int i : iter::range(8)){
        for(int j : iter::range(8)){

            Position tempPos  = Position(i,j);
            Move tempMove = Move(initTile_->getPosition(),tempPos); 
            Tile* tempTile = chessBoard_->getTile(tempPos);

            bool isMoveValid =tempPiece->verifyMove(tempMove, chessBoard_); 
            connect(tempTile,           &Tile::tileClicked,
                    this,               &Game::onMoveEnd);
            if(!chessBoard_->getTile(tempPos)->isEmpty()){
                std::unique_ptr<Piece> tempEnnemyPiece = chessBoard_->getPiece(tempPos);
                setPiece(std::move(tempEnnemyPiece),tempPos);
            }   
            if(isMoveValid && tempMove.getStart() != tempMove.getEnd())            
                tempTile->changeColor(TileColor::BLUE);
        }


    }             
    setPiece(std::move(tempPiece), initTile_->getPosition());

}

void Game::connectMenu(){ 

    connect(startButton_,  &Tile::clicked,    
            this,          &Game::onStartClick);
    connect(cleanButton_,  &CleanButton::clicked,
            this,          &Game::onCleanClick);
    connect(readButton_,   &CleanButton::clicked,
            this,          &Game::onReadClick);
    connect(exitButton_,   &ExitButton::clicked,
            this,          &Game::close);

}
void Game::disconnectAllTiles(){
    for(int i : iter::range(8))
    for(int j : iter::range(8)){
        Tile* temp= chessBoard_->getTile(Position(i,j));
        temp->disconnect();
        connect(temp, &Tile::clicked,
                temp, &Tile::onTileClick);
    }
}


void Game::switchTurn(){
    isPlayerWhite_ = !isPlayerWhite_;
    if(isPlayerWhite_)
        std::cout << "White turn" <<std::endl;
    else
        std::cout << "Black turn" << std::endl;

}

void Game::setFromLine(QString line){
    QStringList listeArgs = line.split(' ');
    PieceColor color;

    Position position = Position(listeArgs[1][0].digitValue(),listeArgs[1][1].digitValue());

    if(listeArgs[0][0] == 'b')
        color = PieceColor::BLACK;
    else
        color = PieceColor::WHITE;
    if(listeArgs[0][1] == 'k')
        setPiece(std::make_unique<King>(color), position);
    else if (listeArgs[0][1] ==  'q') 
        setPiece(std::make_unique<Queen>(color), position);
    else if (listeArgs[0][1] ==  'r') 
        setPiece(std::make_unique<Rook>(color), position);
    else if (listeArgs[0][1] ==  'b') 
        setPiece(std::make_unique<Bishop>(color), position);
    else if (listeArgs[0][1] ==  'n') 
        setPiece(std::make_unique<Knight>(color), position);
    else if (listeArgs[0][1] ==  'p') 
        setPiece(std::make_unique<Pawn>(color), position);



}


//Slots Definitions
//----------------------------------------------------------------------------------
void Game::onStartClick(){

    //Remove all current piece
    cleanBoard();

    isPlayerWhite_ = true;

    //Set King Piece
    setPiece(std::make_unique<King>(PieceColor::BLACK), Position(4,0));
    setPiece(std::make_unique<King>(PieceColor::WHITE), Position(4,7));

    //Set Queen Piece
    setPiece(std::make_unique<Queen>(PieceColor::BLACK), Position(3,0));
    setPiece(std::make_unique<Queen>(PieceColor::WHITE), Position(3,7));

    //Set Bishop Piece
    setPiece(std::make_unique<Bishop>(PieceColor::BLACK), Position(2,0));
    setPiece(std::make_unique<Bishop>(PieceColor::BLACK), Position(5,0));
    setPiece(std::make_unique<Bishop>(PieceColor::WHITE), Position(2,7));
    setPiece(std::make_unique<Bishop>(PieceColor::WHITE), Position(5,7));

    //Set Knight Piece
    setPiece(std::make_unique<Knight>(PieceColor::BLACK), Position(1,0));
    setPiece(std::make_unique<Knight>(PieceColor::BLACK), Position(6,0));
    setPiece(std::make_unique<Knight>(PieceColor::WHITE), Position(1,7));
    setPiece(std::make_unique<Knight>(PieceColor::WHITE), Position(6,7));

    //Set Rook Piece
    setPiece(std::make_unique<Rook>(PieceColor::BLACK), Position(0,0));
    setPiece(std::make_unique<Rook>(PieceColor::BLACK), Position(7,0));
    setPiece(std::make_unique<Rook>(PieceColor::WHITE), Position(7,7));
    setPiece(std::make_unique<Rook>(PieceColor::WHITE), Position(0,7));

    //set Pawn Piece
    for(int i: iter::range(8)){
        setPiece(std::make_unique<Pawn>(PieceColor::BLACK), Position(i,1));
        setPiece(std::make_unique<Pawn>(PieceColor::WHITE), Position(i,6));
    }
    connectStartMove(); 
}


void Game::onMoveStart(Tile* tile){
    tile->changeColor(TileColor::RED);
    initTile_ = tile;
    isStartingMove_ = true;
    connectEndMove();
}

void Game::onMoveEnd(Tile* tile){
    try{
        cleanColor();
        currentMove_ = Move(initTile_->getPosition(),tile->getPosition());
        verifyMove(currentMove_);
        Check check(this,currentMove_); 
        movePiece(currentMove_);
        initTile_ = nullptr;
        switchTurn();
        connectStartMove();
    }
    catch(InvalidMoveError& e){
        QMessageBox().critical(0, "Error when trying to move a piece", e.what());
        connectStartMove();
    }
}

void Game::onReadClick(){
    cleanBoard();
    QString path = "./position/";
    QFile fileName = QFileDialog::getOpenFileName(this,tr("Select position"), path, tr("Position file (*.pos)"));

    //Credit to https://stackoverflow.com/questions/5444959/read-a-text-file-line-by-line-in-qt
    try{
        if (fileName.open(QIODevice::ReadOnly))
        {
            QTextStream in(&fileName);
            while (!in.atEnd()){
                QString line = in.readLine();
                setFromLine(line);

            }
            fileName.close();
        }
    }
    catch(ExcessivePieceError &e){
        QMessageBox().critical(0, "Error when trying to load a ChessBoard position", e.what());
        cleanBoard();
    }
    connectStartMove();
}



