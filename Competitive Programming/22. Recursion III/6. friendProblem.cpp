#include<iostream>
using namespace std;

/*
Given N, friends who want to go to a party on bikes, Each guy can go as single, or as a couple.
Find the Number of ways in which N friends can go to the party.
N = 3
ways = 4

similar to last problem.
f(n) = 1.f(n-1) + (n-1)C1.f(n-2);

if(n == 0 || n==1) return 1;

*/