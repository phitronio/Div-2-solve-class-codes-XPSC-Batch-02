//write a section in prefix sum
# Prefix Sum
## 1D Prefix Sum
Suppose we have an array $A$ of length $n$, and we want to compute the prefix sum of $A$. We can define a new array $B$ of length $n+1$, where $B[i] = \sum_{j=0}^{i} A[j]$ for $i \in [0, n-1]$. Then, $B[i]$ is the prefix sum of $A$ up to index $i$. We can compute $B$ in $O(n)$ time by the following algorithm:
```
B[0] = A[0]
for i = 1 to n-1:
    B[i] = B[i-1] + A[i]
```

Using prefix sum we can answer the following query in $O(1)$ time:
- What is the sum of $A[i:j]$?
To answer this query, we can simply compute $B[j] - B[i-1]$. We have to be careful when $i = 0$.

## 2D Prefix Sum
Suppose we have a 2D array $A$ of size $n \times m$, and we want to compute the prefix sum of $A$. We can define a new array $B$ of size $(n) \times (m)$, where $B[i][j] = \sum_{k=0}^{i} \sum_{l=0}^{j} A[k][l]$ for $i \in [0, n-1]$ and $j \in [0, m-1]$. Then, $B[i][j]$ is the prefix sum of $A$ up to index $(i, j)$. We can compute $B$ in $O(nm)$ time by the following algorithm:
```
for i = 0 to n-1:
    for j = 0 to m-1:
        B[i][j] = A[i][j]
        if i > 0:
            B[i][j] += B[i-1][j]
        if j > 0:
            B[i][j] += B[i][j-1]
        if i > 0 and j > 0:
            B[i][j] -= B[i-1][j-1]
```
Using prefix sum we can answer the following query in $O(1)$ time:
- What is the sum of $A[i_1:i_2][j_1:j_2]$?
To answer this query, we can simply compute $B[i_2][j_2] - B[i_1-1][j_2] - B[i_2][j_1-1] + B[i_1-1][j_1-1]$. We have to be careful when $i_1 = 0$ or $j_1 = 0$.

## Problem
Suppose we are given an array $A$ of length $n$, which is initially all zeros. We are given $q$ updates of the form $(l, r, x)$, which means we have to add $x$ to $A[l:r]$. After all the updates, we want to find the value of $A[i]$ for all $i \in [0, n-1]$. 

To solve this problem in $O(n+q)$ time, we can use prefix sum. We can define a new array $B$ of length $n+1$. When we have an update $(l, r, x)$, we can add $x$ to $B[l]$ and subtract $x$ from $B[r+1]$. After all the queries are processed, we can compute the prefix sum of $B$ to get the final answer.

We can extend this idea to $2D$ arrays too. Consider solving this problem: https://codeforces.com/contest/1864/problem/D