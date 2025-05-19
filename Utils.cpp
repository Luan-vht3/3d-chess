#include "Utils.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::string ansi(int red, int green, int blue) {
    return "\033[38;2;" +
        std::to_string(red) + ";" +
        std::to_string(green) + ";" +
        std::to_string(blue) + "m";
}

bool isInside(const std::vector<int>& point) {
    return std::all_of(
        point.begin(),
        point.end(),
        [](int i) { return 1 <= i && i <= 8; });
}

bool isInside(int file, int rank) {
    return file >= 1 && file <= 8 && rank >= 1 && rank <= 8;
}

std::vector<int> addVec(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) result[i] = a[i] + b[i];
    return result;
}

std::vector<int> mulVec(const std::vector<int>& v, int scalar) {
    std::vector<int> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) result[i] = v[i] * scalar;
    return result;
}

void printVec(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (int i : vec) std::cout << i << " ";
    std::cout << "]";
}

void generateTuples(
    int D,
    std::vector<int>& current,
    std::map<int, std::vector<std::vector<int>>>& groups
) {
    if (current.size() == D) {
        if (std::all_of(current.begin(), current.end(), [](int x) { return x == 0; })) return;
        int abs_sum = 0;
        for (int x : current) abs_sum += std::abs(x);
        groups[D - abs_sum].push_back(current);
        return;
    }

    for (int i = -1; i <= 1; ++i) {
        current.push_back(i);
        generateTuples(D, current, groups);
        current.pop_back();
    }
}

std::map<int, std::vector<std::vector<int>>> groupByAbsSum(int D) {
    std::map<int, std::vector<std::vector<int>>> groups;
    std::vector<int> current;
    generateTuples(D, current, groups);
    return groups;
}
