#include <bits/stdc++.h>
using namespace std;
#define N 5005
 
// To store vertices and value of k
int n, k;
 
vector<int> gr[N];
 
// To store number vertices at a level i
int d[N][505];
 
// To store the final answer
int ans = 0;
 
// Function to add an edge between two nodes
void Add_edge(int x, int y)
{
    gr[x].push_back(y);
    gr[y].push_back(x);
}
 
// Function to find the number of distinct
// pairs of the vertices which have a distance
// of exactly k in a tree
void dfs(int v, int par)
{
    // At level zero vertex itself is counted
    d[v][0] = 1;
    for (auto i : gr[v]) {
        if (i != par) {
            dfs(i, v);
 
            // Count the pair of vertices at
            // distance k
            for (int j = 1; j <= k; j++)
                ans += d[i][j - 1] * d[v][k - j];
 
            // For all levels count vertices
            for (int j = 1; j <= k; j++)
                d[v][j] += d[i][j - 1];
        }
    }
}

// Driver code
int main()
{
    n = 5, k = 2;
 
    // Add edges
    Add_edge(1, 2);
    Add_edge(2, 3);
    Add_edge(3, 4);
    Add_edge(2, 5);
 
    // Function call
    dfs(1, 0);
 
    // Required answer
    cout << ans;
 
    return 0;
}