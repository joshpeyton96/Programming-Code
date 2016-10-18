/*
Assignment
Program with persistent data
Joshua Peyton
C14348526
Part 2 - Implement a text menu. 
*/
#include <stdio.h>
#include <conio.h>//used for clear screen
#include <stdlib.h>
#include <string.h>
#define SIZE 10000
struct record
    {
        char team1[20], team2[20];
        int score1, score2;
    };
    struct record matches;
    //Declaring functions
    //Prototypes
    //Each function passes the structure matches down
    void convertTxt(struct record matches);
    void displayLeagueTable();
    void newResult(struct record matches);
    void highestNumofGoals(struct record matches);
    void matchesofTeam();
    void displayResults(struct record matches);
    main()
{
    int option;// int variable so the user can chose an option from the text menu
        
      int menu_separator;
    {
        do
        {/*MAIN MENU*/
            for(menu_separator=80; menu_separator>0; menu_separator--)//Used to separate text me menu
                {
                    printf(".");
                }//end for loop
                /*end for- 80 full stops will display horizontally across  the screen which will hold the text menu*/
                printf("\n1. Convert the matches.txt to matches.bin.\n");
                /*(MENU)-This option displays the League Table*/
      
                printf("\n2. Display the League Table.\n");
                /*(MENU)-This option displays the League Table*/
      
                printf("\n3. Enter a new result.\n");
                /*(MENU)-This option allows the user to enter a new result*/
      
                printf("\n4. Display the matches with highest number of goals scored.\n");
                /*(MENU)-This option displays matches with the highest number of goals scored*/
      
                printf("\n5. Enter a team to display their results.\n");
                /*(MENU)-This option asks user for a team to display their results*/
                
                printf("\n6. Display the results of the 180 matches.\n");
                /*(MENU)-This option displays the results of the 180 matches*/
                
                printf("\n7. Exit Program\n.");
                /*(MENU)-This option simply closes the program*/

                for(menu_separator=80; menu_separator>0; menu_separator--)
                    {
                        printf(".");
                    }//end for loop
                    /*end for- //end for()- 80 full stops will display horizontally across  the screen which will hold the main menu*/
                    
                    printf("Please enter one of the options between 1-5 in the main menu.\n=");
                    /*'option' integer is scanned so whatever number is entered by the user this will equal to the 'option' variable*/
                    
                    scanf("%d", &option);
                    
                    if(option<1||option>6)
                    {
                        printf("You must choose an option between 1-6!\n");
                        printf("\nPlease press enter to try again.\n");
                        /* Error checking so that the user can only enter a number between 1-5*/
                        getchar();
                    }//end for
                    getchar();
                    clrscr();
                    
                    
    //if 1 is entered by user for the text menu then this function is called
    if(option == 1)
    {
        //call function
        convertTxt(matches);//Global struct passed down
        printf("\n\nPlease press enter to continue to the Text Menu.\n");
        clrscr();
    }

    //if 3 is entered by user for the text menu then this function is called
    if(option == 2)
    {
        //call function
        displayLeagueTable();//Global struct passed down and pointer
        printf("\n\nPlease press enter to continue to the Text Menu.\n");
        clrscr();
    }
    
    //if 4 is entered by user for the text menu then this function is called
    if(option == 3)
    {
        //call function
        newResult(matches);//Global struct passed down and pointer
        printf("\n\nPlease press enter to continue to the Text Menu.\n");
        clrscr();
    }
    
    //if 5 is entered by user for the text menu then this function is called
    if(option == 4)
    {
        //call function
        highestNumofGoals(matches);//Global struct passed down and pointer
        printf("\n\nPlease press enter to continue to the Text Menu.\n");
        clrscr();
    }
    
    //if 6 is entered by user for the text menu then this function is called
    if(option == 5)
    {
        //call function
        matchesofTeam();//Global struct passed down and pointer
        printf("\n\nPlease press enter to continue to the Text Menu.\n");
        clrscr();
    }
    
      //if 2 is entered by user for the text menu then this function is called
    if(option == 6)
    {
        //call function
        displayResults(matches);//Global struct passed down and pointer
        printf("\n\nPlease press enter to continue to the Text Menu.\n");
        clrscr();
    }
}//end do loop

while(option!=7);//The main menu will continuously display until the user enters option 6 to exit program
}//end while loop

}//end main

