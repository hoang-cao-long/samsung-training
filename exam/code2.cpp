#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    int m, n, t;
    cin >> m >> n;
    int a[100][100];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 < x2)
        {
            int tmp = a[x1][y1];
            for (int j = x1; j <= x2; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j == x1)
                    {
                        if (k >= y1)
                        {
                            if (k == n - 1)
                            {
                                a[j][k] = a[j + 1][0];
                            }
                            else
                            {
                                a[j][k] = a[j][k + 1];
                            }
                        }
                    }
                    else if (j == x2)
                    {
                        if (k < y2)
                        {
                            a[j][k] = a[j][k + 1];
                        }
                    }
                    else
                    {
                        if (k == n - 1)
                        {
                            a[j][k] = a[j + 1][0];
                        }
                        else
                        {
                            a[j][k] = a[j][k + 1];
                        }
                    }
                }
            }
            a[x2][y2] = tmp;
        }

        if (x1 == x2 && y1 < y2)
        {
            int tmp = a[x1][y1];
            for (int j = y1; j < y2; j++)
            {
                a[x1][j] = a[x1][j + 1];
            }
            a[x2][y2] = tmp;
        }

        if (x1 > x2)
        {
            int tmp = a[x1][y1];
            for (int j = x1; j >= x2; j--)
            {
                for (int k = n - 1; k >= 0; k--)
                {
                    if (j == x1)
                    {
                        if (k <= y1)
                        {
                            if (k == 0)
                            {
                                a[j][k] = a[j - 1][n - 1];
                            }
                            else
                            {
                                a[j][k] = a[j][k - 1];
                            }
                        }
                    }
                    else if (j == x2)
                    {
                        if (k > y2)
                        {
                            a[j][k] = a[j][k - 1];
                        }
                    }
                    else
                    {
                        if (k == 0)
                        {
                            a[j][k] = a[j - 1][n - 1];
                        }
                        else
                        {
                            a[j][k] = a[j][k - 1];
                        }
                    }
                }
            }
            a[x2][y2] = tmp;
        }

        if (x1 == x2 && y1 > y2)
        {
            int tmp = a[x1][y1];
            for (int j = y1; j > y2; j--)
            {
                a[x1][j] = a[x1][j - 1];
            }
            a[x2][y2] = tmp;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
