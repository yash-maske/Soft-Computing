#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p1 = {1,0,1,1,0,0,1,0};
    vector<int> p2 = {0,1,0,0,1,1,0,1};
    int n = p1.size();

    vector<int> mask(n);
    for(int i=0; i<n; i++) mask[i] = rand() % 2;

    for(int i=0; i<n; i++)
        if(mask[i]) swap(p1[i], p2[i]);

    cout << "Mask: ";
    for(int m: mask) cout << m;
    cout << "\nChild1: ";
    for(int b: p1) cout << b;
    cout << "\nChild2: ";
    for(int b: p2) cout << b;
}
