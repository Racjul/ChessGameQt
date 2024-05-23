#pragma once
#include<QColor>
enum class PieceColor{
    BLACK,
    WHITE,
};

enum class TileColor{
    BLACK,
    WHITE,
    RED,
    BLUE
};

namespace Color
{
constexpr QColor QButton = QColor(139,186,87);
constexpr QColor QBackground = QColor(48,46,43);
constexpr QColor QWhite = QColor(235,236,208);
constexpr QColor QBlack = QColor(119,149,86);
constexpr QColor QRed  = QColor(255,0,0);
constexpr QColor QBlue = QColor(0,0,255);
}
