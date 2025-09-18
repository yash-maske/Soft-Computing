#include <iostream>
#include <fstream>
using namespace std;


double trapezoidal(double x, double a, double b, double c, double d) {
    if (x <= a || x >= d) return 0.0;
    else if (x >= b && x <= c) return 1.0;
    else if (x > a && x < b) return (x - a) / (b - a);
    else return (d - x) / (d - c);
}

int main() {
    ofstream fout("trapezoidal_d_12.txt");
    double a = 0, b = 3, c = 7, d = 12; 
    for (double x = -2; x <= 12; x += 0.5) {
        fout << x << " " << trapezoidal(x, a, b, c, d) << endl;
    }
    fout.close();
    return 0;
}
