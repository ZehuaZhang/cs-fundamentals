// 310. Minimum Height Trees
// Difficulty : Medium 

// For a undirected graph with tree characteristics, we can choose any node as the root. 
// The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
// Given such a graph, write a function to find all the MHTs and return a list of their root labels.

// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Example 1:

// Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

//         0
//         |
//         1
//        / \
//       2   3
// return [1]

// Example 2:

// Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5
// return [3, 4]

// Hint:
// How many MHTs can a graph have at most?

// Note:
// (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph 
// in which any two vertices are connected by exactly one path. 
// In other words, any connected graph without simple cycles is a tree.”

// (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

// Credits:
// Special thanks to @peisi for adding this problem and creating all test cases.

// Update (2015-11-25):
// The function signature had been updated to return List<Integer> instead of integer[]. 
// Please click the reload button above the code editor to reload the newest default code definition.

// Time:  O(n)
// Space: O(n)

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
    if (n == 1) {
      return {0};
    }
    vector<int> outDegree(n, 0);
    vector<vector<int>> graph(n, vector<int>());
    for (auto edge : edges) {
      graph[edge.first].push_back(edge.second);
      ++outDegree[edge.first];
      graph[edge.second].push_back(edge.first);
      ++outDegree[edge.second];
    }
    
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (outDegree[i] == 1) {
        q.push(i);
      }
    }
    while (n > 2) {
      int size = q.size();
      while (size--) {
        int node = q.front(); q.pop();
        --n;
        for (int nbr : graph[node]) {
          if (--outDegree[nbr] == 1) {
            q.push(nbr);
          }
        }
      }
    }
    vector<int> result;
    while (!q.empty()) {
      result.push_back(q.front()); q.pop();
    }
    return result;
  }
};