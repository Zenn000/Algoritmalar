#include <stdio.h>

void customSort(int arr[], int n) {
    // Önce sırala
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    
    // Özel sırala
    int result[n];
    int left = 0, right = n-1;
    for (int i = 0; i < n; i++)
        result[i] = (i%2 == 0) ? arr[right--] : arr[left++];
    
    // Kopyala
    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}

int main() {
    int arr[] = {60, 80, 3, 9, 57, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    customSort(arr, n);
    printf("Özel sıralama: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
