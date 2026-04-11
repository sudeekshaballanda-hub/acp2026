/*Write a modular C program to perform the following tasks using file handling functions:
i.Read the details of n students from the user and store them in an array of structures.
ii.Write the array of structures to a text (ASCII) file using fprintf().
iii.Read the data back from the ASCII file into a second array using fscanf() and display it.
iv.Display the array of structures.
Function prototype:*/
#include<stdio.h>

typedef struct{
    int roll_no;
    char name[50];
    int marks;
}Student;

void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, const char *filename);
int readFromTextFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

 void inputStudents(Student students[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter details of student %d:\n",i+1);
        printf("Enter Roll no.: ");
        scanf("%d",&students[i].roll_no);
        printf("Enter name: ");
        scanf("%s",students[i].name);
        printf("Enter marks: ");
        scanf("%d",&students[i].marks);
    }
}
void writeToTextFile(Student students[], int n, const char *filename)
{
    FILE *file=fopen(filename,"w");
    if(file==NULL)
    {
        printf("Error opening file!\n");
    }
    for(int i=0;i<n;i++)
    {
        fprintf(file,"%d %s %d\n",students[i].roll_no,students[i].name,students[i].marks);
    }
    fclose(file);
}

int readFromTextFile(Student students[], const char *filename)
{
    FILE *file=fopen(filename,"r");
    if(file==NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }
    int i=0;
    while(fscanf(file,"%d %s %d",&students[i].roll_no,&students[i].name,&students[i].marks)==3)
    {
        i++;
    }
    fclose(file);
    return i;
}

void printStudents(Student students[], int n)
{
    printf("\n---------------Details of students-------------\n");
    for(int i=0;i<n;i++)
    {
        printf("Roll no.: %d\n",students[i].roll_no);
        printf("Name: %s\n",students[i].name);
        printf("Marks: %d\n",students[i].marks);
        printf("---------------------------------------------\n");
    }
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    Student students[n];
    inputStudents(students,n);
    writeToTextFile(students,n,"students.txt");
    int count=readFromTextFile(students,"students.txt");
    printStudents(students,count);
    return 0;
}

