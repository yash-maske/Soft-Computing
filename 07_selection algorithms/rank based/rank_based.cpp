#include <iostream>
#include<vector>
using namespace std;

vector<double> calulate_Rank(vector<double>&fitness){
 

    for(int j=1;j<fitness.size();j++){
        for(int k=j;k>0;k--){
            if(fitness[k]<fitness[k-1]){
                swap(fitness[k],fitness[k-1]);
            }else{
                break;
            }
            
        }
    }


    return fitness;
}

vector<vector<double>> calculate_area(vector<double>rank){
            int size = rank.size();
            int total = (size * (size+1))/2;
            vector<vector<double>>area;
            for(int i=0;i<rank.size();i++){
                double a = (double)(i + 1) / total;
                area.push_back({rank[i],a*100});
            }
            return area;
}

void print_wheel(vector<vector<double>>wheel){
    for(int i=0;i<wheel.size();i++){
        cout<<wheel[i][0]<<" "<<"--->"<<" "<<wheel[i][1]<<"%"<<endl;
    }
}

int main(){
vector<double> fitness = {0.4,0.05,0.03,0.02};
vector<double> rank = calulate_Rank(fitness);

vector<vector<double>>area = calculate_area(rank);
print_wheel(area);
return 0;
}