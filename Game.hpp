#pragma once

#include "button/CleanButton.hpp"
#include "button/ExitButton.hpp"
#include "button/ReadButton.hpp"
#include "button/StartButton.hpp"

#include "chessBoard/ChessBoard.hpp"
#include "chessBoard/Position.hpp"
#include "constant/Color.hpp"

#include <memory>
#include <qmessagebox.h>
#pragma warning(push(),0)
#include<QMainWindow>
#include <qboxlayout.h>
#include <qmainwindow.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#pragma pop()


class Game:public QMainWindow{
    Q_OBJECT
    public:
    Game(QWidget* parent=nullptr);
    ~Game() override = default;

    void switchTurn();
    bool isPositionEmpty(const Position pos){return chessBoard_->getTile(pos)->isEmpty();}
    std::unique_ptr<Piece> getPiece(const Position pos){return chessBoard_->getPiece(pos);}
    void setPiece(std::unique_ptr<Piece> piece, Position position);
    PieceColor getCurrentPlayerColor(){if(isPlayerWhite_) return PieceColor::WHITE; else return PieceColor::BLACK;}
    ChessBoard* getChessBoard(){return chessBoard_;}
public slots:
    //Menu button slots
    void onStartClick();
    void onMoveStart(Tile* tile);
    void onMoveEnd(Tile* tile);
    void onCleanClick(){cleanBoard();}
    void onReadClick();

private:
    void movePiece(const Move& move);

    void verifyMove(Move& move);

    void cleanBoard();
    void cleanColor();

    void connectStartMove();
    void connectEndMove();
    void connectMenu();
    void disconnectAllTiles();

    void setFromLine(QString line);

    bool isPlayerWhite_ = true;
    bool isStartingMove_ = true;
    Move currentMove_ = Move();
    Tile* initTile_ = nullptr;

    QWidget* centralWidget_;

    ChessBoard* chessBoard_;

    StartButton* startButton_;
    CleanButton* cleanButton_;
    ReadButton* readButton_;
    ExitButton* exitButton_;

    QVBoxLayout* listButton_;
    QHBoxLayout* horizontalLayout_;
};
