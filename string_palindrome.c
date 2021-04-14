/*
This program checks if a given string is a palindrome or not
*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,len;
    char arr[50], dup[20];
    gets(arr); //or scanf("%[^\n%*c",str)
    strcpy(dup,arr);

    if(strcmp(strrev(arr),dup) == 0)
    {
        printf("%s is a palindrome",dup);
    }
    else
    {
        printf("%s is not a palindrome",dup);
    }
    return 0;
}