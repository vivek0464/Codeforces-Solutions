#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef long double ld;
#define mod         ll(1000000007)
#define mod1        ll(998244353)
#define mox         ll(100005)
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

ll spf[mox];
map < vector<pll>, ll> mp;
ll ans=0, n, k;
vector<pll> v[mox];

void sieve(){ 
    rep(i,1,mox){
        spf[i]=i;
    }
    for(ll i=2; i*i<mox; i++){  
        if(spf[i]==i){ 
            for(ll j=i*i; j<mox; j+=i){
                if(spf[j]==j){ 
                    spf[j]=i;
                }
            }
        }
    }
} 

void gf(ll x, ll p){
    vector<pll> ret; 
    while(x!=1){
        ll c=0, t=spf[x];
        while(x%t==0){
            x/=t;
            c++;
        }
        c%=k;
        if(c!=0){
            ret.push_back(mk(t,c));
        }
    }
    v[p]=ret;
    mp[ret]++;
    if((ll)ret.zz==0){
        ans+=mp[ret]-1;
    }
}

int main()
{
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>k;
    sieve();
    vll a(n);
    rep(i,0,n){
        cin>>a[i];
        gf(a[i], i);
    }
    ll r=0;
    rep(i,0,n){
        if((ll)v[i].zz!=0){
            vector<pll> tm=v[i];
            rep(j,0,v[i].zz){
                tm[j].ss=k-v[i][j].ss;
            }
            r+=mp[tm];
            if(tm==v[i])
            r--;
        }
    }
    r/=2;
    ans+=r;
    cout<<ans<<nn;

    return 0;
}
