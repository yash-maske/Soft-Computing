#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p1 = {1,0,1,1,0,0,1,0};
    vector<int> p2 = {0,1,0,0,1,1,0,1};
    int n = p1.size();

    vector<int> points = {2,4,6}; 
    bool flip = false, last = 0;
    for(int c: points){
        if(flip)
            for(int i = last; i < c; i++) swap(p1[i], p2[i]);
        flip = !flip;
        last = c;
    }
    if(flip) for(int i = last; i < n; i++) swap(p1[i], p2[i]);

    cout << "Child1: ";
    for(int b: p1) cout << b;
    cout << "\nChild2: ";
    for(int b: p2) cout << b;
}
