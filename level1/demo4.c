/*Write a modular C program to create a structure Flight with flight_number, destination, and available_seats. 
Create an array of 4 flights. Write a program that takes a destination name from the user and checks if a flight is available to that location, displaying the flight number if found.
Function prototype:
void readFlights(int n, Flight f[]); 
void searchByDestination(int n, Flight_t f[], char searchDest[]);*/
#include<stdio.h>
#include<string.h>
typedef struct {
    int flight_number;
    char destination[50];
    int available_seats;
} Flight;
void readFlights(int n,Flight f[])
{
    for(int i=0;i<n;i++)
    {
        printf("Enter flight_number : ");
        scanf("%d",&f[i].flight_number);
        printf("Enter destination : ");
        scanf("%s",f[i].destination);
        printf("Enter available_seats : ");
        scanf("%d",&f[i].available_seats);
    }
}
void searchByDestination(int n,Flight f[],char searchDest[])
{
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(f[i].destination,searchDest)==0)
        {
        printf("Flight No. %d ",f[i].flight_number);
        found=1;
        }
    }
        if(found==0)
        printf("Not Found");
}
int main()
{
    int n;
    Flight f[50];
    char searchDest[50];
    printf("Enter n : ");
    scanf("%d",&n);
    readFlights(n,f);
    printf("Enter your Destination: ");
    scanf("%s",searchDest);
    searchByDestination(n,f,searchDest);
    return 0;
}