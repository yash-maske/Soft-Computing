#include <iostream>
#include <vector>
#include <random>
#include <cfloat>
#include <cmath>
using namespace std;

vector<vector<float>> Initialize_Positions(float Upper_Bound, float Lower_Bound, int Population_Size)
{
    vector<vector<float>> Initial_Positions(Population_Size, vector<float>(2));

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);

    for (int i = 0; i < Population_Size; i++)
    {
        float rand1 = dist(gen);
        float rand2 = dist(gen);

        Initial_Positions[i][0] = Lower_Bound + rand1 * (Upper_Bound - Lower_Bound);
        Initial_Positions[i][1] = Lower_Bound + rand2 * (Upper_Bound - Lower_Bound);
    }
    return Initial_Positions;
}

float Mini_Value(vector<float> &Points)
{
    float Minimized_Value = (Points[0] * Points[0]) - (Points[0] * Points[1]) + (Points[1] * Points[1]) + 2 * Points[0] + 4 * (Points[1]) + 3;

    return Minimized_Value;
}
vector<float> Minimize_Function(vector<vector<float>> &Postions, int Population_Size)
{
    vector<float> Minimized_Values(Population_Size);
    for (int i = 0; i < Population_Size; i++)
    {
        Minimized_Values[i] = (Postions[i][0] * Postions[i][0]) - (Postions[i][0] * Postions[i][1]) + (Postions[i][1] * Postions[i][1]) + 2 * Postions[i][0] + 4 * (Postions[i][1]) + 3;
    }
    return Minimized_Values;
}

vector<vector<float>> Best_Values(vector<vector<float>> &Positions, int Population_Size)
{
    vector<float> Min = Minimize_Function(Positions, Population_Size);
    vector<vector<float>> Best_Positions(3, vector<float>(2));
    int index_Xa = 0;
    int index_Xb = 0;
    int index_Xd = 0;
    for (int i = 0; i < Population_Size; i++)
    {
        if (Min[i] < Min[index_Xa])
        {
            index_Xa = i;
             index_Xb = i+1;
            index_Xd = i+2;
            
        }
    }

    for (int j = 0; j < Population_Size; j++)
    {
        if (j!= index_Xa && Min[j] < Min[index_Xb])
        {
            index_Xb = j;
             index_Xd = j+1;
        }
    }

    for (int k = 0; k < Population_Size; k++)
    {
        if (k!= index_Xa && k!= index_Xb && Min[k] < Min[index_Xd])
        {
            index_Xd = k;
        }
    }

    Best_Positions[0] = Positions[index_Xa];
    Best_Positions[1] = Positions[index_Xb];
    Best_Positions[2] = Positions[index_Xd];

    return Best_Positions;
}






float a(int iteration, int max_iteration)
{
    return 2 * (1 - (float)iteration / max_iteration);
}

float c()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);
    float random = dist(gen);
    return 2 * random;
}

float A(float a)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);
    float random = dist(gen);
    return 2 * (a * random) - a;
}

vector<vector<float>> Dabd(vector<vector<float>> &Best_Postions, vector<float> &curr_pos)
{
    vector<vector<float>> Dabd(3, vector<float>(2));
    for (int i = 0; i < 3; i++)
    {
        float C = c();
        Dabd[i][0] = fabs(C * Best_Postions[i][0] - curr_pos[0]);
        Dabd[i][1] = fabs(C * Best_Postions[i][1] - curr_pos[1]);
    }
    return Dabd;
}

vector<float> Xnew(vector<vector<float>> &Best_Postions, vector<vector<float>> &Dabd, float small_a)
{
    vector<vector<float>> X123(3, vector<float>(2));
    float Xnew_x1 = 0;
    float Xnew_x2 = 0;
    for (int i = 0; i < 3; i++)
    {
        float big_A = A(small_a);
        X123[i][0] = Best_Postions[i][0] - big_A * Dabd[i][0];
        if (X123[i][0] < -5)
        {
            X123[i][0] = -5;
        }
        if (X123[i][0] > 5)
        {
            X123[i][0] = 5;
        }
        Xnew_x1 = Xnew_x1 + X123[i][0];

        X123[i][1] = Best_Postions[i][1] - big_A * Dabd[i][1];
        if (X123[i][1] < -5)
        {
            X123[i][1] = -5;
        }
        if (X123[i][1] > 5)
        {
            X123[i][1] = 5;
        }
        Xnew_x2 = Xnew_x2 + X123[i][1];
    }

    float Xnew_avg_x1 = Xnew_x1 / 3;
    float Xnew_avg_x2 = Xnew_x2 / 3;

    return {Xnew_avg_x1, Xnew_avg_x2};
}
int main()
{
    float Upper_Bound = 5;
    float Lower_Bound = -5;
    int Population_Size = 5;
    vector<vector<float>> Postions = Initialize_Positions(Upper_Bound, Lower_Bound, Population_Size);
    for (int i = 1; i <= 200; i++)
    {
        int iteration = i;
        int max_iteration = 200;

        float small_a = a(iteration, max_iteration);

        vector<vector<float>> Best_Positions = Best_Values(Postions, Population_Size);
        vector<float> Minimized_Values = Minimize_Function(Postions, Population_Size);
        cout << "Printing Postions : " << endl;
        for (int k = 0; k < Population_Size; k++)
        {
            cout << Postions[k][0] << " " << Postions[k][1] << endl;
        }
        cout << "Printing Minimized Values : " << endl;
        for (int m = 0; m < Population_Size; m++)
        {
            cout << Minimized_Values[m] << endl;
        }
        for (int j = 0; j < Population_Size; j++)
        {
            vector<float> Current_Position = Postions[j];
            vector<vector<float>> Dalpha_beta_delta = Dabd(Best_Positions, Current_Position);
            vector<float> X_NEW = Xnew(Best_Positions, Dalpha_beta_delta, small_a);

            float fu_value_Xnew = Mini_Value(X_NEW);
            float fu_valu_X = Mini_Value(Current_Position);

            if (fu_value_Xnew < fu_valu_X)
            {
                Postions[j][0] = X_NEW[0];
                Postions[j][1] = X_NEW[1];
            }
        }
    }
}
