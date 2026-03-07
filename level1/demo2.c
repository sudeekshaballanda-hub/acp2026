/*Write a C program to compare areas of three rectangles and find the largest using functions and structure. (else-if ladder)
typedef struct {
    	char name[50];
    	float length;
    	float width;
    	float area;
} Rectangle;
Function prototype:
Rectangle input();
float calculate_area(Rectangle rect);
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);
*/
#include<stdio.h>
typedef struct {
    char name[50];
    float length;
    float width;
    float area;
} Rectangle;
Rectangle input()
{
    Rectangle r;
    {
        printf("\nEnter Name of the rectangle : ");
        scanf("%s",r.name);
        printf("\nEnter Length : ");
        scanf("%f",&r.length);
        printf("\nEnter width : ");
        scanf("%f",&r.width);
    }
    return r;
}
float calculate_area(Rectangle r)
{
    float area;
    area=r.length*r.width;
    return area;
}
void compare_areas(Rectangle r1,Rectangle r2,Rectangle r3)
{
    if(r1.area>r2.area && r1.area>r3.area)
    printf("%s is greater",r1.name);
    else if(r2.area>r1.area && r2.area>r3.area)
    printf("%s is greater",r2.name);
    else
    printf("%s is greater",r3.name);
}
int main()
{
    Rectangle r1,r2,r3;
    r1=input();
    r2=input();
    r3=input();
    r1.area=calculate_area(r1);
    r2.area=calculate_area(r2);
    r3.area=calculate_area(r3);
    compare_areas(r1,r2,r3);
    return 0;
}
