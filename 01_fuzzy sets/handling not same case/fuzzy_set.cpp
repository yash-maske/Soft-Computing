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
        return ((X - 160) / 30.0);
    }
    else
    {
        return 1;
    }
}

double MembershipFunction2(float X)
{
    float c = 175; 
    float k = -0.1;
    double exponent = k * (X - c);
    return 1.0 / pow(2.71828, exponent);
}

int main()
{
    
    float height1[] = {150, 160, 165, 170, 175, 180};
    float height2[] = {155, 160, 170, 175, 185, 190};

    int n1 = sizeof(height1) / sizeof(height1[0]);
    int n2 = sizeof(height2) / sizeof(height2[0]);

    float final[100][2]; 
    int index = 0;


    for (int i = 0; i < n1; i++)
    {
        float h = height1[i];
        double mf1 = MemberShipFunction1(h);

      
        double mf2 = 0;
        for (int j = 0; j < n2; j++)
        {
            if (height2[j] == h)
            {
                mf2 = MembershipFunction2(height2[j]);
                break;
            }
        }

        final[index][0] = h;
        final[index][1] = max(mf1, mf2);
        index++;
    }

   
    for (int j = 0; j < n2; j++)
    {
        float h = height2[j];
        bool found = false;

        for (int i = 0; i < n1; i++)
        {
            if (height1[i] == h)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            double mf2 = MembershipFunction2(h);
            final[index][0] = h;
            final[index][1] = mf2;
            index++;
        }
    }

 
    cout << "Height -> Final Membership" << endl;
    for (int i = 0; i < index; i++)
    {
        cout << final[i][0] << " -> " << final[i][1] << endl;
    }

    return 0;
}
