#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include for time measurement

#define INFINITY 9999
#define MAX 10

// Function prototype
void dijkstra(int G[MAX][MAX], int n, int startnode);

int main()
{
    int G[MAX][MAX], i, j, n, u;
    
    printf("--- Dijkstra's Algorithm ---\n");
    
    printf("Enter no. of vertices (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid number of vertices. Exiting.\n");
        return 1;
    }
    
    printf("\nEnter the adjacency matrix (use 0 for no direct edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    
    printf("\nEnter the starting node (0 to %d): ", n - 1);
    if (scanf("%d", &u) != 1 || u < 0 || u >= n) {
        printf("Invalid starting node. Exiting.\n");
        return 1;
    }
    
    // Call the function to run Dijkstra's algorithm
    dijkstra(G, n, u);
    
    return 0;
}

/**
 * Implements Dijkstra's Shortest Path Algorithm.
 * * Time Complexity: O(V^2) because of the two nested loops 
 * used to find the minimum distance node and update distances.
 */
void dijkstra(int G[MAX][MAX], int n, int startnode)
{
    clock_t start_time, end_time;
    double execution_time;
    
    // Start time measurement
    start_time = clock(); 
    
    // Variables used for the algorithm
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    
    // 1. Create the cost matrix: replace 0 (no edge) with INFINITY
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }
    
    // 2. Initialize pred[], distance[] and visited[]
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    
    // 3. Main loop: Repeat n-2 times to find shortest path to n-1 nodes
    while (count < n) // Loop for n iterations (including the start node itself)
    {
        mindistance = INFINITY;
        
        // O(V) step: Find the node with the minimum distance among unvisited nodes
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        
        if (mindistance == INFINITY) break; // All remaining nodes are unreachable
        
        // Mark the selected node as visited
        visited[nextnode] = 1;
        
        // O(V) step: Update the distance of its adjacent unvisited nodes
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        
        count++;
    }
    
    end_time = clock(); // End time measurement
    
    // 4. Print the path and distance of each node
    printf("\n--- Results ---\n");
    for (i = 0; i < n; i++)
        if (i != startnode)
        {
            printf("\nDistance of node %d = %d", i, distance[i]);
            
            // Print path
            printf("\nPath = %d", i);
            j = i;
            do
            {
                j = pred[j];
                printf(" <-%d", j);
            } while (j != startnode);
            printf("\n");
        }

    // Calculate and print execution time
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\n--- Execution Summary ---\n");
    printf("Execution Time for Dijkstra: **%f seconds**\n", execution_time);
}