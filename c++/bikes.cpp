#include<bits/stdc++.h>
using namespace std;

float maxDistance(int n, int fuel){
    float totalDist = 0;
    while (n>0)
    {
        totalDist += fuel/n;
        n--;
    }
    return totalDist;
}
int main() 
{ 
    int n = 3; // number of bikes 
    int fuel = 100; 
    printf("Maximum distance possible with %d bikes is %f", 
            n, maxDistance(n, fuel)); 
    return 0; 
} 