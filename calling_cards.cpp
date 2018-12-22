/* 247 - Calling Circles */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include<map>
#include<math.h>
#include<vector>
#include <stack>
#define MAX 40
using namespace std;
map<string , int >MAP;
map<int  , string >MAP2;
vector<vector<string> > arra;
vector<vector<int> > G;
vector<vector<int> > GT;
bool vis[MAX];
stack<int>S;
int ans=0;
void dfs(int node)
{
    vis[node]=1;
    for(int i=0; i<G[node].size(); i++)
        if(!vis[G[node][i]])
            dfs(G[node][i]);
 
    S.push(node);
 
}
void dfs2(int node)
{
    vis[node]=1;
 
    arra[ans].push_back(MAP2[node]);
    for(int i=0; i<GT[node].size(); i++)
        if(!vis[GT[node][i]])
            dfs2(GT[node][i]);
 
 
 
}
int main()
{
    int m,n;
    string a, b;
    int c,d,k;
    int u=1;
    while(scanf("%d %d",&m,&n))
    {
 
        G.assign(m+1, vector<int>());
        GT.assign(m+1, vector<int>());
        arra.assign(m+1, vector<string>());
 
 
        if(!m && !n)
            break;
        c=1;
 
        for (int i=1; i<=n; i++)
        {
            cin>> a >> b;
 
            if(MAP.find(a)==MAP.end())
            {
                MAP2[c]=a;
                d=c;
                MAP[a]=c++;
 
            }
            if(MAP.find(b)==MAP.end())
            {
                MAP2[c]=b;
                k=c;
                MAP[b]=c++;
 
            }
             
            G[MAP[a]].push_back(MAP[b]);
            GT[MAP[b]].push_back(MAP[a]);
 
        }
 
 
        fill(&vis[0],&vis[MAX],false);
        for(int i=1; i<=m ; i++)
            if(!vis[i])
                dfs(i);
        fill(&vis[0],&vis[MAX],false);
        ans=0;
 
        while(!S.empty())
        {
 
            int node = S.top();
 
            S.pop();
            if(!vis[node])
                dfs2(node),ans++;
 
 
 
        }
        if(u > 1) puts("");
        printf("Calling circles for data set %d:\n",u++);
        for(int i=0; i<ans; i++)
        {
            int w=arra[i].size();
 
            for(int j=0; j<w; j++)
            {
                cout<<arra[i][j] ;
                if(j<w-1)
                    cout << (", ");
            }
            printf("\n");
        }
        while(!S.empty())S.pop();
 
 
        MAP.clear();
        MAP2.clear();
    }
 
    return 0;
}