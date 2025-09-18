#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


double gaussian(double x, double mean, double sigma) {
    return exp(-0.5 * pow((x - mean) / sigma, 2));
}

int main() {
    ofstream fout("gaussian_mean_7.txt");
    double mean = 7, sigma = 2;   
    for (double x = -2; x <= 12; x += 0.5) {
        fout << x << " " << gaussian(x, mean, sigma) << endl;
    }
    fout.close();
    return 0;
}
