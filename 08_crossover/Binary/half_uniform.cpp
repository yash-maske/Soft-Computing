#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p1 = {1,0,1,1,0,0,1,0};
    vector<int> p2 = {0,1,0,0,1,1,0,1};

    vector<int> diff;
    for(int i=0; i<p1.size(); i++)
        if(p1[i] != p2[i]) diff.push_back(i);

    random_shuffle(diff.begin(), diff.end());
    int swaps = diff.size() / 2;
    for(int i=0; i<swaps; i++)
        swap(p1[diff[i]], p2[diff[i]]);

    cout << "Child1: ";
    for(int b: p1) cout << b;
    cout << "\nChild2: ";
    for(int b: p2) cout << b;
}
