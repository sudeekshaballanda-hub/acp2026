/*Write a C program using array of structures and functions to:
i.	Accept the number of rectangles.
ii.	For each rectangle, accept its length and width.
iii.	Calculate and display the area of each rectangle.
iv.	Determine and display the rectangle with the largest area. (array of structures, for loop, if statement)
typedef struct {
    	float length;
    	float width;
    	float area;
} Rectangle;
Function prototype:
void input(int n, Rectangle rects[n]);
void calculate_area(int n, Rectangle rects[n]);
int findLargestArea(int n, Rectangle rects[n]);
void output(int largestIndex, Rectangle rects[]);*/

#include<stdio.h>
typedef struct {
    char name[50];
    float length;
    float width;
    float area;
} Rectangle ;
void input(int n, Rectangle rect[n])
{
    for(int i=0;i<n;i++)
    {
        printf("Enter details of rectangle %d : ",i+1);
        printf("Enter name : ");
        scanf("%s",rect[i].name);
        printf("Enter length: ");
        scanf("%f",&rect[i].length);
        printf("Enter width : ");
        scanf("%f",&rect[i].width);
    }
}
void calculate_area(int n,Rectangle rect[n])
{
    for(int i=0;i<n;i++)
    {
        rect[i].area=rect[i].length*rect[i].width;
    }
}
int findLargestArea(int n,Rectangle rect[n])
{
    int Largestindex=0;
    for(int i=1;i<n;i++)
    {
        if (rect[i].area>rect[Largestindex].area)
        Largestindex=i;
    }
    return Largestindex;
}
void output(int n,int LargestIndex,Rectangle rect[])
{
    for(int i=0;i<n;i++)
    {
        printf("Details of Rectangle %d\n",i+1);
        printf("Name: %s \n",rect[i].name);
        printf("Area : %f \n",rect[i].area);
    }
    printf("largest Rectangle is %s \n",rect[LargestIndex].name);
    printf("The Index of the largest Rectangle is %d\n",LargestIndex);
}
int main()
{
    Rectangle rect[100];
    int n,LargestIndex;
    printf("Enter n : ");
    scanf("%d",&n);
    input(n,rect);
    calculate_area(n,rect);
    LargestIndex=findLargestArea(n,rect);
    output(n,LargestIndex,rect); 
    return 0;  
}