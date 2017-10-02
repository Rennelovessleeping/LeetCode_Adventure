/**************************************************************************
 * File Name : EvenTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-09-2017
 *
 * Last Modified : Fri Sep 29 14:02:50 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
// Return the number of nodes of subtree having
// node as a root.
int dfs(vector<int> tree[N], int visit[N], int *ans, int node)
{
    int num = 0, temp = 0;
 
    // Mark node as visited.
    visit[node] = 1;
 
    // Traverse the adjacency list to find non-
    // visited node.
    for (int i = 0; i < tree[node].size(); i++)
    {
        if (visit[tree[node][i]] == 0)
        {
            // Finding number of nodes of the subtree
            // of a subtree.
            temp = dfs(tree, visit, ans, tree[node][i]);
 
            // If nodes are even, increment number of
            // edges to removed.
            // Else leave the node as child of subtree.
            (temp%2)?(num += temp):((*ans)++);
        }
    }
 
    return num+1;
}
 
