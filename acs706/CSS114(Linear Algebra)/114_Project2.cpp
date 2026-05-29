#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

class MatrixAnalyzer {
private:
    int n; // ขนาดของเมทริกซ์ (2*2 หรือ 3*3)
    vector<vector<double>> A;

    // หาdet matrix 3x3
    double getDeterminant3x3(const vector<vector<double>>& M) {
        return M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) -
               M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]) +
               M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
    }

    vector<double> getEigenvector3x3(double lambda) {
        vector<vector<double>> M = A;
        for (int i = 0; i < 3; i++) M[i][i] -= lambda;
        vector<double> v = {
            M[0][1] * M[1][2] - M[0][2] * M[1][1],
            M[0][2] * M[1][0] - M[0][0] * M[1][2],
            M[0][0] * M[1][1] - M[0][1] * M[1][0]
        };
        double norm = v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
        if (norm < 1e-6) {
            v = {
                M[1][1] * M[2][2] - M[1][2] * M[2][1],
                M[1][2] * M[2][0] - M[1][0] * M[2][2],
                M[1][0] * M[2][1] - M[1][1] * M[2][0]
            };
        }
        return v;
    }

    void solve2x2() {
        double trace = A[0][0] + A[1][1];
        double det = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
        double discriminant = (trace * trace) - (4 * det);

        if (discriminant < 0) {
            cout << "1. Eigen values: Complex numbers\n3. Diagonal matrix: No\n5. Reason: Eigenvalues are not real numbers\n";
            return;
        }

        double lambda1 = (trace + sqrt(discriminant)) / 2.0;
        double lambda2 = (trace - sqrt(discriminant)) / 2.0;
        cout << "1. Eigen values:\n   lambda1 = " << lambda1 << "\n   lambda2 = " << lambda2 << "\n\n";

        auto get_v = [&](double lambda, double& vx, double& vy) {
            if (A[0][1] != 0) { vx = 1.0; vy = -(A[0][0] - lambda) / A[0][1]; }
            else if (A[1][0] != 0) { vy = 1.0; vx = -(A[1][1] - lambda) / A[1][0]; }
            else { vx = 1.0; vy = 0.0; }
        };

        double v1x, v1y, v2x, v2y;
        get_v(lambda1, v1x, v1y);
        get_v(lambda2, v2x, v2y);
        cout << "2. Eigen vectors:\n   v1 = [" << v1x << ", " << v1y << "]^T\n   v2 = [" << v2x << ", " << v2y << "]^T\n\n";

        if (discriminant == 0 && (A[0][1] != 0 || A[1][0] != 0)) {
            cout << "3. Diagonal matrix: No\n5. Reason: Defective matrix (Not enough independent eigenvectors)\n";
            return;
        }

        cout << "3. Diagonal matrix: Yes\n\n4. D = P^-1 * A * P\n";
        double detP = (v1x * v2y) - (v2x * v1y);
        cout << "   [Matrix P]\n   [ " << v1x << "  " << v2x << " ]\n   [ " << v1y << "  " << v2y << " ]\n\n";
        cout << "   [Matrix P^-1]\n   [ " << v2y/detP << "  " << -v2x/detP << " ]\n   [ " << -v1y/detP << "  " << v1x/detP << " ]\n\n";
        cout << "   [Matrix D]\n   [ " << lambda1 << "  0 ]\n   [ 0  " << lambda2 << " ]\n";
    }

    void solve3x3() {
        double trace = A[0][0] + A[1][1] + A[2][2];
        double a = -trace;
        double b = (A[0][0]*A[1][1] - A[0][1]*A[1][0]) + 
                   (A[0][0]*A[2][2] - A[0][2]*A[2][0]) + 
                   (A[1][1]*A[2][2] - A[1][2]*A[2][1]);
        double c = -getDeterminant3x3(A);

        double Q = (3 * b - a * a) / 9.0;
        double R = (9 * a * b - 27 * c - 2 * a * a * a) / 54.0;
        double D = Q * Q * Q + R * R;

        if (D > 1e-6) {
            cout << "1. Eigen values: Complex numbers exist\n3. Diagonal matrix: No\n5. Reason: Not all eigenvalues are real\n";
            return;
        }

        double theta = acos(R / sqrt(-Q * Q * Q));
        double lambda1 = 2 * sqrt(-Q) * cos(theta / 3.0) - a / 3.0;
        double lambda2 = 2 * sqrt(-Q) * cos((theta + 2 * M_PI) / 3.0) - a / 3.0;
        double lambda3 = 2 * sqrt(-Q) * cos((theta + 4 * M_PI) / 3.0) - a / 3.0;

        cout << "1. Eigen values:\n   lambda1 = " << lambda1 << "\n   lambda2 = " << lambda2 << "\n   lambda3 = " << lambda3 << "\n\n";

        vector<double> v1 = getEigenvector3x3(lambda1);
        vector<double> v2 = getEigenvector3x3(lambda2);
        vector<double> v3 = getEigenvector3x3(lambda3);

        cout << "2. Eigen vectors:\n";
        cout << "   v1 = [" << v1[0] << ", " << v1[1] << ", " << v1[2] << "]^T\n";
        cout << "   v2 = [" << v2[0] << ", " << v2[1] << ", " << v2[2] << "]^T\n";
        cout << "   v3 = [" << v3[0] << ", " << v3[1] << ", " << v3[2] << "]^T\n\n";

        cout << "3. Diagonal matrix: Yes\n\n4. D = P^-1 * A * P\n";
        cout << "   [Matrix P (Eigenvector Matrix)]\n";
        cout << "   [ " << v1[0] << "  " << v2[0] << "  " << v3[0] << " ]\n";
        cout << "   [ " << v1[1] << "  " << v2[1] << "  " << v3[1] << " ]\n";
        cout << "   [ " << v1[2] << "  " << v2[2] << "  " << v3[2] << " ]\n\n";
        
        cout << "   [Matrix D (Diagonal Matrix)]\n";
        cout << "   [ " << lambda1 << "  0  0 ]\n";
        cout << "   [ 0  " << lambda2 << "  0 ]\n";
        cout << "   [ 0  0  " << lambda3 << " ]\n";
    }

public:
    // Constructor 
    MatrixAnalyzer(const vector<vector<double>>& matrixData) {
        A = matrixData;
        n = A.size();
    }

    void printMatrix() {
        cout << "--- Initial Matrix " << n << "x" << n << " ---\n";
        for (int i = 0; i < n; i++) {
            cout << "[ ";
            for (int j = 0; j < n; j++) cout << setw(5) << A[i][j] << " ";
            cout << "]\n";
        }
        cout << "\n";
    }

    void analyze() {
        if (n == 2) solve2x2();
        else if (n == 3) solve3x3();
        else cout << "Error: Only 2x2 and 3x3 matrices are supported.\n";
        cout << "------------------------------------------\n\n";
    }
};

int main() {
    /*vector<vector<double>> data2x2 = {
        {3, 0}, 
        {8, -1}
    };
    MatrixAnalyzer m2(data2x2);
    m2.printMatrix();
    m2.analyze();*/

    vector<vector<double>> data3x3 = {
        {1, 1, -2}, 
        {4, 0, 4},
        {1, -1, 4}
    };
    MatrixAnalyzer m3(data3x3);
    m3.printMatrix();
    m3.analyze();

    return 0;
}