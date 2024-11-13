// Refer: https://www.youtube.com/watch?v=zQi6QpH2v-Q

#include <bits/stdc++.h>
using namespace std;

/*

Convert array to monotonic space

Y Y Y | N N N N
l             r
+ To find first N

*/

int check(int x){
    return arr[x]>=arr[0];
}


int n;
int arr[1000];

int main() {
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	
	l=0;
	r=n-1;
	ans=0;
	
	while(l<=r){
	    int mid=(l+r)/2;
	    
	    if(check(mid)){
	        l=mid+1;
	    }else{
	        ans=mid;
	        r=mid-1;
	    }
	}
	
	return ans;
}

