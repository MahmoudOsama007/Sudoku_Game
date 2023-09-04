#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <string.h>
#include <time.h>







int arr[9][9];
int raw=0;
int col=0;
int num=0;

int random_number(int min, int max);
void print_2d_array(int arr[9][9]);
void check_num(int *num);
void set_2d_array(int arr[9][9]);
void delay_func(void);
void edit_2d_array(int arr[9][9],int raw,int col,int num);
void start_Screen(void);



//printf(“\033[0;33m”); //set the text to Yellow color
//printf("\033[0m"); // Reset the text to default color


int main()
{

    start_Screen();
    set_2d_array(arr);


    while(1)
    {
        print_2d_array(arr);
        printf("\nEnter The Raw = ");
        check_num(&raw);


        printf("\nEnter The Col = ");
        check_num(&col);

        printf("\nEnter The Number = ");
        check_num(&num);

        edit_2d_array(arr,raw,col,num);

    }

    return 0;

}















/***
 // Generate and print a random number between 1 and 9
    int number = random_number(1, 9);
    printf("Random number: %d\n", number);

***/


int random_number(int min, int max)
{

    return min + rand() % (max - min + 1);
}
// Seed the random number generator



void print_2d_array(int arr[9][9])
{
    system("cls");// Clear display before printing the array

    printf("\n\n\n\n\n");

    // Print the first row with the column indices
    printf("    ");
    printf("\t\t    ");//Space For Colums number raw

    for(int j = 0; j < 9; j++)
    {
        if(j % 3 == 0)
        {
            printf(" ");
        }
        printf("\033[0;33m%2d  ", j+1);
        printf("\033[0m");
    }
    printf("\n\n");
    printf("\t\t");//Space For ----- raw
    printf("\033[0;33m   --------------------------------------\n");
    printf("\033[0m"); // Reset the text to default color
    // Loop through each row of the array
    for(int i = 0; i < 9; i++)
    {
        if(i % 3 == 0 && i!=0)
        {
            printf("\t\t");//Space For ----- raw
            printf("\033[0;33m   --------------------------------------\n");
            printf("\033[0m"); // Reset the text to default color
        }
        // Print the row index
        printf("\t\t");
        printf("\033[0;33m%d   ", i+1);
        printf("\033[0m");



        // Loop through each column of the array
        for(int j = 0; j < 9; j++)
        {
            if(j % 3 == 0)
            {
                printf("\033[0;33m|");
                printf("\033[0m"); // Reset the text to default color
            }

            if((i==5 && j==1)||(i==4 && j==0)||(i==6 && j==2)||(i==3 && j==3)||(i==8 && j==6)||(i==2 && j==4)||(i==1 && j==5)||(i==0 && j==8)||(i==7 && j==7))
            {
                printf("\033[0;33m%2c  ", arr[i][j]);
                printf("\033[0m"); // Reset the text to default color
                continue;
            }


            // Print the array element
            printf("%2c  ", arr[i][j]);
        }


        // Print a newline after each row
        printf("\n");

    }
    printf("\t\t");//Space For ----- raw
    printf("\033[0;33m   --------------------------------------\n");
    printf("\033[0m"); // Reset the text to default color
    printf("\n\t\t\tYou Can Log Out Any Time by insert  0 \n\n");
}



void check_num(int *num)
{
    // Declare a variable to store the number
    int x;

    // Scan the number from the standard input
    scanf("%d", &x);
    if(x==0)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tThank You,See you soon.");
        Sleep(5000);
        exit(1);

    }

    while((x < 1 || x > 9) )
    {
        // Print an error message
        printf("\nNot valid.Please Try a number from 1 to 9: ");
        // Scan another number from the standard input
        fflush(stdin);
        scanf("%d", &x);

        while(getchar() != '\n');
    }

    // Assign the number to the pointer parameter
    *num = x;
}


void set_2d_array(int arr[9][9])
{

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            arr[i][j]=' ';
        }
    }

    arr[5][1]=random_number(1, 9)+'0';
    srand(time(NULL));
    arr[4][0]=random_number(1, 9)+'0';
    arr[6][2]=random_number(1, 9)+'0';
    arr[3][3]=random_number(1, 9)+'0';
    arr[8][6]=random_number(1, 9)+'0';
    arr[2][4]=random_number(1, 9)+'0';
    srand(time(NULL));
    arr[1][5]=random_number(1, 9)+'0';
    arr[0][8]=random_number(1, 9)+'0';
    arr[7][7]=random_number(1, 9)+'0';
}

void delay_func(void)
{

    printf("\nTry Again in ");
    for(char z =4; z>0; z--)
    {
        printf("\033[0;33m%d  ",z);
        sleep(1); // Pause for 1 seconds
    }

    printf("\033[0m"); // Reset the text to default color

}

static int flag=0;
void edit_2d_array(int arr[9][9],int raw,int col,int num)
{
    flag=0;

    for(int i =0; i<9 ; i++)
    {
        if(arr[i][col-1]==num+'0')  // Do not subtract 1 from i and col
        {
            flag=1; // Set flag to 1 if number is found
            break; // Break out of the loop
        }
    }
    if(flag==1)
    {
        printf("\nThis Number wrote before try another one between 1 and 9");
        delay_func();
    }
    else if(flag==0 && arr[raw-1][col-1]==' ')
    {
        arr[raw-1][col-1]=num+'0';
    }
}



void start_Screen(void)
{
    char s[]= {'L','o','a','d','i','n','g','.','.','.','\0'};
    printf("\t");

//7 8 9
    for(int i =0; i<3; i++)
    {
        printf("\n\n");

        for(int i =0; s[i]; i++)
        {
            printf("\t%3c",s[i]);
            Sleep(50);
        }
        Sleep(500);
        system("cls");
    }


    char s1[]= {'W','e','l','c','o','m','e','\0'};
    printf("\t");
    for(int i =0; i<1; i++)
    {
        printf("\n");

        for(int i =0; s1[i]; i++)
        {
            if(i==0)
            {
                printf("\t\t\t\t\t\t");
            }
            printf("%c",s1[i]);
            Sleep(50);
        }
        Sleep(1000);
        printf("\n\n\n");
    }

    char s3[]="  To The Sudoku Game";
    printf("\t");
    for(int i =0; i<1; i++)
    {

        printf("\n");

        for(int i =0; s3[i]; i++)
        {
            if(i==0)
            {
                printf("\t\t\t\t\t");
            }
            printf("%c",s3[i]);
            Sleep(50);
        }
        Sleep(1000);
        printf("\n\n\n\n");
    }
    char s4[]="Engoy ^_^";
    printf("\t");
    for(int i =0; i<1; i++)
    {

        printf("\n");

        for(int i =0; s4[i]; i++)
        {
            if(i==0)
            {
                printf("\t\t\t\t\t\t");
            }
            printf("%c",s4[i]);
            Sleep(50);
        }
        Sleep(1000);
        printf("\n\n\n\n\n");

    }
    char s5[]=" Designed By Mahmoud Osama {Techosphy}";
    printf("\n");
    for(int i =0; i<1; i++)
    {
        printf("\t\t\t\t");

        for(int i =0; s5[i]; i++)
        {
            if(i==0)
            {
                printf("\t\t\t\t\t\t");
            }
            printf("%c",s5[i]);
            Sleep(50);
        }
        Sleep(1000);
        printf("\n\n\n\n\n");
        system("cls");
    }

}



