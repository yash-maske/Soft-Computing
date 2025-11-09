#include<vector>
#include <iostream>
using namespace std;
int main(){
vector<int>chromosome = {1,0,0,1,0};
vector<int> f_bits = {2,4};

for(int i=0;i<f_bits.size();i++){
    if(chromosome[f_bits[i]]==0){
        chromosome[f_bits[i]] = 1;
    }else{
        chromosome[f_bits[i]] = 0;
    }

}

for(int i=0;i<chromosome.size();i++){
    cout<<chromosome[i]<<" ";
}
return 0;
}