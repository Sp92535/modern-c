#include <stdio.h>
#include <stdbool.h>
#define N 10

void bfs(size_t src, bool graph[N][N]);

int main()
{
    bool graph[N][N] = {
        {true, false, true, true, false, true, false, false, true, true},
        {false, true, true, false, false, true, true, false, false, true},
        {true, true, false, true, false, true, false, true, false, false},
        {false, false, true, true, false, false, true, true, true, false},
        {true, false, false, true, true, false, true, false, true, true},
        {false, true, false, false, true, true, true, false, false, true},
        {true, false, true, true, false, true, false, true, false, true},
        {false, false, true, false, true, true, true, false, true, false},
        {true, true, false, true, false, false, true, false, true, true},
        {false, true, false, false, true, false, true, true, false, true},
    };

    // to find connected component we can refer to union find (challenge 4) so i am skipping it

    // bfs assuming only one connected component
    bfs(0, graph);

    // if no cycle found then it is a spanning tree an undirected graph is preffered in this case
}

void bfs(size_t src, bool graph[N][N])
{

    bool vis[N];
    size_t qu[N], front = 0, rear = 0;

    qu[rear++] = src;
    vis[src] = true;
    printf("[ ");
    while (front < rear)
    {
        size_t qu_size = rear - front;

        for (size_t i = 0; i < qu_size; i++)
        {
            size_t curr = qu[front++];
            printf("%ld ", curr);
            for (size_t j = 0; j < N; j++)
            {
                if (!vis[j] && graph[curr][j])
                {
                    vis[j] = true;
                    qu[rear++] = j;
                }
            }
        }
    }
    printf("]\n");
}
