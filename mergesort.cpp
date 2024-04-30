#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int mid, int l, int r) {
    int s1 = mid - l + 1;
    int s2 = r - mid;

    int a1[s1];
    int a2[s2];

    for (int i = 0; i < s1; i++) {
        a1[i] = arr[l + i];
    }
    for (int i = 0; i < s2; i++) {
        a2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < s1 && j < s2) {
        if (a1[i] <= a2[j]) {
            arr[k++] = a1[i++];
        } else {
            arr[k++] = a2[j++];
        }
    }

    while (i < s1) {
        arr[k++] = a1[i++];
    }
    while (j < s2) {
        arr[k++] = a2[j++];
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int middle = l + (r - l) / 2;
        mergesort(arr, l, middle);
        mergesort(arr, middle + 1, r);
        merge(arr, middle, l, r);
    }
}

int main() {
    int arr[] = {3, 4, 25, 24, 6, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    int r = size - 1;
    mergesort(arr, l, r);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    return 0;
}
