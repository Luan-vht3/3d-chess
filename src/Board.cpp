#include "Board.h"
#include "Piece.h"
#include "Utils.h"
#include <iostream>

Board::Board() : grid(8, std::vector<Piece>(8)) {}

Piece Board::at(const std::vector<int>& coords) const {
    return grid[8 - coords[1]][coords[0] - 1];
}

void Board::setPiece(std::vector<int> pos, Piece newPiece) {
    grid[8 - pos[1]][pos[0] - 1] = newPiece;
}

void Board::setState(std::vector<int> pos, int newState) {
    Piece p = at(pos);
    p.state = newState;
    setPiece(pos, p);
}

void Board::print(const bool perspective) const {
    std::cout << (turn ? "WHITE" : "BLACK") << " to move ::" << std::endl;
    std::cout << (perspective ? FILES : SELIF) << std::endl;
    std::cout << TOP << std::endl;
    if (perspective) {
        for (int i = 0; i <= 7; i++) {
            std::cout << 8 - i << " " << BAR;
            for (int j = 0; j <= 7; j++) {
                std::cout << at({j + 1, 8 - i}) << BAR;
            }
            std::cout << " " << 8 - i << std::endl;
            std::cout << (i < 7 ? MIDDLE : BOTTOM) << std::endl;
        }
    } else {
        for (int i = 7; i >= 0; i--) {
            std::cout << 8 - i << " " << BAR;
            for (int j = 7; j >= 0; j--) {
                std::cout << at({j + 1, 8 - j}) << BAR;
            }
            std::cout << " " << 8 - i << std::endl;
            std::cout << (i > 0 ? MIDDLE : BOTTOM) << std::endl;
        }
    }
    std::cout << (perspective ? FILES : SELIF) << std::endl;
}
