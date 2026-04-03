/*Write a program to swap two integer arrays.  
Function prototype:
void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[n], int b[n]);*/
#include<stdio.h>
void read_array(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void print_array(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
void swap_array(int n,int a[n],int b[n])
{
    for(int i=0;i<n;i++)
    {
        int temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}
int main()
{
    int n;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n],b[n];
    printf("Enter array 1: ");
    read_array(n,a);
    printf("Enter array 2: ");
    read_array(n,b);
    swap_array(n,a,b);
    printf("Before swapping : %d\n",a[0]);
    printf("Array 1, element 0 after swapping: %d\n",a[0]);
    printf("Array 2, element 0 after swapping: %d\n",b[0]);
    return 0;
}