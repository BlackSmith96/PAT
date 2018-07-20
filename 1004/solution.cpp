/*
 *注意树的最大层数以及可能的第一层的输出。
 *
 */


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> children[101];

int counts[102];
int depth = -1; //used for count the depth of the tree

void dfs(int node, int d){
    if(d > depth)
        depth = d;
    if(children[node].size() == 0){
        counts[d]++;
        return;
    }
    for(int i=0;i < children[node].size();++i){
        dfs(children[node][i],d+1);
    }
}

int main(){
    int N,M;
    cin >> N >> M;

    for(int i=0;i < M;++i){
        int ID,k,tID;
        cin >> ID >> k;
        for(int j=0;j < k;++j){
            cin >> tID;
            children[ID].push_back(tID);
        }
    }

    dfs(1,0);

    cout << 0;
    for(int i=1;i <= depth;++i){
        cout << ' ' << counts[i];
    }
    cout << endl;
}