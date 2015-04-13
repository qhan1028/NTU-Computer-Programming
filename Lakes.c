#include <stdio.h>

int in(i, j, N, M)
{
	return (i >= 0 && i < N && j >= 0 && j < M);
}

int FindLakeSize(int i, int j, int N, int M, int lake[401][401])
{
	int d, size = 1;
	int di[4] = {1, 0, -1, 0};
	int dj[4] = {0, 1, 0, -1};

	lake[i][j] = 0;
	for (d = 0 ; d < 4 ; d++) {
		int newi = i + di[d];
		int newj = j + dj[d];
		if (lake[newi][newj] == 1 && in(newi, newj, N, M)) {
			size += FindLakeSize(newi, newj, N, M, lake);
		}
	}
	return size;
}

int FindAllLakes(int N, int M, int lake[401][401], int lakesize[])
{
	int count = 0;
	int i, j;

	for (i = 0 ; i < N ; i++) {
		for (j = 0 ; j < M ; j++) {
			if (lake[i][j] == 1) {
				lakesize[count] = FindLakeSize(i, j, N, M, lake);
				count++;
			}
		}
	}
	return count;
}

int main(void)
{
	int N, M, i, j, temp;
	scanf("%d%d", &N, &M);
	int lake[401][401];
	for (i = 0 ; i < N ; i++) {
		for (j = 0 ; j < M ; j++) {
			scanf("%d", &lake[i][j]);
		}
	}
	int lakesize[401*401] = {0};
	int AllLakes = FindAllLakes(N, M, lake, lakesize);

	for (i = 0 ; i < AllLakes ; i++) {
		for (j = i+1 ; j < AllLakes ; j++) {
			if (lakesize[i] < lakesize[j]) {
				temp = lakesize[i];
				lakesize[i] = lakesize[j];
				lakesize[j] = temp;
			}
		}
	}
	for (i = 0 ; i < AllLakes ; i++) {
		printf("%d\n", lakesize[i]);
	}
	return 0;
}