/*
Minimum Cost To Reach Train Station

There are N stations on route of a train. The train goes from station 0 to N-1.
The ticket cost for all pair of stations (i, j) is given where j is greater than i.
Find the minimum cost to reach the destination.

Consider the following example:

Input:
cost[N][N] = { {0, 15, 80, 90},
              {INF, 0, 40, 50},
              {INF, INF, 0, 70},
              {INF, INF, INF, 0}
             };
There are 4 stations and cost[i][j] indicates cost to reach j
from i. The entries where j < i are meaningless.

Output:
The minimum cost is 65
The minimum cost can be obtained by first going to station 1
from 0. Then from station 1 to station 3.
*/

function minCost(cost: number[][]) {
  const cnt = cost.length;
  const dist = Array(cnt).fill(Infinity);
  dist[0] = 0;

  for (let i = 0; i < cnt; ++i) {
    for (let j = i + 1; j < cnt; ++j) {
      dist[j] = Math.min(dist[j], dist[i] + cost[i][j]);
    }
  }
  return dist[cnt - 1];
}

console.log(
  minCost([
    [0, 15, 80, 90],
    [Infinity, 0, 40, 50],
    [Infinity, Infinity, 0, 70],
    [Infinity, Infinity, Infinity, 0],
  ])
);
