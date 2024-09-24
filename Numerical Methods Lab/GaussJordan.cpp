#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 100;

vector<vector<double>> PrintMatrix(vector<vector<double>> A, int n){
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n + 1; c++){
            // cout << fixed << setprecision(2) ;
            cout << setw(8) << A[r][c] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return A;
}

vector<vector<double>> gauss_eli(vector<vector<double>> A, int n){
    for(int c = 1; c <= n; c++){
        if(A[c][c] == 0){
            for(int r = 1; r <= n; r++){
                if(A[r][c] != 0){
                    swap(A[c], A[r]);
                    break;
                }
            }
        }
    }
    // PrintMatrix(A, n);
    for(int c = 1; c <= n; c++){
        for(int r = 1; r <= n; r++){
            if(r > c){
                double ratio = A[r][c] / A[c][c];
                for(int k = 1; k <= n + 1; k++){
                    A[r][k] -= (ratio * A[c][k]); 
                }
                // PrintMatrix(A, n);
            }
        }
    }
    return A;
}

vector<vector<double>> jordan_eli(vector<vector<double>> A, int n){
    // PrintMatrix(A, n);
    for(int c = 1; c <= n; c++){
        for(int r = 1; r <= n; r++){
            if(r < c){
                double ratio = A[r][c] / A[c][c];
                for(int k = 1; k <= n + 1; k++){
                    A[r][k] -= (ratio * A[c][k]); 
                }
                // PrintMatrix(A, n);
            }
        }
    }
    return A;
}

vector<vector<double>> row_echelon(vector<vector<double>> A, int n){
    for(int r = 1; r <= n; r++){
        double divisor = A[r][r];
        for(int c = 1; c <= n + 1; c++){
            A[r][c] /= divisor;
        }
    }
    return A;
}

vector <double> Solve(vector<vector<double>> A, int n){
    vector <double> x(n+1);
    for(int i = n; i >= 1; i--){
        x[i] = A[i][n+1];
        for(int j = i + 1; j <= n; j++){
            x[i] -= (A[i][j] * x[j]);
        }
    }
    return x;
}


void GaussJordanElimination()
{
    vector<vector<double>> A1(N,vector<double>(N)), A2(N,vector<double>(N)), A3(N,vector<double>(N)), Result(N,vector<double>(N));
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n + 1; j++){
            cin >> A1[i][j];
        }
    }
    A2 = gauss_eli(A1, n);
    A3 = jordan_eli(A2, n);
    Result = row_echelon(A3, n);

    PrintMatrix(A2, n);
    PrintMatrix(A3, n);
    PrintMatrix(Result, n);

    vector <double> x = Solve(Result, n);
    for(int i = 1; i <= n; i++){
        cout << "x" << i << " = " << x[i] << "\n";
    }
}

int32_t main() {
    GaussJordanElimination();
    return 0;
}