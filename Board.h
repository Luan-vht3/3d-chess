#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.h"
#include "Utils.h"


class Board {
public:
    std::vector<std::vector<Piece>> grid;
    bool turn = 1; // 0 = black, 1 = white
    std::vector<std::vector<bool>> castling = {{1, 1}, {1, 1}}; // {K, Q}
    
    Board();

    Piece at(const std::vector<int> &coords) const;
    void setPiece(std::vector<int> pos, Piece newPiece);
    void setState(std::vector<int> pos, int newState);
    void print(const bool perspective = true) const;

};



#endif // BOARD_H
