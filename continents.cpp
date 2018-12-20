/* 11094 - Continents */

#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, ans, sum;
char arr[21][21], used[21][21], land;
void dfs(int x, int y) {
    if(y < 0)   y = m-1;
    if(y >= m)  y = 0;
    if(x < 0 || x >= n)
        return ;
    if(used[x][y] != 0 || arr[x][y] != land)
        return ;
    used[x][y] = 1;
    sum++;
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x, y-1);
}
int main() {
	ifstream in;
	ofstream out;
	in.open("cont.txt");
	out.open("cont_o");
    while(in>>m>>n) {
        memset(used, 0, sizeof(used));
        for(i = 0; i < n; i++)
            in>>arr[i];
        in>>i>>j;
        land = arr[i][j];
        dfs(i, j);
        ans = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                sum = 0;
                dfs(i, j);
                if(sum > ans)
                    ans = sum;
            }
        }
        out<<ans<<endl;;
    }
    return 0;
}