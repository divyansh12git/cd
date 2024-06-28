#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string.h>
#include<cmath>
#include<limits.h>
#include<algorithm>
#include<time.h>
using namespace std;

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

#define     F                       first
#define     S                       second

#define     INF                     1e18
#define     PI                      3.141592653589793238462

#define     ll                      long long
#define     pii                     pair<int,int>
#define     pll                     pair<ll,ll>
#define     llfl(i,s,e)             for(long long i=s;i<e;i++)
#define     fl(i,s,e)               for(int i=s;i<e;i++)
#define     fa(i,z)                 for(auto i:z)

#define     pb                      push_back
#define     pf                      push_front

#define     vsort(v)                sort(v.begin(),v.end())
#define     vreverse(v)             reverse(v.begin(),v.end())

#define     mapit(it,d1,d2,map)     unordered_map<d1,d2>::iterator it=map.begin()
#define     vecit(it,dt,vec)        vector<dt>:: iterator it=vec.begin();

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

ll gcd(ll a, ll b){ if(a==b)return a;    if(a>b)a-=b;    if(b>a)b-=a;    return gcd(a,b);    }  //m
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

void debug(int t=1) {cout << "Case #" << t << ": ";}
void tres(bool t){ t?cout<<"YES":cout<<"NO";cout<<endl; }

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/

int lcs(string &a,string &b,int x,int y,vector<vector<int>>dp){
    if(x<0 || y<0)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    if(a[x]==b[y]){
        return dp[x][y]=1+lcs(a,b,x-1,y-1,dp);
    }
    return dp[x][y]=0+max(lcs(a,b,x-1,y,dp),lcs(a,b,x,y-1,dp));
}

void solve(){
    //code here...    
    string a,b;
    cin>>a;
    cin>>b;
    map<char,pair<int,vector<int>>>mp;
    fl(i,0,b.length()){
        

        mp[b[i]].first++;
        mp[b[i]].second.pb(i);
        
    }
    // for(auto i:mp){
    //     cout<<i.first<<"->";
    //     cout<<i.second.first<<" ";
    // }cout<<endl;
    int ans=0;
    vector<int>vec;
    fl(i,0,a.length()){
        if(mp.find(a[i])!=mp.end()){
            if(mp[a[i]].first!=0){
                mp[a[i]].first--;
                vec.pb(mp[a[i]].second[0]);
                mp[a[i]].second.erase(mp[a[i]].second.begin());
            }
        }
    }
    
    int maxi=INT_MIN;
    int p=0;
    // for(auto i:vec){
    //     cout<<i<<" ";
    // }cout<<endl;
    fl(i,0,vec.size()){
        int count=0;
        p=i;
        for(int j=i+1;j<vec.size();j++){
            if(vec[p]<vec[j]){
                count++;p=j;
            }
        }
        maxi=max(count,maxi);
    }
    if(maxi==INT_MIN)maxi=0;
    else maxi+=1;
    // cout<<"|"<<maxi+1<<endl;
    cout<<a.length()+b.length()-maxi<<endl;
    // vector<vector<int>>dp(a.length(),vector<int>(b.length(),-1));
    // int x=lcs(a,b,a.length()-1,b.length()-1,dp);
    // // cout<<x<<endl;
    // cout<<a.length()+b.length()-x<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
   //     freopen("output.txt","w",stdout);
    //     freopen("Error.txt", "w", stderr);
    // #endif 
    ll t; cin>>t; while(t--)solve();
 
}