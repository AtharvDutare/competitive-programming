#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return (a*b)/gcd(a,b); }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
vector<ll> sieve(ll lm) {
    //O(NloglogN)
    //assume all are prime
    vector<bool> is_prime(lm + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(ll i=2;i*i<=lm;i+=1) {
        if(is_prime[i]){
            for (ll j=i*i;j<=lm;j+=i) {
                is_prime[j] = false;
            }
        }
    }   
    vector<ll> primes;
    for (ll i=2;i<=lm;i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}
//fast exponanation
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
int bitLength(int x){ return (int)log2(x)+1;}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


/* clang-format on */

/* Main()  function */
int main()
{

	#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        if(n>m){
            cout<<n-m<<endl;
        }
        else if(m%n<=n/2){
            cout<<m%n<<endl;
        }
        else{
            cout<<n-m%n<<endl;
        }
    }
	return 0;
}
//arithmetic mod 
//sum
//(a+b)%mod=(a%mod+b%mod)%mod
//product
//(a*b)%mod=((a%mod)*(b%mod))%mod inner backet is imp
//subtract
//(a-b)%mod=(((a%mod-a%mod)%mod+mod)%mod)
//(((a%mod-b%mod)-c%mod)%mod+mod)%mod
//R=(R+mod)%mod to (-2+5)=3

//modular inverse
//(a/b)%mod=a*inv(b)=((a%mod)*(b^(mod-2))%mod)%mod

//PREFIX SUM
// for(int i=1;i<=m;i++){
//     prefixSum[i]=arr[i]+prefixSum[i-1];
// }
//arr[l..r]=prefix[r]-prefix[l-1] one based indexing 

//2D prefix sum
// for(int i=1;i<=m;i++){
//     for(int j=1;j<=n;j++){
//         prefixSum[i][j]=arr[i][j]+prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1];
//     }
// }
// prefix(a,b)-->(c,d) ans=p[c][d]-p[c][b-1]-p[a-1][d]+p[a-1][b-1];

//~x=-(x+1)
// x 2`s compliment is ~x+1=-x
//~ make all bit opposite (all bit leading zeros)
// 1111=-1=11111111111111111111111111111111(32 1`s)
// 1110=-2
// 1101=-3
// 1011=-4 and goes 

// 1000101<<2=100010100 a<<b=a*(2^b)
// 101010<<4=1010100000
//mid=(s+e)>>1
//a>>b=a/(2^b)
//bitmask is zero based indexing

//compliment of N=~N&((1<<L)-1) L is length of bit and N is bit
// make clear last set bit is (x)&(x-1) or i-(i&-i)
// get bitMask of only having last set bit of x is (x&(-x)) 
