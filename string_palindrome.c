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
    strcpy(dup,arr);    //copies original arr string to dup string

    if(strcmp(strrev(arr),dup) == 0)    // this line compares reversed string and original str
    {
        printf("%s is a palindrome",dup);
    }
    else
    {
        printf("%s is not a palindrome",dup);
    }
    return 0;
}