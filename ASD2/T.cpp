#include <bits/stdc++.h>
using namespace std;

long long p;

long long power(long long n, long long k) {
    if (k == 0)
        return 1;
    if (k == 1)
        return n % p;
    long long result = power(n, k/2);
    result = ((long long)result*result)%p;
    if (k % 2 == 1)
        result = ((long long)result*n)%p;
    return result;
}

long long inverse(long long x) {
    return power(x, p-2);
}

void row_swap(vector<vector<long long>> &matrix, long long i, long long j) {
    swap(matrix[i], matrix[j]);
}

void sub_rows(vector<vector<long long>> &matrix, long long i, long long j, long long x) {
    for (long long k = 0; k < matrix[i].size(); k++) {
        long long temp = ((long long)matrix[j][k] * x) % p;
        if (temp > matrix[i][k])
            matrix[i][k] = p + matrix[i][k] - temp;
        else
            matrix[i][k] = matrix[i][k] - temp;
    }
}

void mul_row(vector<vector<long long>> &matrix, long long i, long long x) {
    for (long long k = 0; k < matrix[i].size(); k++)
        matrix[i][k] = ((long long)matrix[i][k] * x) % p;
}

void gauss(vector<vector<long long>> &matrix, long long n, long long m) {
    long long column = 0, row = 0;
    while (column < m && row < n) {
        for (long long i = row; i < n; i++) {
            if (matrix[i][column] != 0) {
                row_swap(matrix, row, i);
                break;
            }
        }

        if (matrix[row][column] == 0) {
            column++;
            continue;
        }

        // cout << "inv " << inverse(matrix[row][column])  << endl << p << endl;
        mul_row(matrix, row, inverse(matrix[row][column]));
        // cout << matrix[row][column] << endl;
        for (long long i = row + 1; i < n; i++)
            sub_rows(matrix, i, row, matrix[i][column]);
        
        column++;
        row++;
    } 
}

int main() {
    // vector<long long> a(1);
    // a[2] = 1;
    long long z;
    cin >> z;
    while (z--) {
        long long n, m;
        cin >> n >> m >> p;
        // m++;
        vector<vector<long long>> matrix(n);
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j <= m; j++) {
                long long a;
                cin >> a;
                matrix[i].push_back(a);
            }
        }
        // for (long long i = 0; i < n; i++) {
        //     for (long long j = 0; j <= m; j++)
        //         cout << matrix[i][j] << " ";
        //     cout << endl;
        // }
        // cout << "asda\n";
        gauss(matrix, n, m);
        // for (long long i = 0; i < n; i++) {
        //     for (long long j = 0; j <= m; j++)
        //         cout << matrix[i][j] << " ";
        //     cout << endl;
        // }

        vector<long long> result(m);
        long long count = 0;
        bool many = false;
        bool nie = false;

        for (long long row = n-1; row >= 0; row--) {
            long long column = 0;
            while (column < m && matrix[row][column] == 0)
                column++;

            if (column == m) {
                if (matrix[row][m] != 0) {
                    nie = true;
                    break;
                }
                continue;
            }
            
            // cout << row << " " << m << endl;
            result[column] = matrix[row][m];

            for (long long i = column + 1; i < m; i++) {
                long long temp = ((long long)matrix[row][i] * result[i]) % p;
                if (temp > result[column])
                    result[column] = p + result[column] - temp;
                else
                    result[column] = result[column] - temp;    
            }

            count++;
        }

        if (nie) {
            cout << "NIE\n";
            continue;
        }

        if (count < m)
            cout << "WIELE\n";
        else
            cout << "TAK\n";
        for (long long i = 0; i < m; i++)
            cout << result[i] << " ";
        cout << "\n";
    }
}