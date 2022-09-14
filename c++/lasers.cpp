#include<bits/stdc++.h>
using namespace std;

struct Point 
{ 
    int x; 
    int y; 
}; 
  
// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(long x1, long x2, long y, long x3, long x4, long y3, long y4) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    if( (x2==x3 && y==y3) || (x1==x4 && y==y4) ){
            return false;
    }
    Point p1, p2, q1, q2;
    p1.x = x1;
    p2.x = x2;
    q1.x = x3;
    q2.x = x4;
    p1.y = y;
    p2.y = y;
    q1.y = y3;
    q2.y = y4;
    
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

void solve(long *pts, long x1, long x2, long y, long N){
    long count = 0;
    for(long i = 1; i<N; i++){
        if(doIntersect(x1, x2, y, i, i+1, pts[i], pts[i+1])){
            count++;
        }
    }
    cout<<count<<endl;
}

int main() {
    int T;
    long N, Q;
    cin>>T;
    while (T--)
    {
        cin>>N>>Q;
        long *pts = new long[N+1];
        long x1, x2, y;
        for(long i = 1; i<=N; i++){
            cin>>pts[i];
        }
        while (Q--)
        {
            cin>>x1>>x2>>y;
            solve(pts, x1, x2, y, N);
        }
        delete []pts;
    }
    return 0;
}