// https://www.spoj.com/problems/SPP/

/*Sequence (ai) of natural numbers is defined as follows:

ai = bi (for i <= k)
ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute am + am+1 + am+2 + ... + an for given m <= n and output it modulo a given positive integer p.

Input
On the first row there is the number C of test cases (equal to about 50).
Each test contains four lines:
k - number of elements of (c) and (b) (1 <= k <= 15)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
m, n, p - natural numbers separated by spaces (1 <= m <= n <= 1018, 1<= p <= 108)
Output
Exactly C lines, one for each test case: (am + am+1 + am+2 + ... + an) modulo p.*/