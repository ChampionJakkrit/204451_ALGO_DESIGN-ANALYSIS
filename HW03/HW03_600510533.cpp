#include <bits/stdc++.h>
using namespace std;

class Point {  
    public: 
    int x, y;  
};  

float dist(Point p1, Point p2) {  
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));  
}

float bruteForce(Point p[], int k) {  
    float min = 10000;  
    for (int i = 0; i < k; ++i)  
        for (int j = i + 1; j < k; j++)  
            if (dist(p[i], p[j]) < min)  
                min = dist(p[i], p[j]);  
    return min;  
} 

float min(float x, float y) { 
    if(x > y)
        return y;
    else 
        return x; 
}
  
int compare_X(const void* n, const void* k) {  
    Point *p1 = (Point *)n, *p2 = (Point *)k;  
    return (p1 -> x - p2 -> x);  
}  
  
int compare_Y(const void* n, const void* k) {  
    Point *p1 = (Point *)n, *p2 = (Point *)k;  
    return (p1 -> y - p2 -> y);  
}  

float closestStrip(Point strip[], int size, float p) {  
    float min = p; 
  
    qsort(strip, size, sizeof(Point), compare_Y);  
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; j++) {
            if (dist(strip[i], strip[j]) < min) {
                min = dist(strip[i], strip[j]);  
            }
        }
    }
  
    return min;  
}  

float mostClose(Point p[], int k) {  
    if (k <= 3)  
        return bruteForce(p, k);  
 
    int mid = k/2;  
    Point midPoint = p[mid]; 

    float dl = mostClose(p, mid);  
    float dr = mostClose(p + mid, k - mid);   
    float d = min(dl, dr); 
  
    Point strip[k];  
    int j = 0;  
    for (int i = 0; i < k; i++)  
        if (abs(p[i].x - midPoint.x) < d)  
            strip[j] = p[i], j++;  
    float minPoint = min(d, closestStrip(strip, j, d)); 
    return minPoint;
}  
    
int main() {  
    int n;
    scanf("%d", &n);
    Point p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i].x;
        cin >> p[i].y;
    }
    qsort(p, n, sizeof(Point), compare_X);
    float closed = mostClose(p, n);
    if (closed >= 10000)
        printf("INFINITY");
    else
        printf("%.4f", closed);
      
    return 0;  
}  