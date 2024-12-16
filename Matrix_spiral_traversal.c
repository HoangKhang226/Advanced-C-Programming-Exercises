#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void input_matrix(int **a, int hang, int cot);
void selection_sort_in_matrix(int **a, int hang, int cot);
void output_array(int **a, int hang, int cot);
void matrix_spiral_traversal(int **a, int **ast, int hang, int cot);
int main()
{
    int hang, cot;
    printf("rows: ");
    scanf("%d", &hang);
    printf("columns: ");
    scanf("%d", &cot);
    int **a = (int **)malloc(sizeof(int *) * hang); // cấp phát động
    for (int i = 0; i < hang; i++)
        a[i] = (int *)malloc(sizeof(int) * cot);
    input_matrix(a, hang, cot);
    printf("mang ban dau la:\n");
    output_array(a, hang, cot);
    selection_sort_in_matrix(a, hang, cot);
    int **ast = (int **)malloc(sizeof(int *) * hang); // cấp phát động
    for (int i = 0; i < hang; i++)
        ast[i] = (int *)malloc(sizeof(int) * cot);
    matrix_spiral_traversal(a, ast, hang, cot);
    printf("mang sau khi sap xep la:\n");
    output_array(ast, hang, cot);
    for (int i = 0; i < hang; i++) // giải phóng bộ nhớ
        free(a[i]);
    free(a);
    return 0;
}
void input_matrix(int **a, int hang, int cot)
{
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < cot; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
}
void selection_sort_in_matrix(int **a, int hang, int cot)
{
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            int min = a[i][j], col_min = j, row_min = i;
            for (int k = i; k < hang; k++)
            {
                if (k == i)
                    for (int l = j; l < cot; l++)
                    {
                        if (a[k][l] < min)
                        {
                            min = a[k][l];
                            col_min = l;
                            row_min = k;
                        }
                    }
                else
                    for (int l = 0; l < cot; l++)
                    {
                        if (a[k][l] < min)
                        {
                            min = a[k][l];
                            col_min = l;
                            row_min = k;
                        }
                    }
            }
            int temp = min;
            a[row_min][col_min] = a[i][j];
            a[i][j] = min;
        }
    }
}
void output_array(int **a, int hang, int cot)
{
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
void matrix_spiral_traversal(int **a, int **ast, int hang, int cot)
{
    int left = 0, right = hang - 1;
    int top = 0, bottom = cot - 1;
    int col = 0, row = 0;
    while (left <= right && top <= bottom)
    {
        // xử lý top
        for (int i = left; i <= right; i++)
        {
            if (col == cot)
            {
                col = 0;
                row++;
            }
            ast[top][i] = a[row][col++];
        }
        top++;
        // xử lý right
        for (int i = top; i <= bottom; i++)
        {
            if (col == cot)
            {
                col = 0;
                row++;
            }
            ast[i][right] = a[row][col++];
        }
        right--;
        if (top < bottom)
        { // xử lý bottom
            for (int i = right; i >= left; i--)
            {
                if (col == cot)
                {
                    col = 0;
                    row++;
                }
                ast[bottom][i] = a[row][col++];
            }
            bottom--;
        }
        if (left < right)
        {
            // xử lý left
            for (int i = bottom; i >= top; i--)
            {
                if (col == cot)
                {
                    col = 0;
                    row++;
                }
                ast[i][left] = a[row][col++];
            }
            left++;
        }
    }
}