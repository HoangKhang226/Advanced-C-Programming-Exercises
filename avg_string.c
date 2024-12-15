#include <stdio.h>
#include <string.h>
float Check_Count_And_Sum(int *a, char *str);
int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    int a[30];
    for (int i = 0; i < 30; i++) // cho giá trị của mảng bằng 0 để tránh lỗi
    {
        a[i] = 0;
    }
    float result = Check_Count_And_Sum(a, str);
    printf("%f", result);
}
float Check_Count_And_Sum(int *a, char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        int count = 0;                         // reset lại biến đếm
        for (int j = i; j <= strlen(str); j++) // cho bằng để xét kí tự null
        {
            // ý tưởng là nếu gặp kí khoảng trắng sẽ xem biến đếm được bao nhiêu và cộng vào mảng nhưng chỉ cộng 1
            if (str[j] == '\0')
            {
                a[count] += 1;
                i = j;
                break;
            }
            if (str[j] == ' ')
            {
                a[count] += 1;
                i = j;
                break;
            }
            else
            {
                count++;
            }
        }
    }
    float sum_of_numerator = 0, sum_of_denominator = 0;
    for (int i = 0; i < 30; i++)
    {
        if (a[i] != 0) // chỉ xét những mảng lớn hơn 0
        {
            sum_of_numerator += a[i] * i;
            sum_of_denominator += i;
        }
    }
    return sum_of_numerator / sum_of_denominator;
}