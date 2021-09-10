#include <stdio.h>
 
int main(void) {
	// your code goes here
	int x[3];
	int y[3];
	int X, Y;
	scanf("%d %d", &x[0], &y[0]);
	scanf("%d %d", &x[1], &y[1]);
	scanf("%d %d", &x[2], &y[2]);
	if(x[0] == x[1]){
		X = x[2];
	}else if(x[0] == x[2]){
		X = x[1];
	}else{
		X = x[0];
	}
	if(y[0] == y[1]){
		Y = y[2];
	}else if(y[0] == y[2]){
		Y = y[1];
	}else{
		Y = y[0];
	}
 
	printf("%d %d\n", X, Y);
	return 0;
}