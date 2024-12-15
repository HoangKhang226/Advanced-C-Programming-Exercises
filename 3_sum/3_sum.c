#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void input(int *arr, int n);
void bubble_sort(int *arr, int n);
int convert_1D_to_2D(int *arr, int *n, int arr2D[][3]);
void print(int *arr, int n);
void print_2D(int arr2D[][3], int col);
void check_and_output(int arr2D[][3], int *col);
int main()
{
    int n;
    printf("input the number of elements in array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("array:\n");
    input(arr, n);
    print(arr, n);
    bubble_sort(arr, n);
    int arr2D[10][3];
    int col = convert_1D_to_2D(arr, &n, arr2D);
    check_and_output(arr2D, &col);
    print_2D(arr2D, col);
    free(arr);
    return 0;
}
void input(int *arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 7 - 3; // Tạo số ngẫu nhiên từ -3 đến 3
}
void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
int convert_1D_to_2D(int *arr, int *n, int arr2D[][3])
{
    int col = 0;
    for (int i = 0; i < *n; i++)
    {
        int j, k;
        int count = 0, flag = 0;
        for (j = i + 1; j < *n; j++)
        {
            for (k = j + 1; k < *n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    arr2D[col][count++] = arr[i];
                    arr2D[col][count++] = arr[j];
                    arr2D[col][count++] = arr[k];
                    col++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
        {
            // xóa các phần tử đã sử dụng
            for (int l = i; l < (*n) - 1; l++)
                arr[l] = arr[l + 1];
            (*n)--;
            for (int l = j - 1; l < (*n) - 1; l++)//-1 vì vị trí l đã bị dịch xuống 1 đơn vị
                arr[l] = arr[l + 1];
            (*n)--;
            for (int l = k - 2; l < (*n); l++)//-2 vì vị trí l đã bị dịch xuống 2 đơn vị
                arr[l] = arr[l + 1];
            (*n)--;
            i--;
        }
    }
    return col;
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
void print_2D(int arr2D[][3], int col)
{
    printf("\n3 sum in array:");
    for (int i = 0; i < col; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
            printf("%5d", arr2D[i][j]);
    }
}
void check_and_output(int arr2D[][3], int *col)
{
    for (int i = 0; i < *col - 1; i++)
        for (int j = i + 1; j < *col; j++)
        {
            if (arr2D[i][0] == arr2D[j][0] &&
                arr2D[i][1] == arr2D[j][1] &&
                arr2D[i][2] == arr2D[j][2])
            {
                // Xóa dòng trùng lặp
                for (int k = j; k < *col - 1; k++)
                {
                    arr2D[k][0] = arr2D[k + 1][0];
                    arr2D[k][1] = arr2D[k + 1][1];
                    arr2D[k][2] = arr2D[k + 1][2];
                }
                (*col)--; // Giảm số lượng cột
                j--;      // Lùi lại để kiểm tra lại phần tử vừa dời lên
            }
        }
}