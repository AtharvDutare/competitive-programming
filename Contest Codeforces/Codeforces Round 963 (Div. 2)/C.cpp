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
int solve(int mid,vector<ll> &arr,int n,int k){
    int f=0;
        for(int j=0;j<n;j++) {
            int val=mid-arr[j];
            if(((val/k)%2)==1) {
                f=1;
                break;
            }
        }

    return !f;
}
/* clang-format on */
void test_case()
{
    // WRITE CODE HERE
    int n,k;
    cin>>n>>k;
    vll arr(n);
    ll mini=INT_MAX;
    ll maxi=INT_MIN;
    f(i,0,n) {
        cin>>arr[i];
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }

    // // for(int i=0;i<k;i++) {
    // //     int t=maxi+i;
    // //     int f=0;
    // //     for(int j=0;j<n;j++) {
    // //         int val=t-arr[j];
    // //         if(((val/k)%2)==1) {
    // //             f=1;
    // //             break;
    // //         }
    // //     }
    // //     if(f==0) {
    // //         cout<<t<<endl;
    // //         return;
    // //     }
        
    // // }
    // int s=maxi;
    // int e=maxi+k-1;
    // int ans=INT_MAX;
    // while(s<=e) {
    //     int mid=(s+e)/2;
     
    //     bool isP=solve(mid,arr,n,k);
    //     //cout<<mid<<" "<<isP<<endl;
    //     if(isP) {
    //         e=mid-1;
    //         ans=min(mid,ans);
    //     }
    //     else{
    //         s=mid+1;
    //     }
        
        
    // }
    // if(ans!=INT_MAX) {
    //     cout<<ans<<endl;
    // }
    // else{
    //     cout<<-1<<endl;
    // }
    // return;

    ll gap=2*k;
    for(int i=0;i<n;i++) {
        ll inc=(maxi-arr[i])/gap;
        arr[i]+=inc*gap;
        assert(arr[i]<=maxi);
    }
    //sort(all(arr));
    map<ll,ll> mp;
    for(auto &x:arr) {
        mp[x]++;
        mp[x+k]--;
        mp[x+2*k]++;
        mp[x+3*k]--;
    }
    int ans=-1;
    int count=0;
    for(auto &x:mp) {
        ll t=x.first;
        ll change=x.second;
        count+=change;
        if(count==n) {
            cout<<t<<endl;
            return;
        }
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
    int tc;
    cin>>tc;
    while(tc--){
        test_case();
    }
	return 0;
}
