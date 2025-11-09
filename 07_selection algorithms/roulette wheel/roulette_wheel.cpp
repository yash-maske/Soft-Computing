#include <iostream>
#include<vector>
using namespace std;
vector<float> calculate_pi(vector<float>&fitness){
    float sum=0;
    vector<float>pi;
    for(int i=0;i<fitness.size();i++){
        sum+=fitness[i];
    }
    for(int j=0;j<fitness.size();j++){
        pi.push_back(fitness[j]/sum);
    }
    return pi;
}

vector<float> calculate_Pi(vector<float>&pi){
    vector<float>Pi;
    Pi.push_back(pi[0]);
    for(int i=1;i<pi.size();i++){
        Pi.push_back(Pi[i-1]+pi[i]);
    }
    return Pi;
}

vector<int> roulette_wheel(vector<float>&random,vector<float>&Pi){
    vector<int>tally(Pi.size(),0);
    for(int i=0;i<Pi.size();i++){
        for(int j=1;j<Pi.size()-1;j++){
            if(random[i]>Pi[j-1]&&random[i]<=Pi[j]){
                tally[j] = tally[j] + 1;
                cout<<j<<" ----> "<<Pi[j]<<" Selected.."<<endl;
            }
        }
    }
    return tally;
}

// void print_tally(vector<int>&tally){
//     for(int i=0;i<tally.size();i++){
//         cout<<i<<" "<<"-->"<<" "<<tally[i]<<endl;
//     }
// }

int main(){
vector<float> random = {0.26,0.06,0.48,0.43,0.09,0.30,0.61};
vector<float> fitness = {1.01,2.11,3.11,4.01,1.91,1.93,4.51};
vector<float> pi = calculate_pi(fitness);
vector<float> Pi = calculate_Pi(pi);
vector<int> tally = roulette_wheel(random,Pi);
// print_tally(tally);
for(int i=0;i<Pi.size();i++){
    cout<<Pi[i]<<" "<<endl;
}
return 0;
}