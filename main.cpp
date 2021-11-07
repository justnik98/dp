#include <chrono>
#include <iostream>
#include "src/triangle.h"

using namespace std;
using namespace std::chrono;

int main() {
    write_random("tr1.txt", 28);


    auto start_dp = high_resolution_clock::now();
    cout << triangle("tr1.txt");
    auto finish_dp = high_resolution_clock::now();
    cout << " : " << duration_cast<milliseconds>(finish_dp - start_dp).count() << endl;


    auto start_rec = high_resolution_clock::now();
    cout << triangle_rec("tr1.txt");
    auto finish_rec = high_resolution_clock::now();
    cout << " : " << duration_cast<milliseconds>(finish_rec - start_rec).count() << endl;
    return 0;
}
