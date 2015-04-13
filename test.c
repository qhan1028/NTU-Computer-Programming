#include <stdio.h>
int find_gcd(int a, int b) // 找最大公因數
{
	int buffer;
	while(a % b != 0) {
		buffer = b;
		b = a % b;
		a = buffer;
	}
	return b;
}
int main(){
	int a[1000],i = 0; // i 要初始化
	int gcd,lcm,count;
    int k,buffer,still_count ;
	while(scanf("%d",&a[i]) != EOF){ // 讀進所有數字
		i ++;	
	}
	count = i;

	for (i = 0 ; i < count - 1 ; i++) { //兩個兩個去找出最小公倍數
		gcd = find_gcd(a[i], a[i+1]);
		lcm = a[i] * a[i+1] / gcd; //找到'暫時的'最小公倍數
		a[i+1] = lcm; // 把'暫時的'最小公倍數指定給a[i+1], 然後在往下兩組找最小公倍數
	}
	/*for(i = 0 ; scanf("%d",&a[i] )!= EOF ; i ++){
		if(a[i] < count){
			buffer = a[i] ;
			a[i] = count ;
			count = buffer;
		}
		still_count = count ;	
		while(a[i] % count != 0){
			k = a[i] % count ;
			a[i] = count ;
			count = k;
		}
		lcm = still_count * a[i] / count;

		count = lcm ;
	}*/
	printf("%d", lcm) ;
return 0 ;
}