ll fp(ll a, ll b) {
    ll ans = 1, rem = a;
    while(b > 0) {
        if(ODD(b)) {
            b--;
            ans = ans * rem % MOD;
        } else {
            b /= 2;
            rem = rem * rem % MOD;
        }
    }
    return ans % MOD;
}
