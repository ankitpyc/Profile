#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include<vector>
using namespace std;
#define N 7700
#define MAX 25000
int dn[N],l[N],ans,dfsn;

typedef struct{
   int source;
   int target;
}record;

static record edge[MAX];
vector <int> adj[MAX];
void dfs(int u, int prev) {
dn[u] = dfsn++;
l[u] = dn[u];
int flag = 0;
for(int i=0;i<adj[u].size();i++) {
int v = adj[u][i];
if(v == prev) continue;
if(dn[v]!=-1)
{
l[u] = min(l[u], dn[v]);
}
else {
dfs(v,u);
if(u!=0 && l[v] >= dn[u]) flag=1;
else if(u==0)
flag++;
l[u] = min(l[u], l[v]);
}
}
if(u!=0 && flag)
//cout<<"ARTICULATION POINT ->"<<u<<endl;
printf("articulation point");
else if(u==0 && flag>1)
cout<<"ARTICULATION POINT ->"<<u<<endl;
}
int main()
{
int a,b;
FILE *fp;
    int count = 0;
    fp = fopen("demo.csv","r");
    if(fp == NULL)
    {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }
    while (fscanf(fp, "%d,%d", &edge[count].source, &edge[count].target) == 2)
    {
        count++;
    }
printf("count is %d\n",count);

for(int i=0;i<N;i++)
adj[i].clear();

for(int p=0;p<count;p++)
{
a=edge[p].source;
b=edge[p].target;
printf("%d %d",a,b);
adj[a].push_back(b);
adj[b].push_back(a);
printf("%d",adj[p]);
}
for(int i=0;i<4;i++)
dn[i] = -1;
dfsn = 1; ans = 0;
dfs(0,-1);
}
