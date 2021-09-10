#include <iostream>

int conductor(int x) {
	int n, result;
	n = x;
	result = x;
	while (n != 0) {
		result += n % 10;
		n /= 10;
	}
	return result;
}
int main() {
	int n, i;
	int result = 0;
	scanf("%d", &n);

	for (i = n; i > 0; i--) {
		if (conductor(i) == n) {
			result = i;
		}
	}
	printf("%d", result);
	return 0;
}