#include <iostream>
long **M;
long C(int k, int n);

int main()
{
    int i = 0, j = 0, t, n, k, m;
    
    std::cin >> t;
    for(i = 0; i < t; i++)
    {
        std::cin >> n >> k >> m;

        M = new long*[n];
        for(i = 0; i < n; i++)
            M[i] = new long[k];
        for(i = 0; i < 100; i++)
            for(j = 0; j < 100; j++)
                M[i][j] = -1;

        std::cout << C(k, n) % m;
        // free
    }
}

long C(int k, int n)
{
    if(0 == k || n == k)
        M[k][n] = 1;
    else if(M[k][n] < 0)
        M[k][n] = C(k-1, n-1) + C(k, n-1);
    return M[k][n];
}