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

template <typename T, typename Container = std::deque<T>>
struct DebugStack : private std::stack<T, Container> {
    auto& push(T& elem) {
        std::stack<T>::push(elem);
        return *this;
    }
    auto& push(T&& elem) {
        std::stack<T>::push(elem);
        return *this;
    }
    auto& pop() {
        std::stack<T>::pop();
        return *this;
    }
    T top() {
        return std::stack<T>::top();
    }
    bool empty() {
        return std::stack<T>::empty();
    }
    T size() {
        return std::stack<T>::size();
    }
    void print() {
        auto const& container = std::stack<T>::c;
        //T should be printable
        std::copy(begin(container), end(container), std::ostream_iterator<T>(std::cout, " "));
        std::cout<<'\n';
    }
};
/*
            WHITEBOARD



*/
/* clang-format on */
/*time complexity(1*1+1*2+1*3....+1*n)=O(n^2)*/
void test_case()
{
    // WRITE CODE HERE
    int n;
    cin>>n;
    vi arr(n);
    f(i,0,n) {
        cin>>arr[i];
    }
    DebugStack<int> st;
    for(int i=0;i<n;i++) {
        st.push(0);
        int c=arr[i];
        int t=st.size();
        while(!st.empty()&&c>0) {
            st.pop();
            c--;
        }
        c=arr[i];
        while(c--&&t--){
            st.push(1);
        }
        //st.print();

    }
    vector<int> a;
    while(!st.empty()) {
        a.pb((int)st.top());
        st.pop();
    }
    for(int i=a.size()-1;i>-1;i--) {
        cout<<a[i]<<" ";
    }

}
void solve() {
    int n;
    cin>>n;
    vi arr(n);
    f(i,0,n) {
        cin>>arr[i];
    }
    vi b(n,0);
    int temp=arr[n-1];
    for(int i=n-1;i>-1;i--) {
        temp=max(temp,arr[i]);
        if(temp>0) {
            b[i]=1;
            temp--;
        }
        
    }
    for(int &x:b) {
        cout<<x<<" ";
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
        solve();
        cout<<endl;
    }
	return 0;
}
