/*
Joshua Peyton
C14348526
Individual Assignment #2
24/02/2015- 11/03/2015
You are required to develop a program that 
will perform security authorisation based
on access codes. The user must be allowed to enter
a code, encrypt the code and compare it with 
the default authorised code and decrypt the 
code. They must be allowed see how many times they
entered a wrong code and the right code.
Separate functions must be used for each main menu
option and pass by reference must by used when passing 
parameters and pointer notation
must be used instead of subscripts.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#define FOUR 4
/*Declaring functions*/
/*Prototypes*/
void option_1(int *enter_code1, int *no_els);//function for option 1 on main menu,  three integers and an int array are passed down to function by pass by reference
void option_2(int *encrypt, int *no_els, int *access_code, int *correct_code, int *incorrect_code);
/*function for option 2 on main menu, two int arrays and three integers  are passed down to function by pass by reference*/
void option_3(int *decrypt, int *no_els);//function for option 3 on main menu, an array  and an int are passed down to the function by pass by reference
void option_4(int *correct, int *incorrect);//function for option 4 on main menu, two integers are passed down to the function by pass by reference
main()
{
    int access_code[]={4,5,2,3};//this is the default authorised access_code array given in the assignment question
    
    int enter_code[FOUR];//this is the array which will store the access code entered by the user
    
    int no_els=4;//declared and initialised for for loops in my functions
    
    int option;

    int correct_code=0;//counter for when access code entered correctly
    
    int incorrect_code=0;//counter for when access code entered incorrectly
    
    int count_option1=1;//counter to make sure option 1 can only only be selected once unless the code entered is encrypted and decrypted then option 1 can be selected again
    
    int count_option2=1;//counter to make sure option 2 can only be selected if there has been a code entered in option 1 that is not encrypted
    
    int count_option3=1;//counter to make sure that option 3 can only be selected if the code has been encrypted in option 2
    
  /*The above 3 counters mean that option 1 can only be selected once after you enter the code 
    unless the code entered has been encrypted and decrypted. It also means that option two can
    only be selected when a code is entered in option 1 and the code is not encrypted yet, once encrypted 
    it can not be encrypted again unless a new code is entered. It also means that option 3 can only be 
    selected if the code has been encryptedin option 2. If the code is encrypted in option 3 then this means 
    option 1 can now be selected again*/
    
    
    int menu_separator;
    {
        do
        {/*MAIN MENU*/
            for(menu_separator=80; menu_separator>0; menu_separator--)
                {
                    printf(".");
                }//end for loop
                /*end for- 80 full stops will display horizontally across  the screen which will hold the main menu*/
                printf("\n1. Enter Code\n");
                /*(MENU)-This option asks user to enter a code */
      
                printf("\n2. Encrypt code and verify if correct \n(i.e., matches authorised access code)\n");
                /*(MENU)-This option allows the user to encrypt their code and verify it*/
      
                printf("\n3. Decrypt Code\n");
                /*(MENU)-This option allows the user to decrypt the code*/
      
                printf("\n4. Display the number of times the code was entered \n(i) Successfully \n(ii)Incorrectly\n");
                /*(MENU)-This option displays the number of time the code was enter successfully and unsuccessfully*/
      
                printf("\n5. Exit Program\n");
                /*(MENU)-This option simply closes the program*/

                for(menu_separator=80; menu_separator>0; menu_separator--)
                    {
                        printf(".");
                    }//end for loop
                    /*end for- //end for()- 80 full stops will display horizontally across  the screen which will hold the main menu*/
                    
                    printf("Please enter one of the options between 1-5 in the main menu.\n=");
                    /*'option' integer is scanned so whatever number is entered by the user this will equal to the 'option' variable*/
                    
                    scanf("%d", &option);
                    
                    if(option<1||option>5)
                    {
                        printf("You must choose an option between 1-5!\n");
                        printf("\nPlease press enter to try again.\n");
                        /* Error checking so that the user can only enter a number between 1-5*/
                        getchar();
                    }//end for
                    getchar();
                    clrscr();
                    
    if(option==1&&count_option1==1)//if the user enters 1 from the main menu
    {
    /*call function option_1*/
    option_1(enter_code, &no_els);
    /*The count and count1 are sent down for error checking, they are reset to value 0 each time a code is entered to allow them to be encrypted and decrypted once each*/
    count_option2--;//this incrementation allows option 2 to be selected. This means the code entered can be encrypted
    count_option1--;//This incrementation means option 1 can not be selected again unless the code entered is encrypted and decrypted
    printf("\n\nPlease press enter to continue to the Main Menu.\n");
    getchar();
    clrscr();
   }//end if
   else
       if(option==1&&count_option1!=1)//warning in option 1 that the user has already entered a code
       {
           printf("\n\n\n               You have already entered an access code.\n\n\n               You can enter a new code after you have encrypted \n               and decrypted the current code you have entered.\n");
           printf("\n\n\n               Please press enter to continue to the Main Menu.\n");
           getchar();
       }

    if(option==2&&count_option2!=1)//if the user enters 2 from the main menu and if this option hasnt already been selected with a code
    {
    //call function option_2
    option_2(enter_code, &no_els, access_code, &correct_code, &incorrect_code);
    count_option2++;//this incrementation means option 2 cant be selected again unless a new code is entered therefore the code cant be encrypted twice
    count_option3--;//this allows option 3 to be selected, therefore option 3 only works if the code is encrypted
    printf("\n\nPlease press enter to continue to the Main Menu.\n");
    getchar();
    clrscr();
    }//end if
    else
        if(option==2&&count_option2==1)
        {
            printf("\n\n\n\n\n\n\n\n                 You have to have a code first to encrypt!\n");
            printf("\n\n\n\n              Please press enter to continue to the Main Menu.\n");
            getchar();
        }
    
    if(option==3&&count_option3!=1)//if the user enters 3 from the main menu and the option 2 has been selected which encrypt a code
    {
    /*call function option_3*/
    option_3(enter_code, &no_els);
    count_option3++;//this incrementation means option 3 cannot be selected again unless a new code is entered and it is encrypted
    count_option1++;//this incrementation means option 1 can now get selected again 
    
    printf("\n\nPlease press enter to continue to the Main Menu.\n");
    
    getchar();
    clrscr();
    }//end if
    else
        if(option==3&&count_option3==1)
        {
            printf("\n\n\n\n\n\n\n\n                 You have to have an encrypted code to decrypt!\n");
            printf("\n\n\n\n                 Please press enter to continue to the Main Menu.\n");
            getchar();
        }
    clrscr();
    
    if(option==4)//if the user enters 4 from the main menu
    {
      //call function option_4
      option_4(&correct_code, &incorrect_code);//the values of these integers change in option 2 since they are both used as counters
        
      printf("\nPlease press enter to continue to the Main Menu.\n");
        
      getchar();
      clrscr();
    }//end if statement
    clrscr();
}//end do loop

while(option!=5);//The main menu will continuously display until the user enters option 5
    
}//end while loop

}//end main()
/*function definition*/
void option_1(int *enter_code1, int *no_els)
{
    int i;

    /*Both of these are sent back to main with a value of zero so the new code entered can be encrypted and decrypted*/
    
    printf("\n\nPlease enter four single integer numbers for the access code.\n");
    
    for(i=0; i<*no_els; i++)
    {
        printf("-");//the '-' is placed infront of where the user enters a digit for the access code
        scanf("%d", enter_code1+i);//user asked to enter 4 values into array which is the access code
    }//end if statement
    clrscr();
    
    /*Error checking. This makes sure the numbers entered for the array are between 0-9 for the access code*/
    if(*(enter_code1+0)<=9&&*(enter_code1+0)>=0&&*(enter_code1+1)<=9&&*(enter_code1+1)>=0&&*(enter_code1+2)<=9&&*(enter_code1+2)>=0&&*(enter_code1+3)<=9&&*(enter_code1+3)>=0)
    {
      printf("\nThe four digit access code you have entered is ");
        
        for(i=0; i<*no_els; i++)
            {
                printf("%d", *(enter_code1+i));//displays the access code entered by the user if digits are between 0-9
            }//end for loop
            getchar();
    }//end if 
     else
    {
        printf("\nYou must enter numbers between 0-9 for your access code\n\nPlease re-enter the access code.(You have one last attempt)\n");
        /*this displays if numbers between 0-9 are not entered and allows the user one more attempt to re-enter the access code*/
        for(i=0; i<*no_els; i++)
            {
                scanf("%d", enter_code1+i);
            }//end for
            if(*(enter_code1+0)<=9&&*(enter_code1+0)>=0&&*(enter_code1+1)<=9&&*(enter_code1+1)>=0&&*(enter_code1+2)<=9&&*(enter_code1+2)>=0&&*(enter_code1+3)<=9&&*(enter_code1+3)>=0)
            {
                printf("\nThe four digit access code entered is ");
                for(i=0; i<*no_els; i++)
                    {
                        printf("%d", *(enter_code1+i));//displays the access code entered by the user at the second attempt if the digits entered are between 0-9
                    }//end for loop
                    getchar();
            }//end if
                    else
                        { 
                            for(i=0; i<*no_els; i++)
                                {
                                    *(enter_code1+i)=0;
                                }//end for loop   
                                printf("\nYou did not enter a suitable access code!");//displays if the user doesnt enter digits between 0-9 and resets the access code to 0,0,0,0
                                getchar();
                        }//end else
    }//end else
}//end option_1 function
/*function definition*/
void option_2(int *(encrypt), int *no_els, int *(access_code), int *correct_code, int *incorrect_code)
{
    int i;
    
    int temp;//used to store variables temporarily
    /*Encrypting process*/
    temp=*(encrypt+0);
    
    *(encrypt+0)=*(encrypt+2);
    
    *(encrypt+2)=temp;
    
    temp=*(encrypt+1);
    
    *(encrypt+1)=*(encrypt+3);
    
    *(encrypt+3)=temp;
    
    for(i=0; i<*no_els; i++)
    {
        *(encrypt+i)=*(encrypt+i)+1;
        
        if(*(encrypt+i)==10)
            {
                *(encrypt+i)=0;
            }//end if
    }
    if(*(encrypt+0)==*(access_code+0)&&*(encrypt+1)==*(access_code+1)&&*(encrypt+2)==*(access_code+2)&&*(encrypt+3)==*(access_code+3))
        /*Compares the access code entered when it is encrypted with the default authorised acces code*/
    {
        *correct_code=*correct_code+1;//counter for how many times the correct access code is entered
        
        printf("\nThe access code has been successfully encrypted.\n");
        
        printf("\nCORRECT CODE! The access code matches the aurthorised access code 4523.");
        /*message indicating the codes match*/
        
    }//end if
    else
    {
        *incorrect_code=*incorrect_code+1;//counter for when the access code is entered incorrectly
        
        /*message warning user they entered the wrong access code*/
        printf("INCORRECT CODE! The access code entered did not match the aurthorised code.");
    }//end else
}//end option_2 function
/*function definition*/
void option_3(int *(decrypt), int *no_els)
{
    int i;
    
    int temp;
    /*Decryption process*/
    temp=*(decrypt+2);
    
    *(decrypt+2)=*(decrypt+0);
    
    *(decrypt+0)=temp;
    
    temp=*(decrypt+1);
    
    *(decrypt+1)=*(decrypt+3);
    
    *(decrypt+3)=temp;
  
    for(i=0; i<*no_els; i++)
    {
        *(decrypt+i)=*(decrypt+i)-1;
        
        if(*(decrypt+i)==0)
            {
                *(decrypt+i)=10;
            }//end if
    }//end for
    
    printf("\nThe access code entered has been successfully decrypted and is now ");
    for(i=0; i<*no_els; i++)
        {
            printf("%d", *(decrypt+i));//displays the access code entered by the user at the second attempt if the digits entered are between 0-9
        }//end for loop
}//end option_3 function
/*function definition*/
void option_4(int *correct_code, int *incorrect_code)
{
    /*Messages displaying how many times the access code was entered correctly and incorrectly*/
    printf("\nThe amount of times the user entered the correct access code\nafter it was encrypted was %d\n", *correct_code);
    
    printf("\nThe amount of times the user entered an incorrect code\nafter it was encrypted was %d\n", *incorrect_code);
}//end option_4 function