/******************************************************************************
// Name: Sophia Comp
// Section: 003
// Project: Checkers Game
*******************************************************************************/
#include <iostream>
using namespace std;

struct checkersGame {

    struct TinyCheckers {
        static const int N = 8;
        char board[N][N];

        void init() {
    for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
    board[r][c] = '.';
    if ((r + c) % 2 == 1 && r < 3) board[r][c] = 'o'; // opponent
    if ((r + c) % 2 == 1 && r > 4) board[r][c] = 'x'; // player
    }
    }
    }

    void print() {
    cout << "\n";
    for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
    cout << board[r][c] << ' ';
    }
    cout << "\n";
    }
    }

    bool movePiece(int r1, int c1, int r2, int c2, char p) {
    if (r2 < 0 || r2 >= N || c2 < 0 || c2 >= N) return false;
    if (board[r1][c1] != p || board[r2][c2] != '.') return false;

    int dr = r2 - r1;
    int dc = c2 - c1;

    if (p == 'x' && dr == -1 && abs(dc) == 1) {
    board[r2][c2] = p;
    board[r1][c1] = '.';
    return true;
    }

    if (p == 'o' && dr == 1 && abs(dc) == 1) {
    board[r2][c2] = p;
    board[r1][c1] = '.';
    return true;
    }
    return false;
    }

    bool hasPieces(char p) {
    for (int r = 0; r < N; r++)
    for (int c = 0; c < N; c++)
    if (board[r][c] == p) return true;
    return false;
    }

    bool playGame() {
    init();
    while (true) {
    print();

    int r1, c1, r2, c2;
    cout << "Your move (r1 c1 r2 c2): ";
    cin >> r1 >> c1 >> r2 >> c2;
    if (!movePiece(r1, c1, r2, c2, 'x')) {
    cout << "Invalid move\n";
    continue;
    }

    if (!hasPieces('o')) return true;


    for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
    if (board[r][c] == 'o') {
    if (movePiece(r, c, r + 1, c + 1, 'o') ||
    movePiece(r, c, r + 1, c - 1, 'o')) {
    goto done;
    }
    }
    }
    }
    done:
    if (!hasPieces('x')) return false; // you lose
    }
    }
    };

};