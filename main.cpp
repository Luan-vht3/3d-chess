#include <iostream>
#include <string>
#include <vector>
#include "src/Board.h"
#include "src/Piece.h"
#include "src/Utils.h"
#include "src/logic/pseudoMoves.h"

/*
Board setUp() {
    Board board;
    std::string order = "RNBQKBNR";
    for (int f = 1; f <= 8; f++) {
        board.setPiece({f,8}, Piece{order[f-1], 0});
        board.setPiece({f,7}, Piece{'P', 0});
        board.setPiece({f,2}, Piece{'P', 1});
        board.setPiece({f,1}, Piece{order[f-1], 1});
    }
    return board;
}
*/

void showMoves(Board board, std::vector<int> square, std::vector<std::vector<int>> moves) {
    /*
    Piece piece = board.at(square);
    
    switch (piece.type) {
        case 'K':
            moves = kingPseudoMoves(board, square);
            break;
        case 'Q':
            moves = queenPseudoMoves(board, square);
            break;
        case 'B':
            moves = bishopPseudoMoves(board, square);
            break;
        case 'R':
            moves = rookPseudoMoves(board, square);
            break;
        case 'N':
            moves = knightPseudoMoves(board, square);
            break;
        case 'P':
            moves = pawnPseudoMoves(board, square);
            break;
        default:
            break;
    }
    */
    board.setState(square, 1);
    for (auto m : moves) board.setState(m, 2);

    board.print();
    
    board.setState(square, 0);
    for (auto m : moves) board.setState(m, 0);
    
}

/******************************************************************/

int main() {
    Board b;
    b.setPiece({4, 4}, Piece{'R', 1});
    b.setPiece({4, 5}, Piece{'R', 0});
    b.setPiece({6, 2}, Piece{'K', 1});
    b.setPiece({2, 6}, Piece{'Q', 0});
    b.setPiece({7, 7}, Piece{'B', 0});
    
    
    b.print();
    
    showMoves(b, {4, 4}, sliderMoves(b, 1, {4, 4}));
    
    return 0;
}
