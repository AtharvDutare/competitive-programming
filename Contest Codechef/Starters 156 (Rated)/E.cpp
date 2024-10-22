

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
#define f(i,s,e) or(long long int i=s;i<e;i++)
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
int findComplement(int num) { int t=bitLength(num); unsigned int mask=(1U<<t)-1; return num^mask;}

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/*
            WHITEBOARD



*/
/* clang-format on */
vll solve(vll arr,ll midIndex,ll mid,int k) {
    int n=arr.size();
    vll ans(n);
    arr[midIndex]=mid;
        ans[midIndex]=mid;
        for(int i=midIndex+1;i<n;i++) {
            int cha=arr[i];
            if(arr[i]-arr[i-1]>k) {
                cha=arr[i-1]+k;
            }
            arr[i]=cha;
            ans[i]=cha;
        }
        for(int i=midIndex-1;i>-1;i--) {
            int cha=arr[i];
            if(arr[i+1]-arr[i]>k) {
                cha=arr[i+1]-k;
            }
            arr[i]=cha;
            ans[i]=cha;
        }
        return ans;
}
vll solve2(vll arr,ll midIndex,ll mid,int k) {
    int n=arr.size();
    vll ans(n);
    arr[midIndex]=mid;
    ans[midIndex]=mid;
        for(int i=midIndex+1;i<n;i++) {
            int cha=arr[i];
            cha=arr[i-1]+k;
            arr[i]=cha;
            ans[i]=cha;
        }
        for(int i=midIndex-1;i>-1;i--) {
            int cha=arr[i];
            cha=arr[i+1]-k;
            arr[i]=cha;
            ans[i]=cha;
        }
        return ans;
}
void test_case()
{
    // WRITE CODE HERE
    int n,k;
    cin>>n>>k;
    vll arr(n);
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll minC=0;
    vll ans(n);
    if(n%2==1) {
        int mid=sum/n;
        int midIndex=n/2;
        //ans+=abs(arr[midIndex]-mid);
        vll v1=solve(arr,midIndex,mid,k);
        vll v2=solve2(arr,midIndex,mid,k);
        ll v1s=0;
        ll v2s=0;
        for(int i=0;i<n;i++) {
            v1s=max(v1s,abs(arr[i]-v1[i]));
            v2s=max(v2s,abs(arr[i]-v2[i]));
        }
        if(v1s<v2s) {
            minC=v1s;
            ans=v1;
        }
        else {
            minC=v2s;
            ans=v2;
        }
    }   
    else {
        ll mid=sum/n;
        ll midIndex=n/2;
        ll midIndex2=n/2-1;
        vll v1=solve(arr,midIndex,mid,k);
        vll v2=solve2(arr,midIndex,mid,k);
        // for(int i=0;i<n;i++) {
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++) {
        //     cout<<v2[i]<<" ";
        // }
        ll v1s=0;
        ll v2s=0;
        for(int i=0;i<n;i++) {
            v1s=max(v1s,abs(arr[i]-v1[i]));
            v2s=max(v2s,abs(arr[i]-v2[i]));
        }
        vll v3=solve(arr,midIndex2,mid,k);
        vll v4=solve2(arr,midIndex2,mid,k);
        ll v3s=0;
        ll v4s=0;
        for(int i=0;i<n;i++) {
            v3s=max(v3s,abs(arr[i]-v3[i]));
            v4s=max(v4s,abs(arr[i]-v4[i]));
        }
        int tempAns=min(v1s,min(v2s,min(v3s,v4s)));
        if(tempAns==v1s) {
            ans=v1;
        }
        else if(tempAns==v2s) {
            ans=v2;
        }
        else if(tempAns==v3s) {
            ans=v3;
        }
        else {
            ans=v4;
        }
        minC=tempAns;
    }
    cout<<minC<<endl;
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;



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
