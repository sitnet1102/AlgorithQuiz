#include <stdio.h>
int result[100];
int index = 0;
int arr[100][100];

int input(int num){
	int check=1;	
	for(int i=0;i<100;i++){
		check = 1;
		if(arr[num-1][i]!='\0'){
			for(int j=0;j<100;j++){
				if(arr[num-1][i]==result[j]){
					check = 0;
				}
				if(result[j]=='\0'){
					break;
				}
			}
			if(check){
				result[index] = arr[num-1][i];
				index++;
				input(arr[num-1][i]);
			}
		}
	}
	return 0;
}

int main(void){
	int com_num;
	int link_num;
	int i,j;
	int result_num=0;
	int a,b;
	int temp;

	scanf("%d %d",&com_num,&link_num);

	for(i=0;i<link_num;i++){
		scanf("%d %d",&a,&b);
		if(a>b){
			temp = a;
			a = b;
			b = temp;
		}
		for(j=0;j<100;j++){
			if(arr[a-1][j]=='\0'){
				arr[a-1][j]=b;
				break;
			}
			//sorting????

		}
		for(j=0;j<100;j++){
			if(arr[b-1][j]=='\0'){
				arr[b-1][j]=a;
				break;
			}
		}
	}
	////////
/*
	for(i=0;i<100;i++){
		if(arr[i][0]!='\0'){
			printf("%d : ",i+1);
			for(j=0;j<100;j++){
				if(arr[i][j]!='\0'){
					printf("%d ",arr[i][j]);
				}else{
					break;
				}
			}
			printf("\n");

		}

	}





*/
	///////



	for(i=0;i<100;i++){
		if(arr[0][i]!='\0'){
			//result[index] = arr[0][i];
			//index++;arr[0][i]
			input(1);			
		}else{
			break;
		}
	}

	for(i=0;i<100;i++){
		if(result[i]!='\0'){
			//printf("%d ",result[i]);
			result_num++;
		}else{
			break;
		}
	}
	printf("%d",result_num-1);
	return 0;
}



