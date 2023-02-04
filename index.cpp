#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1 . . . n
void printOptimalParens(int s[][100], int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void MatrixChainOrder(int p[], int n)
{
	
    int m[100][100], s[100][100];

    // Initializing the values of m[i][i] as 0.
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // Solving the problem by using the bottom-up approach
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications is " << m[1][n - 1] << endl;

    cout << "Optimal Parenthesization is : ";
    printOptimalParens(s, 1, n-1);
}

int main()
{
    int arr[100];
    int n = 0;

    ifstream file("data.txt");
    while (file >> arr[n])
    {
        n++;
    }
    
    MatrixChainOrder(arr,n);

    return 0;
}



