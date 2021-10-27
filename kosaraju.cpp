//Solved problem : 427C

//Kosaraju's Algorithm
vector<int> g[100000],g2[100000];
int cost[100000]; int vis[100000];
void dfs1(int v, vector<int> &list){
    vis[v]=1;
    for(auto x:g[v]){
        if(vis[x])continue;
        dfs1(x,list);
    }
    list.push_back(v);
}
void dfs2(int v,vector<int> &comp){
    vis[v]=1;
    for(auto x:g2[v]){
        if(vis[x])continue;
        dfs2(x,comp);
    }
    comp.push_back(cost[v]);
}

void solve() {
    int n;
    cin >> n;
    fo(i,n) re(cost[i]);
    int m; cin >> m;
    fo(i,m){
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g2[y].push_back(x);
    }
    fo(i,n) vis[i] = 0;
    vector<int> list;
    fo(i,n){
        if(vis[i]) continue;
        dfs1(i, list);
    }
    reverse(all(list));
    memset(vis, 0, sizeof vis);
    int money = 0, ways = 1;
    vector<int> comp;
    fo(i,n){
        if(vis[list[i]]) continue;
        comp.clear();
        dfs2(list[i], comp);
        int mn = *min_element(all(comp));
        int cnt = count(all(comp), mn);
        money += mn;
        ways = (ways * cnt) % mod;
    }
    ps(money, ways);
}