#include <iostream>;
using namespace std;

int dxma[8] = {-2, -2, -1, 1, 2, 2, 1, -1}; // 8
int dyma[8] = {-1, 1, 2, 2, 1, -1, -2, -2}; // 8

int A[1000][1000];
int ks[2][999000];

int main()
{
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int N, K, M, D;
        cin >> N >> K >> M >> D;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                A[i][j] = 0;
            }
        }
        int x, y;
        // k : 1
        // m : 2
        // d: -1
        for (int i = 0; i < K; i++)
        {
            cin >> x >> y;
            ks[0][i] = x;
            ks[1][i] = y;
            A[x][y] = 1;
        }
        for (int i = 0; i < M; i++)
        {
            cin >> x >> y;
            A[x][y] = 2;
        }
        for (int i = 0; i < D; i++)
        {
            cin >> x >> y;
            A[x][y] = -1;
        }
        int max = 0;
        int tempx, tempy;
        for (int i = 0; i < K; i++)
        {
            int x1 = ks[0][i];
            int y1 = ks[1][i];
            int count = 0;
            for (int j = 0; j < 8; j++)
            {
                int nx = x1 + dxma[j];
                int ny = y1 + dyma[j];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                {
                    continue;
                }
                if (A[nx][ny] > 0)
                {
                    count++;
                }
            }
            if (count > max)
            {
                max = count;
                tempx = x1;
                tempy = y1;
            }
        }

        cout << "#" << tc << " " << tempx << " " << tempy << " " << max << endl;
    }
    return 0;
}