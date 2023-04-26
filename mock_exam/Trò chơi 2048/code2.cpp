#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int n, a[1000];
        cin >> n;
        for (int i = n - 1; i >= 0; i--)
        {
            cin >> a[i];
        }
        int flag = 0;

        while (n > 1 && flag == 0)
        {
            flag = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i] == a[i + 1])
                {
                    a[i] = a[i] * 2;
                    // don mang
                    for (int j = i + 1; j < n - 1; j++)
                    {
                        a[j] = a[j + 1];
                    }
                    n--;
                    flag = 0;
                }
            }
        }

        cout << "#" << tc << " " << a[0] << endl;
    }
    return 0;
}