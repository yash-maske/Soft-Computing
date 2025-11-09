#include<vector>
#include <iostream>
using namespace std;
int main(){
vector<int>chromosome = {1,0,0,1,0};
vector<int> i_bits = {0,4};

swap(chromosome[i_bits[0]],chromosome[i_bits[1]]);
for(int i=0;i<chromosome.size();i++){
    cout<<chromosome[i]<<" ";
}
return 0;
}