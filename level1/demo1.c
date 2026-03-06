/*
Write a modular C program to read n float values from the user, store them in an array and find the maximum value and its index. (array, passing arrays to functions, for loop, if statement)
Function prototype:
void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[ ], int max_index);
*/
#include<stdio.h>
void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[ ], int max_index);

void input(int n,float arr[n])
{
    for(int i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }
}
int find_max_index(int n,float arr[n])
{
    int max_index=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[max_index])
        {
            max_index=i;
        }
    }
    return max_index;
}
void output(float arr[],int max_index)
{
    printf("maximum index is %d",max_index);
}
int main()
{
    int n;
    float arr[100];
    int largest;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    input(n,arr);
    largest=find_max_index(n,arr);
    output(arr,largest);
    return 0;
}