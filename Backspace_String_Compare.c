//https://leetcode.com/problems/backspace-string-compare/
#include <stdio.h>
#include <string.h>
void checkS(char s1[]);
int Check(char s1[], char s2[]);
int main()
{
    char s1[100], s2[100];
    printf("nhap chuoi 1: ");
    gets_s(s1, sizeof(s1));
    printf("nhap chuoi 2: ");
    gets_s(s2, sizeof(s2));
    checkS(s1);
    checkS(s2);
    printf("-------------------------\n");
    printf("chuoi thu nhat sau kiem tra %s", s1);
    printf("\nchuoi thu hai sau kiem tra %s\n", s2);
    if (Check(s1, s2))
        printf("TRUE");
    else
        printf("FALSE");
    return 0;
}
void checkS(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[0] == '#') // xét nếu vị trí đầu tiên có "#" thì sẽ xóa vị trí đầu tiên mà k xóa chữ
        {
            for (int j = 0; j < strlen(s); j++)
            {
                s[j] = s[j + 1];
            }
            i--;
        }
        else
        {
            if (s[i] == '#')
            {
                for (int j = i; j < strlen(s); j++)
                {
                    s[j - 1] = s[j + 1]; // xóa kí tự tại vị trí j và cập nhật lại mảng
                }
                i -= 2;
            }
        }
    }
}
int Check(char s1[], char s2[])
{
    int count = 0;
    if (strlen(s1) != strlen(s2))
    {
        return 'F';
    }
    else
    {
        for (int i = 0; i < strlen(s1); i++)
        {
            if (s1[i] != s2[i])
            {
                break;
            }
            else
                count++;
        }
        if (count == strlen(s1))
            return 1;
    }
=======
// Example 1:
// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

// Example 2:
// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".

// Example 3:
// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".
#include <stdio.h>
#include <string.h>
void checkS(char s1[]);
int Check(char s1[], char s2[]);
int main()
{
    char s1[100], s2[100];
    printf("nhap chuoi 1: ");
    gets_s(s1, sizeof(s1));
    printf("nhap chuoi 2: ");
    gets_s(s2, sizeof(s2));
    checkS(s1);
    checkS(s2);
    printf("-------------------------\n");
    printf("chuoi thu nhat sau kiem tra %s", s1);
    printf("\nchuoi thu hai sau kiem tra %s\n", s2);
    if (Check(s1, s2))
        printf("TRUE");
    else
        printf("FALSE");
    return 0;
}
void checkS(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[0] == '#') // xét nếu vị trí đầu tiên có "#" thì sẽ xóa vị trí đầu tiên mà k xóa chữ
        {
            for (int j = 0; j < strlen(s); j++)
            {
                s[j] = s[j + 1];
            }
            i--;
        }
        else
        {
            if (s[i] == '#')
            {
                for (int j = i; j < strlen(s); j++)
                {
                    s[j - 1] = s[j + 1]; // xóa kí tự tại vị trí j và cập nhật lại mảng
                }
                i -= 2;
            }
        }
    }
}
int Check(char s1[], char s2[])
{
    int count = 0;
    if (strlen(s1) != strlen(s2))
    {
        return 'F';
    }
    else
    {
        for (int i = 0; i < strlen(s1); i++)
        {
            if (s1[i] != s2[i])
            {
                break;
            }
            else
                count++;
        }
        if (count == strlen(s1))
            return 1;
    }
>>>>>>> 23d5441593ad6ac2e06e12eca03392945c57d39b
}
