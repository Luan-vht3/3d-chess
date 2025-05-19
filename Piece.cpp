#include "Piece.h"
#include "Utils.h"
#include <iostream>


std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    std::string color = (piece && piece.color) ? WHITE : BLACK;
    std::string content = BOLD + color + piece.type + RESET;

    switch (piece.state) {
        case 0:
            os << " " << content << " ";
            break;
        case 1:
            os << "[" << content << "]";
            break;
        case 2:
            os << "(" << content << ")";
            break;
        default: break;
    }
    return os;
}
