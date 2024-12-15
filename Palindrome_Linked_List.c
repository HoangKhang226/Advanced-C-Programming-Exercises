//https://leetcode.com/problems/palindrome-linked-list/description/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} node;
int check_val(node *head,int position);
node *createnode(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}
void push_front(node **head, int x)
{
    node *newnode = createnode(x);
    newnode->next = *head;
    *head = newnode;
}
int input(node **head)
{
    int val,count=-1;
    printf("Enter values for a singly linked list (enter 0 to stop):\n ");
    while (1)
    {
        scanf("%d", &val);
        count++;
        if(count==0&&val==0)
        exit(0);
        if (val == 0)
            break;
        push_front(head, val);
    }
    return count;
}
node *reverse(node *head)
{
    node *prev = NULL, *curr = head, *next = NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int check_palindrome(node *head,int quantity)
{
    int left=1,right=quantity;
    while(left<right)
    {
        int left_val = check_val(head,left);
        int right_val=check_val(head,right);
        if(left_val!=right_val)
        return 0;
        left++;
        right--;
    }
    return 1;
}
int check_val(node *head,int position)
{
    for(int i=1;i<position;i++)//lấy giá trị trước nó 1 đơn vị
    head=head->next;
    return head->val;
}
void print(node *head)
{
    while (head != NULL)
    {
        printf("%d", head->val);
        head = head->next;
    }
}
int main()
{
    node *head = NULL;
    int quantity=input(&head);//nhập dslk từ bàn phím
    head=reverse(head);// đảo ngược chứ không dùng push back vì dùng push back sẽ tăng tg chạy code
    printf("singly linked list: ");
    print(head);//in dslk
    if(check_palindrome(head,quantity))//hàm KT
    printf("\nYES");
    else
    printf("\nNO");
    return 0;
}