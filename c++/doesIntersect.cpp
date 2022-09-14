#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x,y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};
bool onSegment(Point p, Point q, Point r){
    if( (q.x <= max(p.x, r.x) && q.y <=max(p.y, r.y) && (q.x >= min(p.x, r.x) && q.y >= min(p.y, r.y)))){
        return true;
    }
    return false;
}
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y)*(r.x-q.x) - (r.y - q.y)*(q.x-p.x);
    if(val == 0){
        return 0;
    }else if(val>0){
        return 1;
    }else{
        return 2;
    }
}
bool doIntersect(Point p1, Point p2, Point q1, Point q2){
    int  o1 = orientation(p1, p2, q1);
    int  o2 = orientation(p1, p2, q2);
    int  o3 = orientation(q1, q2, p1);
    int  o4 = orientation(q1, q2, p2);
    if(o1!=o2 && o3!=o4){
        return true;
    }
    if(o1==0 && onSegment(p1, q1, p2)){
        return true;
    }
    if(o2==0 && onSegment(p1, q2, p2)){
        return true;
    }
    if(o3==0 && onSegment(q1, p1, q2)){
        return true;
    }
    if(o4==0 && onSegment(q1, p2, q2)){
        return true;
    }
    return false;
}
int main() 
{ 
    struct Point p1 = {1, 1}, q1 = {10, 1}; 
    struct Point p2 = {1, 2}, q2 = {10, 2}; 
  
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 
  
    p1 = {10, 0}, q1 = {0, 10}; 
    p2 = {0, 0}, q2 = {10, 10}; 
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 
  
    p1 = {-5, -5}, q1 = {0, 0}; 
    p2 = {1, 1}, q2 = {10, 10}; 
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 
  
    return 0; 
} 