#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p1 = {1,0,1,1,0,0,1,0};
    vector<int> p2 = {0,1,0,0,1,1,0,1};
    int n = p1.size();

    vector<int> index(n);
    iota(index.begin(), index.end(), 0);
    random_shuffle(index.begin(), index.end());

    vector<int> s1(n), s2(n);
    for(int i=0; i<n; i++){
        s1[i] = p1[index[i]];
        s2[i] = p2[index[i]];
    }

    int point = rand() % n;
    for(int i=point; i<n; i++) swap(s1[i], s2[i]);

    vector<int> c1(n), c2(n);
    for(int i=0; i<n; i++){
        c1[index[i]] = s1[i];
        c2[index[i]] = s2[i];
    }

    cout << "Child1: ";
    for(int b: c1) cout << b;
    cout << "\nChild2: ";
    for(int b: c2) cout << b;
}
