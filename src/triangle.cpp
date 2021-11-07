//
// Created by just on 07.11.2021.
//

#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include "triangle.h"

using namespace std;


void read_file(const std::string &filename, vector<vector<uint32_t>> &tr) {
    fstream in(filename);
    string line;
    uint32_t size = 1;
    while (!in.eof()) {
        auto tmp = vector<uint32_t>(size);
        auto i = 0;
        while (!in.eof() && i < size) {
            auto k = 0;
            in >> k;
            tmp[i] = k;
            i++;
        }
        size++;
        tr.push_back(tmp);
    }
}

uint32_t triangle(const std::string &filename) {
    vector<vector<uint32_t>> tr;
    read_file(filename, tr);
    for (int i = tr.size() - 2; i >= 0; --i) {
        for (auto j = 0; j < tr[i].size(); ++j) {
            tr[i][j] += tr[i + 1][j] > tr[i + 1][j + 1] ? tr[i + 1][j] : tr[i + 1][j + 1];
        }
    }
    return tr[0][0];
}

uint32_t find_rec(vector<vector<uint32_t>> &tr, uint32_t row = 0, uint32_t col = 0, uint32_t total = 0) {
    if (row == tr.size() - 1) {
        return total + tr[row][col];
    }
    return max(find_rec(tr, row + 1, col, total + tr[row][col]), find_rec(tr, row + 1, col + 1, total + tr[row][col]));
}

uint32_t triangle_rec(const string &filename) {
    vector<vector<uint32_t>> tr;
    read_file(filename, tr);
    return find_rec(tr);
}

void write_random(const string &filename, uint32_t count) {
    ofstream out;
    srand(time(nullptr));
    out.open(filename, ofstream::out | ofstream::trunc);
    auto size = 1;
    for (auto i = 0; i < count; ++i) {
        for (auto j = 0; j < i + 1; ++j) {
            auto k = rand() % 255;
            out << k << ' ';
        }
        out << '\n';
    }
}
