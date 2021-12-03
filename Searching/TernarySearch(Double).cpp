/**
 * Description: Ternary Search for Double values
 * Source: https://www.youtube.com/playlist?list=PL-Jc9J83PIiGiFr2WFAiS9nEssqEoCKC4
 * Problem: https://www.codechef.com/problems/ICM2003
*/


ld b,c;

ld f(ld x){
    return (x*x+b*x+c)/sin(x);
}


void solve(){
    cin>>b>>c;
    ld l,r;
    l=0,r=PI/2.0;
    while(r-l > Eps){  //Instead of while can run for 100-150 iterations
        ld m1=l+(r-l)/3;
        ld m2=r-(r-l)/3;
        if(f(m1)>f(m2))
            l=m1;
        else
            r=m2;
    }
    cout << fixed << setprecision(15) << f(l) << endl;
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
