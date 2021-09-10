#include <iostream>
int process(int x) {
	int n, test;
	n = x;
	while (n != 0) {
		test = n % 1000;
		n /= 10;
		if (test == 666) {
			return 1;
		}
	}
	return 0;
}
int main() {
	int n, i, check;
	check = 0;
	scanf("%d", &n);
	for (i = 666; i < 10000000; i++) {
		check += process(i);
		if (check == n) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}