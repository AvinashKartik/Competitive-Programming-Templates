#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

struct pt{
    long long x, y;
    pt(){}
    pt(long long _x, long long _y):x(_x), y(_y){}
    pt operator+(const pt & p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt & p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt & p) const { return x * p.y - y * p.x; }
    long long dot(const pt & p) const { return x * p.x + y * p.y; }
    long long cross(const pt & a, const pt & b) const { return (a - *this).cross(b - *this); }
    long long dot(const pt & a, const pt & b) const { return (a - *this).dot(b - *this); }
    long long sqrLen() const { return this->dot(*this); }
};

bool onSegment(pt p, pt q, pt r){ 
	if (r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) && 
		r.y <= max(p.y, q.y) && r.y >= min(p.y, q.y)) 
		return true; 
	return false; 
} 

bool colinear(pt p, pt q, pt r){ 
	long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
	return (val == 0);
}

bool InTriangle(pt a, pt b, pt c, pt point){
    long long s1 = abs(a.cross(b, c));
    long long s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
    return s1 == s2;
}

bool InPolygon(vector<pt> q, vector<pt> p){
	bool ok = 0;
	for(auto it : p){
		for(int i = 0; i < q.size(); i++){
			if(colinear(q[i], q[(i+1)%q.size()], it)){
				ok |= onSegment(q[i], q[(i+1)%q.size()], it);
			}
		}
	}
	if(ok) return 0;
	for(auto it : p){
		for(int i = 1; i < q.size()-1; i++){
			ok |= InTriangle(q[0], q[i], q[i+1], it);
		}
	}
	return ok;
}

int main(){
}