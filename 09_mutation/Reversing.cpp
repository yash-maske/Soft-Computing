#include<vector>
#include <iostream>
using namespace std;
int main(){
vector<int>chromosome = {1,0,0,1,0};
vector<int> r_bits = {1,3};
vector<int> mutated_chromosome;
for(int i=0;i<r_bits[0];i++){
    mutated_chromosome.push_back(chromosome[i]);    
}
for(int j=r_bits[1];j>=r_bits[0];j--){
    mutated_chromosome.push_back(chromosome[j]);
}
for(int k = r_bits[1]+1;k<chromosome.size();k++){
    mutated_chromosome.push_back(chromosome[k]);
}


for(int i=0;i<chromosome.size();i++){
    cout<<mutated_chromosome[i]<<" ";
}
return 0;
}