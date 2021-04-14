/*
This program checks if a string is palindrome using recursion.
*/
#include<stdio.h>
#include<string.h>

int is_palindrome(char arr[20], char rev_arr[20],int indx)
{
    int count = 0;
    if (arr[indx] == rev_arr[indx])
    {
        //printf("%c %c\n",arr[indx],rev_arr[indx]);
        count += 1;

        if (indx == strlen(arr))
        {
            if (count == strlen(arr))
            {
                return 1;
            }
        }

        else if (indx < strlen(arr))
        {
            return is_palindrome(arr, rev_arr, indx + 1);
        }
    }

    else
    {
        return 0;
    }

}

int main()
{
    int val;
    char arr[20],dup[20];
    gets(arr);
    strcpy(dup, arr);
    
    val = is_palindrome(arr, strrev(dup), 0);
    
    if(val == 1)
    {
        printf("String is a palindrome\n");
    }
    else{
        printf("String is not a palindrome\n");
    }
    return 0;
}