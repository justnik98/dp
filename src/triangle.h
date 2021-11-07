//
// Created by just on 07.11.2021.
//

#ifndef DYNAMIC_PROG_TRIANGLE_H
#define DYNAMIC_PROG_TRIANGLE_H

#include <string>

uint32_t triangle(const std::string &filename);

uint32_t triangle_rec(const std::string &filename);

void write_random(const std::string &filename, uint32_t count);

#endif //DYNAMIC_PROG_TRIANGLE_H
