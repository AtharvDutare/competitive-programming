ll power(int a,int b){
    //log(b)
    if(!b){
        return 1;
    }
    //a%=MOD;
    ll half_power=power(a,b/2);
    if(b%2==0){
        return( half_power*half_power)%MOD;
    }
    return ((half_power*half_power)%MOD*a%MOD)%MOD;
}
int ncr(int n,int r,vi &fact){
    if(r>n||n<0||r<0){
        return 0;
    }
    int nr=fact[n];
    int dr=(fact[r]*fact[n-r])%MOD;
    dr=power(dr,MOD-2);
    //line 80 81 of dr=(invmod[r]*invmod[n-r])%MOD;
    //calculate invmod when calculate fact 
    return (nr*dr)%MOD;
}