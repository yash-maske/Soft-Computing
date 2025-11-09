#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p1 = {1,0,1,1,0,0,1,0};
    vector<int> p2 = {0,1,0,0,1,1,0,1};

    for(int i = 0; i < p1.size(); i++)
        if(rand() % 2) swap(p1[i], p2[i]);

    cout << "Child1: ";
    for(int b: p1) cout << b;
    cout << "\nChild2: ";
    for(int b: p2) cout << b;
}
