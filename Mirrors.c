#include <stdio.h>
int main(void) 
{
	int w,d;
	scanf("%d%d",&w,&d);
	
	//各格情況
	int i,j;
	int coordinate[w][d];
	for (i = d-1 ; i >= 0 ; i--) { //y座標
		for (j = 0 ; j < w ; j++) { //x座標
			scanf("%d",&coordinate[j][i]);
		}
	}
	
	//開始判斷
	int x,y,direction,side;
	//以上OK
	
	for (i = 0 ; i < w ; i++) { //下出發
		direction = 1;
		x = i;
		y = 0;
		while (x >= 0 && x < w && y >=0 && y < d) {
			switch (coordinate[x][y]) { //方向
				case 1 :
				if (direction == 1 || direction == 3) direction--;
				else direction++;
				break;
				case 2 :
				if (direction == 1) direction = 2;
				else if (direction == 2) direction = 1;
				else if (direction == 3) direction = 0;
				else if (direction == 0) direction = 3;
				break;
				default :
				direction = direction;
			}
			switch (direction) { //移動
				case 0 :
				x = x + 1;
				break;
				case 1 :
				y = y + 1;
				break;
				case 2 :
				x = x - 1;
				break;
				case 3 :
				y = y - 1;
				break;
				default :
				x = y = 0;
			}
		}
		if (x == w) side = w + y;
		if (x < 0) side = 2*(w + d) - y - 1;
		if (y == d) side = 2*w + d - x - 1;
		if (y < 0) side = x;
		
		printf("%d \n",side);
	}
	
	for (i = 0 ; i < d ; i++) { //右出發
		direction = 2;
		x = w - 1;
		y = i;
		while (x >= 0 && x < w && y >=0 && y < d) {
			switch (coordinate[x][y]) { //方向
				case 1 :
				if (direction == 1 || direction == 3) direction--;
				else direction++;
				break;
				case 2 :
				if (direction == 1) direction = 2;
				else if (direction == 2) direction = 1;
				else if (direction == 3) direction = 0;
				else if (direction == 0) direction = 3;
				break;
				default :
				direction = direction;
			}
			switch (direction) { //移動
				case 0 :
				x = x + 1;
				break;
				case 1 :
				y = y + 1;
				break;
				case 2 :
				x = x - 1;
				break;
				case 3 :
				y = y - 1;
				break;
				default :
				x = y = 0;
			}
		}
		if (x == w) side = w + y;
		if (x < 0) side = 2*(w + d) - y - 1;
		if (y == d) side = 2*w + d - x - 1;
		if (y < 0) side = x;
		
		printf("%d \n",side);
	}
	
	for (i = w - 1 ; i >= 0 ; i--) { //上出發
		direction = 3;
		x = i;
		y = d - 1;
		while (x >= 0 && x < w && y >=0 && y < d) {
			switch (coordinate[x][y]) { //方向
				case 1 :
				if (direction == 1 || direction == 3) direction--;
				else direction++;
				break;
				case 2 :
				if (direction == 1) direction = 2;
				else if (direction == 2) direction = 1;
				else if (direction == 3) direction = 0;
				else if (direction == 0) direction = 3;
				break;
				default :
				direction = direction;
			}
			switch (direction) { //移動
				case 0 :
				x = x + 1;
				break;
				case 1 :
				y = y + 1;
				break;
				case 2 :
				x = x - 1;
				break;
				case 3 :
				y = y - 1;
				break;
				default :
				x = y = 0;
			}
		}
		if (x == w) side = w + y;
		if (x < 0) side = 2*(w + d) - y - 1;
		if (y == d) side = 2*w + d - x - 1;
		if (y < 0) side = x;
		
		printf("%d \n",side);
	}
	
	for (i = d - 1 ; i >= 0 ; i--) { //左出發
		direction = 0;
		x = 0;
		y = i;
		while (x >= 0 && x < w && y >=0 && y < d) {
			switch (coordinate[x][y]) { //方向
				case 1 :
				if (direction == 1 || direction == 3) direction--;
				else direction++;
				break;
				case 2 :
				if (direction == 1) direction = 2;
				else if (direction == 2) direction = 1;
				else if (direction == 3) direction = 0;
				else if (direction == 0) direction = 3;
				break;
				default :
				direction = direction;
			}
			switch (direction) { //移動
				case 0 :
				x = x + 1;
				break;
				case 1 :
				y = y + 1;
				break;
				case 2 :
				x = x - 1;
				break;
				case 3 :
				y = y - 1;
				break;
				default :
				x = y = 0;
			}
		}
		if (x == w) side = w + y;
		if (x < 0) side = 2*(w + d) - y - 1;
		if (y == d) side = 2*w + d - x - 1;
		if (y < 0) side = x;
		
		printf("%d \n",side);
	}
	
	return 0;
}
