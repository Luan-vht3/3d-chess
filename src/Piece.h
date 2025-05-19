#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>

struct Piece {
    char type = ' ';
    int color = -1; // -1 = none, 0 = white, 1 = black
    int state = 0; // 0 = lying; 1 = selected; 2 = target
    std::vector<int> sliderRayDims = {};
    std::vector<int> hopperSignature = {};

    operator bool() const { return type != ' '; }
};

std::ostream& operator<<(std::ostream& os, const Piece& piece);

#endif // PIECE_H
