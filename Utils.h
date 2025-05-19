#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::string ansi(int red, int green, int blue);

bool isInside(int file, int rank);
bool isInside(const std::vector<int>& point);

std::vector<int> addVec(const std::vector<int>& a, const std::vector<int>& b);
std::vector<int> mulVec(const std::vector<int>& v, int scalar);
void printVec(const std::vector<int>& vec);

void generateTuples(
    int D,
    std::vector<int>& current,
    std::map<int, std::vector<std::vector<int>>>& groups
);

std::map<int, std::vector<std::vector<int>>> groupByAbsSum(int D);


const std::string WHITE = ansi(128, 174, 255);
const std::string BLACK = ansi(252, 78, 99);
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string ITALIC = "\033[3m";

const std::string FILES  = "    a   b   c   d   e   f   g   h    ";
const std::string SELIF  = "    h   g   f   e   d   c   b   a    ";
const std::string TOP    = "  ┌───┬───┬───┬───┬───┬───┬───┬───┐  ";
const std::string MIDDLE = "  ├───┼───┼───┼───┼───┼───┼───┼───┤  ";
const std::string BOTTOM = "  └───┴───┴───┴───┴───┴───┴───┴───┘  ";
const std::string BAR    = "│";

const std::vector<std::pair<int, int>> ELLDIRS = {
    {+1, +2}, {+2, +1}, {+2, -1}, {+1, -2},
    {-1, -2}, {-2, -1}, {-2, +1}, {-1, +2},
};

#endif // UTILS_H