void convertTxt(struct record matches)
{
    FILE *fp = fopen("matches.txt", "r");//opening the txt file in read mode
    FILE *fp2 = fopen("matches.bin", "wb");//opening the binary file in read + write mode
    
    if(fp == NULL)
    {
        printf("File Error\n");
        getchar();
    }//Checking if there is data in the file
   
    //while not end of file    
    //fscanf used to read data from txt file into pointer
    while (fscanf(fp, "%[^,] , %[^,] , %i , %i",matches.team1, matches.team2,&matches.score1, &matches.score2) != EOF)
    {
        fwrite(&matches, sizeof(matches), 1, fp2);
        //writing data from file to .bin
    }
    printf("You have successfully converted the matches.txt to matches.bin\n");
    getchar();
}

/*function definition*/
void displayLeagueTable()
{
    struct record matches[180];
    //An array of strings to store the 10 teams 
    char *teams[10];
    
    //Int array to store the goals scored for each team 
    int scored[10]= {0};
    
    //Int array to store the goals conceded for each team 
    int conceded[10]={0};
    
    //Int array to store the goals points for each team 
    int points[10]={0};
    
    //used to display position of each team in the league
    int pos = 0;
    
    //Initialising each element of the array with one of the ten teams in the league
    teams[0] = "Liverpool     ";
    teams[1] = "Inter Milan   ";
    teams[2] = "Juventus      ";
    teams[3] = "Chelsea       ";
    teams[4] = "Manchester Utd";
    teams[5] = "Real Madrid   ";
    teams[6] = "Barcalona     ";
    teams[7] = "PSG           ";
    teams[8] = "Porto         ";
    teams[9] = "Bayern Munich ";    
    int i = 0;
    
    FILE *fp = fopen("matches.bin", "rb");//opening the binary file in reading mode
    
    if(fp==NULL)
    {
        printf("File Error\n");
    }//Checking if there is data in the file
    
       while(!feof (fp))
    {
        fread(&matches,sizeof(record),1,fp);//reads each element in the file
        /*Compare string function used in an if statement to calculate the goals scored, 
                   conceded and points gained by the team in this element of the array of strings*/
        if(strncmp(matches[i].team1, teams[0], 20)==0)
            {
                scored[0] = scored[0] + matches[i].score1;
                conceded[0] = conceded[0] + matches[i].score2;
                if(matches[i].score1 > matches[i].score2)
                {
                    points[0] = points[0] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[0] = points[0] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                         conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[1] , 20)==0)
            {
                scored[1] = scored[1] + matches[i].score1;
                conceded[1] = conceded[1] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[1] = points[1] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[1] = points[1] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                   conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[2], 20)==0)
            {
                scored[2] = scored[2] + matches[i].score1;
                conceded[2] = conceded[2] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[2] = points[2] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[2] = points[2] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                   conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[3], 20)==0)
            {
                scored[3] = scored[3] + matches[i].score1;
                conceded[3] = conceded[3] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[3] = points[3] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[3] = points[3] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                   conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[4], 20)==0)
            {
                scored[4] = scored[4] + matches[i].score1;
                conceded[4] = conceded[4] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[4] = points[4] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[4] = points[4] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                   conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[5], 20)==0)
            {
                scored[5] = scored[5] + matches[i].score1;
                conceded[5] = conceded[5] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[5] = points[5] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[5] = points[5] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                   conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[6], 20)==0)
            {
                scored[6] = scored[6] + matches[i].score1;
                conceded[6] = conceded[6] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[6] = points[6] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[6] = points[6] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                   conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[7], 20)==0)
            {
                scored[7] = scored[7] + matches[i].score1;
                conceded[7] = conceded[7] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[7] = points[7] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[7] = points[7] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                   conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[8], 20)==0)
            {
                scored[8] = scored[8] + matches[i].score1;
                conceded[8] = conceded[8] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[8] = points[8] + 3;
                }
                else
                     if(matches[i].score1 == matches[i].score2)
                {
                    points[8] = points[8] + 1;
                }
            }
            /*Compare string function used in an if statement to calculate the goals scored, 
                      conceded and points gained by the team in this element of the array of strings*/
            if(strncmp(matches[i].team1, teams[9], 20)==0)
            {
                scored[9] = scored[9] + matches[i].score1;
                conceded[9] = conceded[9] + matches[i].score2;
                 if(matches[i].score1 > matches[i].score2)
                {
                    points[9] = points[9] + 3;
                }
                    if(matches[i].score1 == matches[i].score2)
                {
                    points[9] = points[9] + 1;
                }
            }
            i++;
    }
    
    fclose(fp);
    fp = fopen("matches.bin", "rb");
    
    printf("\n\nLeague Table\n");
    printf("------------\n");
    printf("Teams                 Points         Goals Scored       Goals Conceded\n\n");
    
  //For loop to display League Table
  for(i=0; i<10; i++)
  {
      pos++;
      
      printf("%d. ", pos);
      
      printf("%s",teams[i]);//Displaying array with first ten home teams
      
      printf("     %d,             %d,                   %d\n",points[i], scored[i], conceded[i]);//Displaying arrays with points, goals scored and conceded for each team
  }
   
    fclose(fp);
    getchar();
}
/*function definition*/
void newResult(struct record matches)
{
    char result[20];//String used to enter a new result
        
    FILE *fp = fopen("matches.bin", "rb");//opening the binary file in reading mode
    
      if(fp==NULL)
    {
        printf("File Error\n");
    }//Checking if there is data in the file
    
    //The result entered by user is the string 'result'
    printf("Enter the new result of a match in the format(Team A, Team B,Goals A,Goals B)\n");
    gets(result);
    
    //writing the string to the file
    fputs(result, fp);
    
    //displaying match entered
    printf("The match you have entered is %s\n", result);
    
    //using fread to read the file 
    fread( &matches,sizeof(matches),1,fp);//reads each element in the file
    
    fclose(fp);
    
    getchar();
}
/*function definition*/
void highestNumofGoals(struct record matches)
{
    FILE *fp = fopen("matches.bin", "rb");//opening the binary file in reading mode
    
      if(fp==NULL)
    {
        printf("File Error\n");
    }//Checking if there is data in the file
    
    printf("The matches with the most goals scored were:\n");
   
    //using fread to read the file 
     while( !feof(fp))//this while loop won't end until end of file 
    {
        fread( &matches,sizeof(matches),1,fp);//reads each element in the file
        //The printf inside the if statement only executes if the if statement is true
        //This if is used to display the matches with the highest amount of goals
        if(matches.score1 + matches.score2 >= 7)
        {
            printf("%s, %s,%i,%i\n", matches.team1, matches.team2, matches.score1, matches.score2);
        }
    }

    fclose(fp);
    
    getchar();
}    
/*function definition*/
void matchesofTeam()
{
    struct record matches[180];
    char team[20];//String used to display results of a single team
    int i = 0;
    
    FILE *fp = fopen("matches.bin", "rb");//open binary file in reading mode
    
      if(fp==NULL)
    {
        printf("File Error\n");
    }//Check that there is data in file
    
    //The team entered by user is the string 'team'
    printf("Please enter a team to see their results\n");
    gets(team);
   
    //using fread to read the file 
     while( !feof(fp))//this while loop won't end until end of file 
    {
        fread(&matches,sizeof(record),1,fp);//reads each element in the file
        //if statement to display results of the team enter by user
        if(strncmp(matches[i].team1, team, 20)==0)
            {
                printf("%s, %s,%i,%i\n", matches[i].team1, matches[i].team2, matches[i].score1, matches[i].score2);
            } 
            i++;
    }
    fclose(fp);
    
    getchar();
} 

/*Function definition*/
void displayResults(struct record matches)
{
    FILE *fp = fopen("matches.bin", "rb");//opening the binary file in reading mode
    
    if(fp == NULL)
    {
        printf("File Error\n");
        getchar();
    }//Checking if there is data in the file
   
    while( !feof(fp))//this while loop won't end until end of file 
    {
        fread(&matches,sizeof(matches),1,fp);//reads each element in the file
        
        //printing the data in the file
        printf("%s, ", matches.team1);
        
        printf("%s,", matches.team2);
        
        printf("%d,", matches.score1);
        
        printf("%d,", matches.score2);
    }//this while will display everything in the file downloaded
    fclose(fp);//close file
    
    getchar();
}