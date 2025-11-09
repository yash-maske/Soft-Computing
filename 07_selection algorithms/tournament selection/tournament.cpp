#include <iostream>
#include<vector>
#include <random>
using namespace std;
const int Nu = 2;

vector<vector<float>>solution(vector<vector<float>>input,int Np){
        vector<vector<float>> solution;
        for(int i=0;i<Np;i++){
            static random_device rd;
            static mt19937 gen(rd());
            uniform_int_distribution<> dist(0, input.size() - 1);  
            int rand1 = dist(gen);
            int rand2 = dist(gen);
            int select;
            while (rand2 == rand1)
            rand2 = dist(gen);
            
            float first_individual = input[rand1][1];
            float second_individual = input[rand2][1];

            float selected = max(first_individual,second_individual);
            if(selected==input[rand1][1]){
                select = rand1;
            }else{
                select =rand2;
            }
            solution.push_back({float(rand1+1),float(rand2+1),float(select+1)});
    }
        return solution;
}

void print_solution_table(vector<vector<float>>solution){
    
    for(int i=0;i<solution.size();i++){
        cout<<"("<<solution[i][0]<<","<<solution[i][1]<<")"<<"  ----------> "<<solution[i][2]<<endl;
    }
}
int main(){
vector<vector<float>> input = {{1,1.0},{2,2.1},{3,3.1},{4,4.0},{5,4.6},{6,1.9},{7,1.8},{8,4.5}};
vector<vector<float>> output = solution(input,8);
print_solution_table(output);
return 0;
}