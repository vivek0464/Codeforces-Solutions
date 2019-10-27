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

ll ans[2005][2005][2]={0};

int main()
{
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, m; cin>>n>>m;
    vector< vll> a(n, vll(m)), cr(n, vll(m)), cc(n, vll(m));
    rep(i,0,n){
        rep(j,0,m){
            char ch; cin>>ch;
            if(ch=='R'){
                a[i][j]=1;
            }
            else{
                a[i][j]=0;
            }
            cr[i][j]=cc[i][j]=a[i][j];
        }
    }
    ans[n-1][m-1][0]=ans[n-1][m-1][1]=1-a[n-1][m-1];
    rep(i,1,n){
        ll j=n-1-i;
        ans[j][m-1][0]=ans[j][m-1][1]=(1-a[j][m-1])*ans[j+1][m-1][0];
    }
    rep(i,1,m){
        ll j=m-1-i;
        ans[n-1][j][0]=ans[n-1][j][1]=(1-a[n-1][j])*ans[n-1][j+1][0];
    }
    rep(i,0,n){
        rep(j,1,m){
            ll k=m-1-j;
            cr[i][k]+=cr[i][k+1];
        }
    }
    rep(i,0,m){
        rep(j,1,n){
            ll k=n-1-j;
            cc[k][i]+=cc[k+1][i];
        }
    }
    rep(x,1,n){
        rep(y,1,m){
            ll i=n-1-x, j=m-1-y;
            if(a[i][j]==0){
                ans[i][j][0]=ans[i][j][1]=(ans[i][j+1][0]+ans[i+1][j][1])%mod;
            }
            else{
                ans[i][j][0]=(ans[i][j+1][0]+mod-ans[i+1][m-cr[i][j]][1]+ans[i+1][j][1])%mod;
                ans[i][j][1]=(ans[i][j+1][0]+ans[i+1][j][1]+mod-ans[n-cc[i][j]][j+1][0])%mod;
            }
        }
    }
    cout<<ans[0][0][0]<<nn;

    return 0;
}
