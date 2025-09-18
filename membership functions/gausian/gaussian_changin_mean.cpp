#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


double gaussian(double x, double mean, double sigma) {
    return exp(-0.5 * pow((x - mean) / sigma, 2));
}

int main() {
    ofstream fout("gaussian_mean_5.txt");
    double x = 5, sigma = 2;   
    for (double mean = -2; mean <= 12; mean += 0.5) {
        fout << x << " " << gaussian(x, mean, sigma) << endl;
    }
    fout.close();
    return 0;
}
