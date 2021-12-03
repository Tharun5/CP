/**
 * Description: Ternary Search for Integers
 * Source: https://www.youtube.com/playlist?list=PL-Jc9J83PIiGiFr2WFAiS9nEssqEoCKC4
 * Problems: 1.https://www.spoj.com/problems/KOPC12A/
             2.https://codeforces.com/problemset/problem/1479/A
*/

// Binary Search Implementation of Ternary Search for Problem 2

ll query(ll i){
    ll val;
    cout<<"? "<<i<<endl;
    cout << flush;
    cin>>val;
    return val;
}
 
void solve(){
    ll n;cin>>n;
    ll l,r;
    l=1,r=n;
    while(l<r){
        ll m1=(l+r)/2;
        ll m2=m1+1;
        if(query(m1)<query(m2)){
            r=m1;
        }else l=m2;
    }
    cout<<"! "<<l<<endl;
 
}


// Ternary Search Implementation for Problem 1

ll n;
vector<ll> h,c;

ll chk(ll m){
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(m-h[i])*c[i];
    }
    return ans;
}

void solve(){
    cin>>n;
    h.resize(n);
    c.resize(n);
    for(int i=0;i<n;i++)cin>>h[i];
    for(int i=0;i<n;i++)cin>>c[i];
    ll l,r;
    l=0;
    r=10000;
    while(l<r){
        ll m1=l+(r-l)/3;
        ll m2=r-(r-l)/3;
        if(chk(m1)<chk(m2)){
            r=m2-1;
        }else if(chk(m1)>chk(m2)){
          l=m1+1;
        }
        else{
            l=m1+1;
            r=m2-1;
        }
    }
    cout<<chk(l)<<endl;

}

int main()
{
    fileio;
    
    int tc;
    cin>>tc;

    while(tc--){
        solve();
    }
}
