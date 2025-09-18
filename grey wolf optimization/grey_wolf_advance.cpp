#include <iostream>
#include <vector>
#include <random>
#include <cfloat>
#include <cmath>
#include <fstream>
using namespace std;

vector<vector<float>> Initialize_Positions(float Upper_Bound, float Lower_Bound, int Population_Size) {
    vector<vector<float>> Initial_Positions(Population_Size, vector<float>(2));
    random_device rd; mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);

    for (int i = 0; i < Population_Size; i++) {
        float rand1 = dist(gen);
        float rand2 = dist(gen);
        Initial_Positions[i][0] = Lower_Bound + rand1 * (Upper_Bound - Lower_Bound);
        Initial_Positions[i][1] = Lower_Bound + rand2 * (Upper_Bound - Lower_Bound);
    }
    return Initial_Positions;
}

float Mini_Value(vector<float> &Points) {
    return (Points[0] * Points[0]) - (Points[0] * Points[1]) + (Points[1] * Points[1]) + 2 * Points[0] + 4 * Points[1] + 3;
}

vector<float> Minimize_Function(vector<vector<float>> &Positions, int Population_Size) {
    vector<float> Minimized_Values(Population_Size);
    for (int i = 0; i < Population_Size; i++) {
        Minimized_Values[i] = Mini_Value(Positions[i]);
    }
    return Minimized_Values;
}

vector<vector<float>> Best_Values(vector<vector<float>> &Positions, int Population_Size, vector<int> &indices) {
    vector<float> Min = Minimize_Function(Positions, Population_Size);
    vector<vector<float>> Best_Positions(3, vector<float>(2));
    indices = {0, 1, 2};

    for (int i = 0; i < Population_Size; i++) {
        if (Min[i] < Min[indices[0]]) indices[0] = i;
    }
    for (int j = 0; j < Population_Size; j++) {
        if (j != indices[0] && Min[j] < Min[indices[1]]) indices[1] = j;
    }
    for (int k = 0; k < Population_Size; k++) {
        if (k != indices[0] && k != indices[1] && Min[k] < Min[indices[2]]) indices[2] = k;
    }

    Best_Positions[0] = Positions[indices[0]]; // alpha
    Best_Positions[1] = Positions[indices[1]]; // beta
    Best_Positions[2] = Positions[indices[2]]; // delta
    return Best_Positions;
}

float a(int iteration, int max_iteration) {
    return 2 * (1 - (float)iteration / max_iteration);
}

float c() {
    random_device rd; mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);
    return 2 * dist(gen);
}

float A(float a) {
    random_device rd; mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);
    return 2 * (a * dist(gen)) - a;
}

vector<vector<float>> Dabd(vector<vector<float>> &Best_Positions, vector<float> &curr_pos) {
    vector<vector<float>> Dabd(3, vector<float>(2));
    for (int i = 0; i < 3; i++) {
        float C = c();
        Dabd[i][0] = fabs(C * Best_Positions[i][0] - curr_pos[0]);
        Dabd[i][1] = fabs(C * Best_Positions[i][1] - curr_pos[1]);
    }
    return Dabd;
}

vector<float> Xnew(vector<vector<float>> &Best_Positions, vector<vector<float>> &Dabd, float small_a) {
    vector<vector<float>> X123(3, vector<float>(2));
    float Xnew_x1 = 0, Xnew_x2 = 0;

    for (int i = 0; i < 3; i++) {
        float big_A = A(small_a);
        X123[i][0] = Best_Positions[i][0] - big_A * Dabd[i][0];
        X123[i][1] = Best_Positions[i][1] - big_A * Dabd[i][1];

        X123[i][0] = max(-5.0f, min(5.0f, X123[i][0]));
        X123[i][1] = max(-5.0f, min(5.0f, X123[i][1]));

        Xnew_x1 += X123[i][0];
        Xnew_x2 += X123[i][1];
    }
    return {Xnew_x1 / 3, Xnew_x2 / 3};
}

int main() {
    float Upper_Bound = 5, Lower_Bound = -5;
    int Population_Size = 5;
    int max_iteration = 200;
    vector<vector<float>> Positions = Initialize_Positions(Upper_Bound, Lower_Bound, Population_Size);

    ofstream fout("gwo_output.txt");

    for (int iteration = 1; iteration <= max_iteration; iteration++) {
        float small_a = a(iteration, max_iteration);

        vector<int> best_indices;
        vector<vector<float>> Best_Positions = Best_Values(Positions, Population_Size, best_indices);
        vector<float> Minimized_Values = Minimize_Function(Positions, Population_Size);

        // Save positions of all wolves
        for (int k = 0; k < Population_Size; k++) {
            fout << iteration << " " << k << " " 
                 << Positions[k][0] << " " << Positions[k][1] << " " 
                 << Minimized_Values[k] << endl;
        }

        // Save alpha, beta, delta
        fout << "ALPHA " << iteration << " " << best_indices[0] << " "
             << Best_Positions[0][0] << " " << Best_Positions[0][1] << " "
             << Mini_Value(Best_Positions[0]) << endl;
        fout << "BETA " << iteration << " " << best_indices[1] << " "
             << Best_Positions[1][0] << " " << Best_Positions[1][1] << " "
             << Mini_Value(Best_Positions[1]) << endl;
        fout << "DELTA " << iteration << " " << best_indices[2] << " "
             << Best_Positions[2][0] << " " << Best_Positions[2][1] << " "
             << Mini_Value(Best_Positions[2]) << endl;

        // Update positions
        for (int j = 0; j < Population_Size; j++) {
            vector<float> Current_Position = Positions[j];
            vector<vector<float>> Dalpha_beta_delta = Dabd(Best_Positions, Current_Position);
            vector<float> X_NEW = Xnew(Best_Positions, Dalpha_beta_delta, small_a);

            if (Mini_Value(X_NEW) < Mini_Value(Current_Position)) {
                Positions[j] = X_NEW;
            }
        }
    }
    fout.close();
    return 0;
}
