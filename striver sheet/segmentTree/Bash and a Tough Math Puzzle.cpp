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

template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<ll> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		//index of query_index in segment tree
		//query_index is index in our array
		if (start == end) {
			u.apply(tree[index]);//update the node(segment tree at index) with new value(from u node)
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
		//after update the leaf node we need to update the node which affect due to change(take log n time)
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void print (){
		cout<<"start"<<endl;
		// for(int i=1;i<s;i++){
		// 	tree[i].printNode();
		// }
		// cout<<endl;
		queue<pair<Node,int>> q;
		q.push({tree[1],1});
		while(!q.empty()){
			int n=q.size();
			while(n--){
				Node node=q.front().first;
				int index=q.front().second;
				q.pop();
				node.printNode();
				int left=2*index;
				int right=2*index+1;
				if(left<s){
					q.push({tree[left],left});
				}
				if(right<s){
					q.push({tree[right],right});
				}
			}
			cout<<endl;
		}
		cout<<"end"<<endl;
	}
	void make_update(int index, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1 {
	ll val; // may change
	// only for safety check
	Node1() { // Identity element
		val = -1;	// may change
	}
	Node1(ll p1) {  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		if(l.val==-1&&r.val==-1){
			val=-1;
		}
		else if(l.val==-1){
			val=r.val;
		}
		else if(r.val==-1){
			val=l.val;
		}
		else
		val = gcd(l.val , r.val);  // may change
	}
	void printNode(){
		cout<<"{"<<val<<"}"<<" ";
	}
};

struct Update1 {
	ll val; // may change
	Update1(ll p1) { // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
	}
};


/*
            WHITEBOARD



*/
/* clang-format on */
void test_case()
{
    // WRITE CODE HERE
    int64 n;
    cin>>n;
    vll arr(n);
    f(i,0,n){
        cin>>arr[i];
    }
    SegTree<Node1,Update1> segmentTree=SegTree<Node1,Update1>(n,arr);
	//segmentTree.print();
    int64 t;
    cin>>t;
	//vector<vector<int64>>input(t,vector<int64>(4))
    while(t--){
        int64 a;
		cin>>a;
		if(a==1){
			int64 l,r,x;
			cin>>l>>r>>x;
			//cout<<a<<" "<<l<<" "<<r<<" "<<x<<endl;
			l--;
			r--;
			bool f=0;
            Node1 node=segmentTree.make_query(l,r);
            if(node.val==x){
				//cout<<"found x without updation"<<endl;
				yes();
                f=1;
            }
            else{
				// for(int64 i=0;i<n;i++){
				// 	segmentTree.make_update(i,x);
				// 	Node1 nodet=segmentTree.make_query(l,r);
				// 	//segmentTree.print();
					
				// 	// if(t==0){
				// 	// 	segmentTree.print();
				// 	// 	cout<<nodet.val<<endl;
				// 	// }
				// 	segmentTree.make_update(i,arr[i]);
				// 	if(nodet.val==x){
				// 		//cout<<"found x with updation at -> "<<i<<endl;
				// 		yes();
				// 		f=1;
				// 		break;
				// 	}
            	// }
				int64 ans=0;
				for(int64 i=l;i<=r;i++){
					if(arr[i]%x!=0){
						ans++;
					}
					if(ans>1){
						break;
					}
				}
				if(ans<=1) yes();
				else no();
			}
		}
		else{
			int64 i,y;
			cin>>i>>y;
			//cout<<a<<" "<<i<<" "<<y<<endl;
			segmentTree.make_update(i-1,y);
			arr[i-1]=y;
			//segmentTree.print();
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
    
        test_case();
    
	return 0;
}
