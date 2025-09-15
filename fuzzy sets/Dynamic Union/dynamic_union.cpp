#include <iostream>
#include <cmath>
using namespace std;
float MemberShipFunction1(float X)
{
    if (X <= 160)
    {
        return 0;
    }
    else if (X > 160 && X < 190)
    {
        return ((X - 160) / 30);
    }
    else
    {
        return 1;
    }
    return -1;
}

double MembershipFunction2(float X)
{
    float c = 175; // middle
    float k = -0.1;
    float e = 2.71828;
    double base = e;
    double exponent = k * (X - c);
    double final = 1 / pow(base, exponent);

    return final;
}
int main()
{

    float height1[] = {150, 160, 165, 170, 175, 180, 185, 190, 195, 200};
    float height2[] = {150, 160, 165, 170, 175, 180, 185, 190, 195, 200};

    float final[100][100];

    for (int i = 0; i < 10; i++)
    {
        double first = MemberShipFunction1(height1[i]);
        double second = MembershipFunction2(height2[i]);
        double final_v;
        if (first >= second)
        {
            final_v = first;
        }
        else
        {
            final_v = second;
        }

        final[i][0] = height1[i];
        final[i][1] = final_v;
    }


    for(int i=0;i<10;i++){
        for(int j=0;j<2;j++){
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}