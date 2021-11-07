#include <iostream>
#include "src/triangle.h"

using namespace std;

int main() {
    cout << triangle("tr1.txt") << endl;
    cout << triangle_rec("tr1.txt") << endl;
    return 0;
}
