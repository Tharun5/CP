ll MOD=1e9+7;

ll Madd(ll x, ll y) {
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}

ll Msub(ll x, ll y) {
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}

ll Mmult(ll x, ll y) {
    return (x * y) % MOD;
}

ll bin_pow(ll x, ll p) {
    x %= MOD;
    ll res = 1;
    while (p > 0) {
        cout<<p<<endl;
        if (p & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return res;
}

ll Minv(ll x) {
    return bin_pow(x, MOD - 2);
}
