#include <iostream>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int main()
{
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int a[100][100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int res = 0;
        while (true)
        {
            int min = 999999999;
            int tempx, tempy;
            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                {
                    continue;
                }
                if (a[nx][ny] > a[x][y] && a[nx][ny] < min)
                {
                    min = a[nx][ny];
                    tempx = nx;
                    tempy = ny;
                }
            }
            if (min == 999999999)
            {
                break;
            }
            x = tempx;
            y = tempy;
            res++;
        }
        cout << "#" << tc << " " << res << endl;
    }
    return 0;
}