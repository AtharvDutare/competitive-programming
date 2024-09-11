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
#define Graph unordered_map<int,vector<int>>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { for (auto x : v) cout << x << " "; cout << endl; }
//void print(vector<T> &v){ for(auto x : v) cout << x <<" "; cout << endl; }

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

int bitLength(int x){ return (int)log2(x)+1;}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/*
            WHITEBOARD



*/
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
        if (!is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}
vector<ll>comp;
/* clang-format on */
void test_case()
{
    // WRITE CODE HERE
    int n;
    cin>>n;
    vi arr(n);
    f(i,0,n) {
        cin>>arr[i];
    }
    unordered_map<int,int> mp;
    int k=comp.size();
    mp[arr[0]]=0;
    for(int i=1;i<n;i++) {
        for(int j=0;j<k;j++) {
            if(mp.find(comp[j]-arr[i])!=mp.end()) {
                cout<<i+1<<" "<<mp[abs(comp[j]-arr[i])]+1<<endl;
                return;
            }
        }
        mp[arr[i]]=i;
    }
    cout<<-1<<endl;
    return;
}
/* Main()  function */
int main()
{

	#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //comp.pb(1);
    comp=sieve(200);
    comp.pb(1);
    //vector<ll> b;
    // b.push_back(1);
    // map<int,bool>mp;
    // for(int i=3;i<=200;i++){
    //     int cnt=0;
    //     for(int j=2;j*j<=i;j++){
    //         if(i%j==0){
    //             cnt++;
    //         }
    //     }
    //     if(cnt>0)b.push_back(i);
    // }
    // cout<<abs(comp.size())<<" "<<b.size()<<endl;
    // for(auto &x:b) {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto &x:comp) {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    int tc;
    cin>>tc;
    while(tc--){
        test_case();
    }
	return 0;
}
