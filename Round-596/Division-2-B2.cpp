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

	ll t; cin>>t;
    while(t--){
        ll n, k, d; cin>>n>>k>>d;
        map <ll,ll> mp;
        vll a(n);
        rep(i,0,n){
            cin>>a[i];
        }
        ll r=0;
        rep(i,0,d-1){
            mp[a[i]]++;
            if(mp[a[i]]==1){
                r++;
            }
        }
        ll ans=k;
        rep(i,d-1,n){
            mp[a[i]]++;
            if(mp[a[i]]==1){
                r++;
            }
            ans=min(ans,r);
            mp[a[i-d+1]]--;
            if(mp[a[i-d+1]]==0){
                r--;
            }
        }
        cout<<ans<<nn;
    }

    return 0;
}
