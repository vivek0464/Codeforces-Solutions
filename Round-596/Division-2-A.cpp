#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef long double ld;
#define mod         ll(1000000007)
#define mod1        ll(998244353)
#define mox         ll(300005)
#define inf         ll(1e18)
#define rep(i,a,b)  for(ll i=a; i<b; i++)
#define vll         vector<ll>
#define pll         pair<ll,ll>
#define mk          make_pair
#define pb          push_back
#define po          pop_back
#define ff          first
#define ss          second
#define bb          begin()
#define ee          end()
#define zz          size()
#define nn          '\n'
#define dbg(x)      cout << #x << " = " << x << '\n'
#define deciPRE(n)  cout<<fixed<<setprecision(n)

ll gcd(ll a, ll b){
    ll mi=min(a, b), mx=max(a, b), temp;
    while(mi){
        temp=mi;
        mi=mx%mi;
        mx=temp;
    }
    return mx;
}

ll pw(ll x, ll n){
    ll ans=1;
    while(n){
        if(n&1ll){
            ans*=x;
            //ans%=mod;
        }
        x*=x;
        //x%=mod;
        n>>=1ll;
    }
    return ans;
}



int main()
{
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll da, db; cin>>da>>db;
    if(db==da+1){
        cout<<da<<' '<<db<<nn;
    }
    else if(da==9 && db==1){
        cout<<da<<' '<<10<<nn;
    }
    else if(da==db){
        cout<<da<<0<<' '<<db<<1<<nn;
    }
    else{
        cout<<-1<<nn;
    }

    return 0;
}
