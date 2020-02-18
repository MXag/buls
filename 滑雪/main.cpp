#include <iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m,ci;
int g[102][102];
int dp[102][102];
bool pan(int x,int y) {
		if(x>=0&&x<n&&y>=0&&y<m) return true;
		return false;
	}

int d(int i,int j){
    int ans = dp[i][j];
		if(ans>0) return ans;
		else {
			ans  = 1;
			for(int x=-1;x<=1;x++) {
				for(int y=-1;y<=1;y++) {
					int dx = i+x;
					int dy = j+y;
					if(abs(x+y)&&pan(dx,dy)&&g[dx][dy]>g[i][j])
						ans = max(ans, d(dx,dy)+1);
				}
			}
			dp[i][j] = ans;
		}
		return ans;
}

int main()
{
    cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>g[i][j];
        memset(dp,0,sizeof(dp));
        int ma = -1;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            ma = max(ma, d(i,j));
			}
            cout<<ma<<endl;
    return 0;
}
