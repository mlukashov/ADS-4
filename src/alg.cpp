// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int lev = 0;
    int prav = size - 1;
    int kol = 0;
    while (lev <= prav) {
        int mid = (lev + prav) / 2;
        if (value < arr[mid]) {
            prav = mid - 1;
        }
        else if (value > arr[mid]) {
            lev = mid + 1;
        }
        else {
            for (int i = 1; arr[mid] == arr[mid - i]; i++)
                    kol++;
            for (int i = 0; arr[mid] == arr[mid + i]; i++)
                    kol++;
            return kol;
        }
    }
    return 0;
}
int countPairs1(int *arr, int len, int value) {
    int kol = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[i] + arr[j] == value)
                kol++;
        }
    }
    return kol;
}
int countPairs2(int *arr, int len, int value) {
    int kol = 0;
    while (arr[len] > value)
        len--;
    for (int i = 0; i < len; i++) {
        for (int j = len; j > i; j--) {
            if (arr[i] + arr[j] == value)
                kol++;
        }
    }
    return kol;
}
int countPairs3(int *arr, int len, int value) {
    int kol = 0;
    for (int i = 0; i < len; i++) {
        kol+= cbinsearch(arr + (i + 1), len - i, value - (*(arr + i)));
    return kol;
    }
}
