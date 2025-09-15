#include <iostream>
using namespace std;
int main(){
float A[4][2] = {{2,1},{4,0.3},{6,0.5},{8,0.2}};
// float B[4][2] = {{2,0.5},{4,0.4},{6,0.1},{8,1}};

float Compliment[4][2];

for(int i =0;i<4;i++){
    
        Compliment[i][0] = (A[i][0]);
        Compliment[i][1] = 1 - (A[i][1]);

}

for(int i=0;i<4;i++){
    cout<<"{ ";
    for(int j=0;j<2;j++){
         cout<<Compliment[i][j]<<"  ";
    }
    
    cout<<"}  ";
   
}
return 0;
}