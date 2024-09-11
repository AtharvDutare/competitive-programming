vector<ll> primefactor(ll n){
    vector<ll> factor;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            factor.pb(i);
            n/=i;
        }
    }
    if(n>1){
        factor.pb(n);
    }
    return factor;
}