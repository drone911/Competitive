#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

class Jogger
{
public:
    uint startDegree, velocity;
    bool isClockwise;
    Jogger(uint s, v, i) : startDegree(s), velocity(v), isClockwise(i) {}
};
struct Point
{
    int x, y;
};

float distanceBetween(uint radius, uint distance, uint angle1, uint angle2)
{
    Point p1(radius * cos(angle1* PI / 180.0 ), radius * sin(angle1* PI / 180.0 ));
    Point p2(radius * cos(angle2* PI / 180.0 ), radius * sin(angle2* PI / 180.0 ));
    p2.x = p2.x + distance;
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y-p2.y, 2));
}
uint findAngle(uint angle, uint velocity, uint time, bool isClockwise){
    uint result = (velocity*time) % 360;
    if(isClockwise){
        result = (angle-result);
        result = (result+360)%360;
    }else{
        result = (angle + result)%360;
    }
    return result;
}
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint R, D1, D2, D3;
    uint T;

    return 0;
}
