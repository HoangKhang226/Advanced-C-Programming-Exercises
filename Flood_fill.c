//https://leetcode.com/problems/flood-fill/description/
#include <stdio.h>
#include <stdlib.h>
void input_array(int cot, int hang, int **a)
{
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            printf("arr[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void Check_and_replace(int cot, int hang, int **a, int i, int j, int c, int n)
{
    if (i < 0 || i >= hang || j < 0 || j >= cot)
        return;
    if (a[i][j] == n)
    {
        a[i][j] = c;
        if (j + 1 < cot) // Kiểm tra phải
            Check_and_replace(cot, hang, a, i, j + 1, c, n);
        if (j - 1 >= 0) // Kiểm tra trái
            Check_and_replace(cot, hang, a, i, j - 1, c, n);
        if (i + 1 < hang) // Kiểm tra dưới
            Check_and_replace(cot, hang, a, i + 1, j, c, n);
        if (i - 1 >= 0) // Kiểm tra trên
            Check_and_replace(cot, hang, a, i - 1, j, c, n);
    }
}
void output_array(int cot, int hang, int **a)
{
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}
int main()
{
    int cot, hang;
    printf("nhap so cot: ");
    scanf("%d", &cot);
    printf("nhap so hang: ");
    scanf("%d", &hang);
    int **a = (int **)malloc(sizeof(int *) * hang); // cấp phát động
    for (int i = 0; i < hang; i++)
        a[i] = (int *)malloc(sizeof(int) * cot);
    input_array(cot, hang, a);
    printf("Array:\n");
    output_array(cot, hang, a);
    int i, j, c;
    printf("address=");
    scanf("%d%d", &i, &j);
    printf("color=");
    scanf("%d", &c);
    int n = a[i][j];
    Check_and_replace(cot, hang, a, i, j, c, n);
    output_array(cot, hang, a);
    for (int i = 0; i < hang; i++)// giải phóng bộ nhớ
        free(a[i]);
    free(a);
    return 0;
}
