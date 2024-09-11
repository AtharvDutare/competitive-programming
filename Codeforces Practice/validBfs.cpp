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
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"Yes\n"; }
void no() { cout<<"No\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void bfs(unordered_map<int,vi>& adjList,vi &seq){
    queue<int>q;
    q.push(seq[0]);
    unordered_map<int,bool> visited;
    visited[seq[0]]=true;
    int i=1;
    int n=seq.size();
    //cout<<"atharv"<<endl;
    while(i<n){
        int node=q.front();
        q.pop();
        vi neigbhour=adjList[node];
        int m=neigbhour.size();
        vi notVisitneigbhour;
        for(int t=0;t<m;t++){
            if(!visited[neigbhour[t]]){
                notVisitneigbhour.pb(neigbhour[t]);
            }
        }
        int k=notVisitneigbhour.size();
        
        for(int w=0;w<k;w++){
            if(find(notVisitneigbhour.begin(),notVisitneigbhour.end(),seq[i])==notVisitneigbhour.end()){
                no();
                return;
            }
            else{
                q.push(seq[i]);
                visited[seq[i]]=true;
            }
            i++;
        }
        
    }
    yes();
    return;
}


/* clang-format on */

/* Main()  function */
int main()
{

	#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

	int n;
    cin>>n;
    unordered_map<int,vi> adjList;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        adjList[x].pb(y);
        adjList[y].pb(x);
    }
    vi seq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        seq.pb(x);
    }
    if(n==2){
        bool temp=1;
        int arr[]={2,1};
        for(int i=0;i<2;i++){
            if(arr[i]!=seq[i]){
                temp=0;
            }
        }
        if(temp)
        no();
        else{
            bfs(adjList,seq);
        }
    }
    else
	bfs(adjList,seq);
	return 0;
}