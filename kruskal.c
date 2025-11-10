#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9]; 

// Disjoint Set Union (DSU) functions
int find(int i)
{
    // Find the root (representative) of the set that 'i' belongs to
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{   // Union operation: merge the sets if they are different
    if (i != j)
    {
        parent[j] = i; // Simple union (without rank/size)
        return 1;
    }
    return 0; // Already in the same set (forms a cycle)
}
void main()
{
    clock_t start_time, end_time;
    double execution_time;
    printf("Kruskal's algorithm in C\n");
    printf("Enter the no. of vertices:\n");
    if (scanf("%d", &n) != 1 || n < 2 || n > 8) {
        printf("Invalid number of vertices. Exiting.\n");
        return;
    }
    
    // Initialize parent array for DSU (1-based indexing assumed)
    for (i = 1; i <= n; i++) {
        parent[i] = 0; 
    }

    printf("\nEnter the cost adjacency matrix :\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (scanf("%d", &cost[i][j]) != 1) return; // Basic error check
            // Use a large value (999) to represent no edge/infinity
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    // --- 2. Kruskal's Algorithm Execution with Time Measurement ---
    printf("\nStarting Kruskal's Algorithm...\n");
    
    start_time = clock(); // Start time measurement
    
    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n) // Loop until V-1 edges are added
    {
        // O(V^2) step: Find the minimum cost edge (min) by scanning the matrix
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        
        u = find(u);
        v = find(v);
        
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        
        cost[a][b] = cost[b][a] = 999;
    }
    
    end_time = clock();
    
    printf("\nMinimum cost = %d\n", mincost);
    
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution Time: **%f seconds**\n", execution_time);
}