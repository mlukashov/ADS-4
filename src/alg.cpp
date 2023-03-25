// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value)
{
	int kol = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (arr[i] + arr[j] == value)
				kol++;
		}
	}
	return kol;
}
int countPairs2(int* arr, int len, int value)
{
	int kol = 0;
	len--;
	while (arr[len] > value) {
		len--;
	}
	for (int i = 0; i < len; i++) {
		for (int j = len; j > i; j--) {
			if (arr[i] + arr[j] == value) {
				kol++;
			}
		}
	}
	return kol;
}
int countPairs3(int* arr, int len, int value)
{
	int kol = 0;
	for (int i = 0; i < len - 1; i++) {
		int lev = i, prav = len;
		while (lev + 1 < prav) {
			int mid = (lev + prav) / 2;
			if (arr[i] + arr[mid] > value) {
				prav = mid;
			}
			else if (arr[i] + arr[mid] < value) {
				lev = mid;
			}
			else {
				kol++;
				int a = mid + 1;
				while (arr[i] + arr[a] == value && a < prav) {
					kol++;
					a++;
				}
				a = mid - 1;
				while (arr[i] + arr[a] == value && a > lev) {
					kol++;
					a--;
				}
				break;
			}
		}
	}
	return kol;
}
