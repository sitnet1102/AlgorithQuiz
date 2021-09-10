#include <iostream>
//해 선택(Selection Procedure)
int function(int num, int* p_k) {
	int result;
	result = (*p_k) / num;
	*p_k = (*p_k) % num;	//적절성 검사(Feasibility Check)
	return result;
}
int main() {
	int n, k, i, result=0;
	int a, b;
	int n_num[10];

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &n_num[i]);
	}

	for (i = n - 1; i >= 0; i--) {
		result += function(n_num[i], &k); 
		//해 검사(Solution Check) 
		if (k == 0) {
			break;
		}
	}
	printf("%d", result);

	return 0;
}