#include <iostream>
#include <vector>
#include <algorithm>
#include "pseudoMoves.h"
#include "../Board.h"
#include "../Utils.h"

std::vector<std::vector<int>> sliderMoves(
    Board& board,
    int rayDim,
    const std::vector<int>& square
) {
    const int D = square.size();
    Piece piece = board.at(square);
    std::vector<std::vector<int>> moves;

    auto rays = groupByAbsSum(D);
    auto directions = rays[rayDim];

    for (auto& delta : rays[rayDim]) {
        std::vector<int> pos = square;

        while (true) {
            pos = addVec(pos, delta);
            if (!isInside(pos)) break;

            if (Piece target = board.at(pos)) {
                if (target.color != piece.color) moves.push_back(pos);
                break;
            }
            moves.push_back(pos);
        }
    }

    return moves;
}


/*
vector<vector<int>> rookPseudoMoves(Board board, vector<int> square) {
    int file = square[0], rank = square[1];
    Piece rook = board.at(square);
    vector<vector<int>> moves;
    
    // Scan in each direction
    for (int d = 0; d < 4; ++d) {
        int dx = ORTHDIRS[d].first, dy = ORTHDIRS[d].second;
        int x = file + dx, y = rank + dy;

        while (isInside(x, y)) {
            Piece target = board.at({x, y});
            if (target) {
                if (target.color != rook.color) moves.push_back({x, y});
                break;
            }
            else moves.push_back({x, y});

            x += dx;
            y += dy;
        }
    }

    return moves;
}

vector<vector<int>> bishopPseudoMoves(Board board, vector<int> square) {
    int file = square[0], rank = square[1];
    Piece bishop = board.at({file, rank});
    vector<vector<int>> moves;
    
    // Scan in each direction
    for (int d = 0; d < 4; ++d) {
        int dx = DIAGDIRS[d].first, dy = DIAGDIRS[d].second;
        int x = file + dx, y = rank + dy;

        while (isInside(x, y)) {
            Piece target = board.at({x, y});
            if (target) {
                if (target.color != bishop.color) moves.push_back({x, y});
                break;
            }
            else moves.push_back({x, y});

            x += dx;
            y += dy;
        }
    }

    return moves;
}

vector<vector<int>> queenPseudoMoves(Board board, vector<int> square) {
    vector<vector<int>> rookPart = rookPseudoMoves(board, square);
    vector<vector<int>> bishopPart = bishopPseudoMoves(board, square);

    rookPart.insert(rookPart.end(), bishopPart.begin(), bishopPart.end());
    return rookPart;
}

vector<vector<int>> knightPseudoMoves(Board board, vector<int> square) {
    int file = square[0], rank = square[1];
    Piece knight = board.at({file, rank});
    vector<vector<int>> moves;
    
    for (int d = 0; d < 8; ++d) {
        int dx = ELLDIRS[d].first, dy = ELLDIRS[d].second;
        int x = file + dx, y = rank + dy;

        if (isInside(x, y)) {
            Piece target = board.at({x, y});
            if (target.color != knight.color) moves.push_back({x, y});
        }
    }

    return moves;
}

vector<vector<int>> kingPseudoMoves(Board board, vector<int> square) {
    int file = square[0], rank = square[1];
    Piece king = board.at({file, rank});
    vector<vector<int>> moves;
    
    for (int d = 0; d < 8; ++d) {
        int dx = SHELLDIRS[d].first, dy = SHELLDIRS[d].second;
        int x = file + dx, y = rank + dy;

        if (isInside(x, y)) {
            Piece target = board.at({x, y});
            if (target.color != king.color) moves.push_back({x, y});
        }
    }

    return moves;
}

vector<vector<int>> pawnPseudoMoves(Board board, vector<int> square) {
    int file = square[0], rank = square[1];
    Piece pawn = board.at(square);
    vector<vector<int>> moves;

    int direction = (pawn.color == 1) ? 1 : -1; // white: up; black: down
    int startRank = (pawn.color == 1) ? 2 : 7;

    // One step forward
    int forward = rank + direction;
    if (isInside(file, forward) && !board.at({file, forward})) {
        moves.push_back({file, forward});

        // Two steps forward from starting position
        if (rank == startRank) {
            int twoForward = rank + 2 * direction;
            if (!board.at({file, twoForward})) moves.push_back({file, twoForward});
        }
    }

    // Captures
    for (int d : {-1, 1}) {
        int targetFile = file + d;
        if (isInside(targetFile, forward)) {
            Piece target = board.at({targetFile, forward});
            if (target && target.color != pawn.color) moves.push_back({targetFile, forward});
        }
    }

    return moves;
}
*/
