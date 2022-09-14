#include <cstdio>
int N;
int map[100][100]={0,};

int main(){
	int temp;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(int k = 0 ; k < N ; k++){
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				if( map[i][k] && map[k][j]){
					map[i][j] = 1;
				}
			}
		}
	}

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
