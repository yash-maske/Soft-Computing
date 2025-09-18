#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


double sigmoid(double x, double a, double c) {
    return 1.0 / (1.0 + exp(-a * (x - c)));
}

int main() {
    ofstream fout("sigmoidal_c_7.txt");
    double a = 1, c = 7;   
    for (double x = -2; x <= 12; x += 0.5) {
        fout << x << " " << sigmoid(x, a, c) << endl;
    }
    fout.close();
    return 0;
}
