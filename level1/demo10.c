/*Write a modular C program to perform the following tasks using file handling functions:
i.	Read the details of n students from the user and store them in an array of structures
ii.	Write the array of structures to a binary file using fwrite().
iii.	Read the binary file into a second array of structures using fread().
iv.	Display the array of structures.
Function prototype:*/
#include<stdio.h>

typedef struct {
    int roll_no;
    char name[50];
    int marks;
}Student;

void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, const char *filename);
int readFromBinaryFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

void inputStudents(Student students[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter details of student %d:\n",i+1);
        printf("Enter Roll no.:");
        scanf("%d",&students[i].roll_no);
        printf("Enter name:");
        scanf("%s",students[i].name);
        printf("Enter marks:");
        scanf("%d",&students[i].marks);
    }
}
void writeToBinaryFile(Student students[],int n,const char *filename)
{
    FILE *file=fopen(filename,"wb");
    if(file==NULL)
    {
        printf("Error opening this file!\n");
    }
    fwrite(students,sizeof(Student),n,file);
    fclose(file);
}
int readFromBinaryFile(Student students[],const char *filename)
{
    FILE *file=fopen(filename,"rb");
    if(file==NULL)
    {
        printf("Error opening this file!\n");
        return 0;
    }
    int count=fread(students,sizeof(Student),100,file);
    fclose(file);
    return count;
}
void printStudents(Student students[],int n)
{
    printf("-------------Student Details-------------\n");
    for(int i=0;i<n;i++)
    {
        printf("Student %d:\n",i+1);
        printf("Roll NO.: %d\n",students[i].roll_no);
        printf("Name: %s\n",students[i].name);
        printf("Marks: %d\n",students[i].marks);
        printf("-------------------------------------------\n");
    }
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    Student students[n];
    inputStudents(students,n);
    writeToBinaryFile(students,n,"students.bin");
    int count=readFromBinaryFile(students,"students.bin");
    printStudents(students,n);
    return 0;
}
