#include <iostream>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n);
void printfun(int visited[], int n, int processSize[]);
int main()
{
    int m;
    int n;
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, m, processSize, n);

    return 0;
}

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = -1;
    }

    for (int j = 0; j < n; j++)
    {
        int mini = INT32_MAX;
        for (int i = 0; i < m; i++)
        {
            if (blockSize[i] >= processSize[j])
            {
                if (mini > blockSize[i])
                {
                    mini = blockSize[i];
                    visited[j] = i;
                }
            }
        }
        if (mini != INT32_MAX)
        {
            blockSize[visited[j]] -= processSize[j];
        }
    }
    printfun(visited, n, processSize);
}

void printfun(int visited[], int n, int processSize[])
{
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {

        if (visited[i] == -1)
        {
            cout << i + 1 << "\t\t" << processSize[i] << "\t\t"
                 << "Not allocated\n";
        }
        else
            cout << i + 1 << "\t\t" << processSize[i] << "\t\t" << visited[i] + 1 << "\n";
    }
}
