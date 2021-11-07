//
// Created by just on 07.11.2021.
//

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
