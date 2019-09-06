#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int MOD = 1e9 + 7;
const LL INF = 1e18;

void fastscan(int &number) { 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c=='-') {  
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
}

/**
* Description: Custom comparator for map / set
* Source: StackOverflow
* Verification: ?
*/
struct cmp {
	bool operator()(const int& l, const int& r) const {
		return l > r;
	}
};
set<int,cmp> s;

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

    return 0;
}