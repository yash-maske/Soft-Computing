#include <iostream>
#include<vector>
using namespace std;

float calulate_F_bar(vector<float>&fitness){
    float sum=0;
    for(int i=0;i<fitness.size();i++){
        sum+=fitness[i];
    }
    float avg = sum/fitness.size();
    return avg;
}

void canonical(vector<float>&fitness,float avg_f){
    vector<float> canonical;
    for(int i=0;i<fitness.size();i++){
        canonical.push_back(fitness[i]/avg_f);
    }
    for(int j=1;j<fitness.size();j++){
        for(int k=j;k>0;k--){
            if(fitness[k]<fitness[k-1]){
                swap(fitness[k],fitness[k-1]);
            }else{
                break;
            }
            
        }
    }
}

void print_canonical(vector<float> & canonical,int Np_no){
    for(int i=canonical.size()-1;i>=canonical.size()-Np_no;i--){
        cout<<canonical[i]<<" ";
    }
}
int main(){

    
vector<float> fitness = {1.01,2.11,3.11,4.01,1.91,1.93,4.51};
float F_bar = calulate_F_bar(fitness);
canonical(fitness,F_bar);
print_canonical(fitness,5);
return 0;
}