#include <iostream>
#include <map>
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
    float c = 175; // middle point
    float k = -0.1;
    double exponent = k * (X - c);
    return 1.0 / pow(2.71828, exponent);
}

int main()
{

    float height1[] = {150, 160, 165, 170, 175, 180};
    float height2[] = {155, 160, 170, 175, 185, 190};

    map<float, double> set1;
    map<float, double> set2;
    map<float, double> finalSet;


    for (float h : height1)
    {
        set1[h] = MemberShipFunction1(h);
    }


    for (float h : height2)
    {
        set2[h] = MembershipFunction2(h);
    }


    for (auto &p : set1)
    {
        float h = p.first;
        double v1 = p.second;
        double v2 = (set2.find(h) != set2.end()) ? set2[h] : 0; // if not present, take 0
        finalSet[h] = max(v1, v2);
    }


    for (auto &p : set2)
    {
        float h = p.first;
        if (finalSet.find(h) == finalSet.end())
        {
            finalSet[h] = p.second; 
        }
    }

    cout << "Height -> Final Membership" << endl;
    for (auto &p : finalSet)
    {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}
