#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


double gaussian(double x, double mean, double sigma) {
    return exp(-0.5 * pow((x - mean) / sigma, 2));
}

int main() {
    ofstream fout("gaussian_sigma_6.txt");
    double x = 6, mean = 2;   
    for (double sigma = -2; sigma <= 12; sigma += 0.5) {
        fout << x << " " << gaussian(x, mean, sigma) << endl;
    }
    fout.close();
    return 0;
}
