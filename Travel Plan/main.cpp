#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 99999999;
int N, M, S, D;
int dis[500][500], pre[500], cost[500][500], cur_dis[500], cur_cost[500];
bool visited[500];

int minn() {
    //Find smallest unknown distance vertex
    int u = -1, max = inf;
    for(int j=0;j < N;++j) {
        if(visited[j] == true)
            continue;
        if(cur_dis[j] < max) {
            u = j;
            max = cur_dis[j];
        }
    }
    return u;
}

bool judge(int start, int dest) {
    if(!dis[start][dest])
        return false;
    if(cur_dis[dest] < cur_dis[start] + dis[start][dest])
        return false;
    if(cur_dis[dest] > cur_dis[start] + dis[start][dest])
        return true;
    if(cur_cost[dest] > cur_cost[start] + cost[start][dest])
        return true;
}

void print_route(int d) {
    if(pre[d] == -1)
        cout << d << ' ';
    else {
        print_route(pre[d]);
        cout << d << ' ';
    }
}

int main() {
    fill(pre,pre+500,-1);
    fill(cur_dis,cur_dis+500,inf);
    fill(cur_cost,cur_cost+500,0);
    fill(dis[0],dis[0]+500*500,0);
    fill(visited,visited+500,false);

    cin >> N >> M >> S >> D;
    for(int i=0,a,b,d,c;i < M;++i) {
        cin >> a >> b >> d >> c;
        dis[a][b] = dis[b][a] = d;
        cost[a][b] = cost[b][a] = c;
    }

    //Dijkstra
    cur_dis[S] = 0;
    while(true) {
        int u = minn();
        if(u == -1) break;
        visited[u] = true;

        for(int j = 0;j < N;++j) {
            if(visited[j])
                continue;
            if(judge(u,j)) {
                pre[j] = u;
                cur_dis[j] = cur_dis[u] + dis[u][j];
                cur_cost[j] = cur_cost[u] + cost[u][j];
            }
        }
    }
    print_route(D);
    cout << cur_dis[D] << ' ' << cur_cost[D];
    return 0;
}