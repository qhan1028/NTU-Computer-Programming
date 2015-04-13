#include <stdio.h> //注意邊界問題
int main(void) 
{
	int n;
	scanf("%d",&n);
	int coordinate[n+2][n+2],i,j;
	for (i = n  ; i > 0 ; i--) { //y
		for (j = 1 ; j <= n ; j++) { //x
			scanf("%d",&coordinate[j][i]);
		}
	}
	for (i = 1 ; i < n+1 ; i++) {
		coordinate[0][i] = 0;
		coordinate[n+1][i] = 0;
		coordinate[i][0] = 0;
		coordinate[i][n+1] = 0;
	}
	// 1是路 0是建築物 判斷上下左右是否有路
	int u,d,r,l,count;
	int A = 0,B = 0,C = 0,D = 0,E = 0;
	for (i = 1 ; i <= n ; i++) { //x
		for (j = 1 ; j <= n ; j++) { //y
			if (coordinate[i][j] == 0)
			continue;
			
			u = d = r = l = count = 0;
			if (coordinate[i+1][j] == 1) {
				r = 1;
				count++;
			}
			if (coordinate[i-1][j] == 1) {
				l = 1;
				count++;
			}
			if (coordinate[i][j+1] == 1) {
				u = 1;
				count++;
			}
			if (coordinate[i][j-1] == 1) {
				d = 1;
				count++;
			}
			switch (count) {
				case 4 :
				A++;
				break;
				case 3 :
				B++;
				break;
				case 2 :
				if ((u == 1 && r == 1) || (u == 1 && l == 1) || (d == 1 && r == 1) || (d == 1 && l == 1)) C++;
				break;
				case 1 :
				D++;
				break;
				default :
				E++;
			}
		}
	}
	printf("%d\n%d\n%d\n%d",A,B,C,D);
	
	return 0;
}
