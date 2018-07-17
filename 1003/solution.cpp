/*
 *题意：
 *首先找到不同最短路径，找到的同时，你可以从你经过的城市带走救援队伍。
 */

#include<iostream>
#include<queue>
using namespace std;

int edges[505][505];
int visited[505];
int dis[505];
int N, M, C1, C2;
int team_nums[505];
int team_carry[505];
int roads[505];

int main(){
	queue<int> q;
	memset(team_carry,0,sizeof(team_carry));
	memset(dis,-1,sizeof(dis));
	memset(visited,0,sizeof(visited));
	memset(edges,-1,sizeof(edges));
	cin >> N >> M >> C1 >> C2;
	for(int i=0;i < N;++i){
		cin >> team_nums[i];
	}
	for(int i=0;i < M;++i){
		int city1,city2,e;
		cin >> city1 >> city2 >> e;
		edges[city1][city2] = edges[city2][city1] = e;
	}
	dis[C1] = 0;
	team_carry[C1] = team_nums[C1];
	q.push(C1);
	roads[C1] = 1;
	for(;;){
		int t = q.front();q.pop();visited[t] = 1;
		if(t == C2)
			break;
		for(int i = 0;i < N;++i){
			if(edges[t][i] != -1 && visited[i] == 0){
				if(dis[i] == -1 || dis[t] + edges[t][i] < dis[i]){
					dis[i] = dis[t] + edges[t][i];
					roads[i] = roads[t];
					team_carry[i] = team_nums[i] + team_carry[t];
				}
				else if(dis[t] + edges[t][i] == dis[i]){
					roads[i] += roads[t];
					team_carry[i] = (team_carry[i] > (team_nums[i] + team_carry[t]))?
											team_carry[i]:team_nums[i]+team_carry[t];
				}
			}
		}
		int max = 99999;
		int c;
		for(int i = 0;i < N;++i){
			if(dis[i] != -1 && dis[i] < max && !visited[i]){
				max = dis[i];
				c = i;
			}
		}
		q.push(c);
	}
	cout << roads[C2] << ' ' << team_carry[C2] << endl;
	return 0;
}