#ifndef PSEUDOMOVES_H
#define PSEUDOMOVES_H

#include <iostream>
#include <vector>
#include "../Board.h"
#include "../Piece.h"

std::vector<std::vector<int>> sliderMoves(
    Board& board,
    int rayDim,
    const std::vector<int>& square
);

/*
std::vector<std::vector<int>> rookPseudoMoves(Board board, std::vector<int> square);

std::vector<std::vector<int>> bishopPseudoMoves(Board board, std::vector<int> square);

std::vector<std::vector<int>> queenPseudoMoves(Board board, std::vector<int> square);

std::vector<std::vector<int>> knightPseudoMoves(Board board, std::vector<int> square);

std::vector<std::vector<int>> kingPseudoMoves(Board board, std::vector<int> square);

std::vector<std::vector<int>> pawnPseudoMoves(Board board, std::vector<int> square);
*/

#endif // PSEUDOMOVES_H
