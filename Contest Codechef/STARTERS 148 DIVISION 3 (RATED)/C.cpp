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
/* clang-format on */
ll non(vector<ll> &arr,ll t) {
    ll n=arr.size();
    ll first,last;
    for(ll i=0;i<n;i++) {
        if(arr[i]==t) {
            first=i;
            break;
        }
    }
    ll trav=first;
    last=trav;
    ll comp=t-1==0?3:t-1;
    // while(trav<n&&arr[trav]!=comp) {
    //     if(arr[trav]==t) {
    //         last=trav;
    //     }
    //     trav++;
    // }
    for(ll i=n-1;i>-1;i--) {
        if(arr[i]==t) {
            last=i;
            break;
        }
    }
    for(ll i=first;i<=last;i++) {
        if(arr[i]==comp) {
            return 0;
        }
    }
    ll  mostRight=first,mostLeft=last;
    while(mostRight>-1&&arr[mostRight]!=comp) {
        mostRight--;
    }
    while(mostLeft<n&&arr[mostLeft]!=comp) {
        mostLeft++;
    }
    return (first-mostRight)*(mostLeft-last); 
    
}
void test_case()
{
    // WRITE CODE HERE
    ll n;
    cin>>n;
    vll arr(n);
    //unordered_map<ll,ll>mp;
    f(i,0,n) {
        cin>>arr[i];
        //mp[arr[i]]++;
    }
    // for(ll x:arr) {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto x:mp) {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    ll ans=n*(n+1)/2;
    // for(ll l=0;l<n;l++) {
    //     unordered_map<ll,ll> t=mp;
    //     for(ll r=l;r<n;r++) {
    //         ll temp=(arr[r]);
    //         temp++;
    //         if(temp==4) temp=1;
    //         t[temp]++;
    //         t[arr[r]]--;
    //         if(t[1]>0&&t[2]>0&&t[3]>0) {
    //             ans++;
    //             //cout<<l+1<<" "<<r+1<<endl;
    //         }
    //         //cout<<l<<" "<<r<<" "<<t[1]<<" "<<t[2]<<" "<<t[3]<<endl;
    //     }
    // }
    ll t1=non(arr,1);
    ll t2=non(arr,2);
    ll t3=non(arr,3);
    ans=ans-t1-t2-t3;
    cout<<ans<<endl;


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
    int tc;
    cin>>tc;
    while(tc--){
        test_case();
    }
	return 0;
}
