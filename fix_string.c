//intput "  dAng   hOAng   KHANG   "
//output "Dang Hoang Khang"
#include <stdio.h>
#include <string.h>
// khai báo nguyên mẫu hàm
void Check_And_Delete__Space_In_Begin_And_End_Of_String(char *str);
void Check_And_Delete__Space_Inside_Of_String(char *str);
void Upper_And_Lower_Inside_String(char *str);
// hàm main
int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    Check_And_Delete__Space_In_Begin_And_End_Of_String(str);
    Check_And_Delete__Space_Inside_Of_String(str);
    Upper_And_Lower_Inside_String(str);
    printf("%s", str);
    printf("\nso luong ki tu cua chuoi sau khi output la %d ki tu", strlen(str));
    return 0;
}
void Check_And_Delete__Space_In_Begin_And_End_Of_String(char *str) // xóa khoảng trắng 2 đầu của chuỗi
{
    // xóa khoảng trắng từ s[0] đến chữ cái đầu tiên
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            strncpy(str, str + (i + 1), strlen(str) - 1);
            str[strlen(str) - 1] = '\0';
            i--; // kiểm tra lại vị trí có khoảng trắng vừa xóa
        }
        else
            break;
    }
    // xóa khoảng trắng từ chữ cái cuối cùng đến khi gặp chữ cái đầu tiên từ dưới lên
    for (int i = strlen(str); i > 0; i--)
    {
        if (str[i - 1] == ' ')
        {
            strncpy(str, str, strlen(str) - 1);
            str[strlen(str) - 1] = '\0';
        }
        else
            break;
    }
}
void Check_And_Delete__Space_Inside_Of_String(char *str) // xóa khoảng trắng bên trong chuỗi
{
    char str1[100], str2[100]; // dùng 2 chuỗi mới để coppy, sau đó xóa khoảng trắng
    for (int i = 0; i < strlen(str); i++)
    {
        int count = 0;
        for (int j = i; j < strlen(str); j++)
        {
            if (str[j] == ' ')
            {
                count++; // nếu gặp khoảng trắng sẽ cộng dồn lại
            }
            else
            {
                i = j; // dùng i=j để tránh việc không cập nhật lại giá trị i
                break;
            }
        }
        if (count > 1) // chỉ xóa khoảng trắng nếu có nhiều hơn 1 khoảng trắng
        {
            strncpy(str1, str + 0, i - count);       // nối chuỗi từ đầu đến khoảng trắng, không lấy khoảng trắng
            str1[i - count] = '\0';                  // để kí tự cuối cùng là '\0' tránh lỗi chuỗi
            strncpy(str2, str + i, strlen(str) - i); // lấy từ chữ cái không có khoảng trắng
            str2[strlen(str) - i] = '\0';            // để kí tự cuối cùng là '\0' tránh lỗi chuỗi
            strcat(str1, " ");                       // nối chuỗi str1 và khoảng trắng
            strcpy(str, strcat(str1, str2));         // nối str1 và str2 lại để coppy lại vào str và cập nhật lại chuỗi str mới
        }
    }
}
void Upper_And_Lower_Inside_String(char *str) // viết hoa chữ kế khoảng trắng và viết thường chữ trong chuỗi
{
    char slwr[2], supr[2]; // khai báo 2 chuỗi với để chứa 1 kí tự chữ và 1 kí tự null
    for (int i = 0; i < strlen(str); i++)
    {
        if (i == 0) // nếu i=0 thì sẽ viết hoa vị trí str[0]
        {
            strncpy(supr, str + i, 1);
            supr[1] = '\0';
            strupr(supr);
            str[i] = supr[0];
        }
        else // ngược lại sẽ vô kt
        {
            if (str[i] == ' ')
            {
                strncpy(supr, str + (i + 1), 1); // coppy vị trí str[i+1] vì nó là chữ kế khoảng trắng
                supr[1] = '\0';                  // thêm kí tự null vào tránh lỗi
                strupr(supr);                    // dùng hàm in hoa để in hoa chuỗi supr
                str[i + 1] = supr[0];            // thay thế vị trí str[i+1] bằng kí tự đã được in hoa
                i += 1;                          // xét vị trí str[i+2] tiếp theo
            }
            else
            {
                strncpy(slwr, str + i, 1); // tương tự bên trên
                slwr[1] = '\0';
                strlwr(slwr);
                str[i] = slwr[0];
            }
        }
    }
}