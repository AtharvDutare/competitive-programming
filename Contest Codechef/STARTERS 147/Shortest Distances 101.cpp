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
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==0){
	                matrix[i][j]=10001;
	            }
	        }
	    }
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]>=10001){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
// void bfs(unordered_map<int,vector<int>>&adjList,int x,int y){
//     int level=0;
//         queue<int> q;
//         unordered_map<int,int> visited;
//         q.push(x);
//         visited[x]=1;
//         int f=0;
//         while(!q.empty()) {
//             int a=q.size();
//             level++;
//             while(a--) {
//                 int node=q.front();
//                 q.pop();
//                 for(auto &neig:adjList[node]) {
//                     if(visited[neig]==0) {
//                         q.push(neig);
//                         visited[neig]=1;
//                     }
//                     if(neig==y) {
//                         cout<<level<<endl;
//                         return;
//                     }
//                 }

//             }
//         }
//         cout<<-1<<endl;
// }
/* clang-format on */
void test_case()
{
    // WRITE CODE HERE
    int n,m;
    cin>>n>>m;
    vll arr(n);
    f(i,0,n) {
        cin>>arr[i];
    }
    vector<vector<int>> adjList(n,vector<int>(n,0));
    for(int i=1;i<=n;i++) {
        int w=i+arr[i-1];
        for(int j=i+1;j<=w;j++) {
            //cout<<i<<" "<<j<<endl;
            if(i<=n&&j<=n)
            adjList[i-1][j-1]++;
            else {
                cout<<-1<<endl;
                return;
            }
        }
    }
    
    shortest_distance(adjList);
    
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        if(x<=n&&y<=n)
        cout<<adjList[x-1][y-1]<<endl;
        else{
            cout<<-1<<endl;
        }
    }

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
