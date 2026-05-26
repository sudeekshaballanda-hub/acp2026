#include <stdio.h>
#include <string.h>

/* Function Declarations */
void readString(char str[]);

void removeNewline(char str[]);

int getLength(char str[]);

int findPattern(char str[], char pat[], int start);

int replacePattern(char str[], char pat[], char rep[], char result[]);

void displayResult(int flag, char result[]);

int main() {

    char str[200], pat[100], rep[100];
    int start;
    char result[200];
    int flag;
    int pos;
    
    
    printf("Enter the string: ");
    fgets(str,sizeof(str),stdin);

    printf("Enter the pattern: ");
    fgets(pat,sizeof(pat),stdin);

    printf("Enter the replacement: ");
    fgets(rep,sizeof(rep),stdin);
    
    removeNewline(str);
    removeNewline(pat);
    removeNewline(rep);
    
    int length=getLength(str);
    pos=findPattern(str,pat,start);
    flag=replacePattern(str,pat,rep,result);
    displayResult(flag,result);
    
    return 0;
}

/* Function to read string 
void readString(char str[]) {
    
}*/

/* User-defined function to remove newline character */
void removeNewline(char str[]) {
    str[strcspn(str,"\n")]='\0';
}

/* Function to find string length */
int getLength(char str[]) {
    int length=strlen(str);
    return length;
}

/* Function to check pattern match */
int findPattern(char str[], char pat[], int start) {

for(int i=0;i<strlen(str)-strlen(pat);i++)
{
    int k=i;
    int j=0;
    while(j<strlen(str)&&str[k]==pat[j])
    {
        k++;
        j++;
    }
    if(j==strlen(pat))
    {
        return i;
    }
}
return -1;
}


/* Function to replace pattern */
int replacePattern(char str[], char pat[], char rep[], char result[]) {
      int i=0,j=0;
      int strLen=strlen(str);
      int patLen=strlen(pat);
      int repLen=strlen(rep);
      int flag=0;
      while(i<strLen)
      {
          if(strncmp(&str[i],pat,patLen)==0)
          {
              strcpy(&result[j],rep);
              j+=repLen;
              i+=patLen;
              flag=1;
          }
          else
          {
              result[j]=str[i];
              j++;
              i++;
          }
          
      }
      result[j]='\0';
      return flag;
}

/* Function to display result */
void displayResult(int flag, char result[]) {

    if (flag==0) 
        printf("Pattern does not exist");
    else 
        printf("The main string after replacement is:%s\n",result);
}








