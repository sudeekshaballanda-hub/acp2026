/*Write a C program to compare two strings using user-defined functions. The program should return:
•	0 if both strings are equal
•	1 if the first string is lexicographically greater
•	-1 if the second string is lexicographically greater
Function prototype:
void inputStrings(char str1[], char str2[]);
int compareStrings(char str1[], char str2[]);
void output(int result);
*/

#include<stdio.h>
void inputStrings(char str1[],char str2[])
{
    printf("Enter string 1: ");
    fgets(str1,100,stdin);
    printf("Enter string 2: ");
    fgets(str2,100,stdin);
}
int compareStrings(char str1[],char str2[])
{
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0')
    {
        if(str1[i]==str2[i])
        i++;
        else if(str1[i]>str2[i])
        return 1;
        else
        return -1;
    }
    if(str1[i]=='\0' && str2[i]=='\0')
    return 0;
    else if(str1[i]=='\0')
    return -1;
    else
    return 1;
}
void output(int result)
{
    if(result==0)
    printf("Both strings are equal\n");
    else if(result==1)
    printf("str1 is greater\n");
    else
    printf("str2 is greater\n");
}
int main()
{
    int n;
    char str1[100],str2[100];

    inputStrings(str1,str2);
    int result=compareStrings(str1,str2);
    output(result);
    return 0;
}