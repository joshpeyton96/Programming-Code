/*
Joshua Peyton- DT211/1- C14348526
Programming Individual Assignment #1
Program that will operate on an ATM machine
for a bank and the program will allow bank
customers to manage their PIN. The pin is 
a 4-digit number
*/


#include <stdio.h>

main()


{
int selected_option;
    
    
int original_pin;
    
    
int pin;
    
    
int new_pin;
    

int new_pin2;
    
    
int successfully_entered_pin;
    
    
int invalid_entered_pin;
    
    
int menu_separator;


int storage_int;//This is a variable which which is used to only temporarily store a value 


storage_int=0;


new_pin=0;

    
new_pin2=0;

    
original_pin=1234;


pin=0;

    
successfully_entered_pin=0;

    
invalid_entered_pin=0;


{
    
      do
    {
        
        
     for(menu_separator=80; menu_separator>0; menu_separator--)
      {
       printf(".");
      } //end for()- 80 full stops will display horizontally across  the screen which will hold the main menu


  
   printf("\n1. Enter PIN and verify correct\n");//(MENU)-This option asks user to enter their current PIN and will display a message saying the PIN entered is either correct or incorrect 
    

   printf("\n2. Change PIN\n");//(MENU)-This option allows user to change their PIN. Once they change their PIN this be their new active PIN. If an invalid PIN is entered an error warning will show. You can not enter a PIN which is not less or more than 4-digits and is the same as your current active PIN
    

   printf("\n3. Display the number of times the PIN was entered (i) Sucessfully (ii) \n   Incorrectly\n");//(MENU)-This option will inform the user of the number of times their PIN was entered successfully or incorrectly 
    

   printf("\n4. Exit Program\n");//(MENU)-This option simply closes the program

    
   for(menu_separator=80; menu_separator>0; menu_separator--)
    {
       printf(".");
    }//end for()- //end for()- 80 full stops will display horizontally across  the screen which will hold the main menu


   printf("\n\nPlease enter one of the above four options\n= ");//This is an added printf to ask the user to pick one of the main menu options(1-4)


   scanf("%d", &selected_option);//'selected_option' integer is scanned so whatever number is inputted by the user this will equal to the 'selected_option'

    
   switch(selected_option)//Switch Statement used and it includes the integer 'selected_option'. I have a case 1,2,3 and 4 for the selected option.Therefore, whatever number between 1-4 that is entered for 'selected_option' will cause that case to execute( for example if 2 is inputted the case 2: will execute )
    {
        case 1://This case will execute if 1 is entered by the user for the 'selected option ' integer
        { 
            printf("\nPlease enter your 4-digit PIN\n= ");//This is the first option on the main menu. The integer 'pin' is scanned therefore whatever 4-digit number is entered will be the value of the integer 'pin'
            
            
            scanf("%d", &pin);
            
        
            if(pin==original_pin&&pin<10000&&pin>999)//if the pin entered in for the 'pin' integer is the same as the integer for 'original_pin' which is set to 1234(but can be changed), this statement is true and the printf below it will execute/ pin<1000&&pin>999 makes sure the PIN entered is a four digit PIN
            {
                successfully_entered_pin++;//This  will add one to the value of the successfully_entered_pin integer  in case 3 everytime the user enters their PIN correctly
                
                
                printf("\nThe 4-digit PIN you've entered is correct\n");//only executes if the integers 'pin' and 'original_pin' are the same 
                
                
                printf("\nPlease press Enter to continue\n");
            }//end if()
            
            
            else
                if(pin!=original_pin&&pin<10000&&pin>999)//if the pin enter for the integer 'pin' is not the same as 'original integer' then the above statement is false and the else statement will execute/ pin<1000&&pin>999 also makes sure the PIN entered is a 4-digit one 
            {
                invalid_entered_pin++;//This  will add one to the invalid_entered_pin integer in case 3 everytime the user enters their PIN incorrectly
                
                
                printf("\nThe 4-digit PIN you've entered is incorrect\n");//Only executes if the if statement is false therefore, 'pin is not equal to 'original_pin'
                
                
                printf("\nPlease press Enter to continue\n");
            }//end else()
            
            
            else
            {
                invalid_entered_pin++;//This  will add one to the invalid_entered_pin integer in case 3 everytime the user enters their PIN incorrectly
                
                
                printf("\n! Error !-You must enter a 4-digit number\n");//This else statement executes if the PIN entered is either more or less than 4 digits
                
                
                printf("\nPlease press Enter to continue\n");
            }
            
            
        }//end case1()
        
        
        flushall();
        
        
        getchar();
        
        
        break;//This break statement terminates the switch statement making sure execution will not continue to the end of the switch statement. Without the break at the end of each switch, execution would continue to the following switch statement without looping back to the main menu 
        
        
    
   
   case 2:// This will execute if 2 is entered in for 'selected_option' integer 
       {
           printf("\nPlease enter a new 4-digit PIN\n= ");//This is the second option on the main menu which allows the user to enter a new pin. The integer 'new_pin' is scanned. Whatever four digit pin is entered will be the value of the integer 'new_pin'
           
          
           scanf("%d", &new_pin);
           
          
           printf("\nPlease re-enter this new 4-digit PIN\n= ");//User is asked to re-enter their new PIN in order to verify it. A new variable is scanned so the two 4-digit numbers entered can be compared
           
           
           scanf("%d", &new_pin2);
           
           
    if(new_pin==new_pin2&&new_pin<10000&&new_pin>999&&new_pin!=original_pin)//If the re-entered pin does match the original entered new pin then the below statement will execute which will display the new PIN entered and change the 'original_pin' variable value to the new_pin value/new_pin<10000&&pin>999 makes sure the new pin entered is a 4-digit one
           {
                     storage_int=original_pin;//The 'storage int' variable is only used to give the 'original_pin' variable a value of zero. 'storage_int=original_pin' means whatever value is stored in the 'original_pin' will be stored in the 'storage int' temporarily until the user changes their PIN again
               
               
                     original_pin=new_pin;//Therefore 'original_pin' is equal to zero because what was stored in that variable is now in the 'storage_int' so original_pin=new_pin means whatever is stored in 'new_pin' is now stored in 'original_pin'
               
               
                     printf("\nYour new PIN has successfully been verified.\nTherefore your new active PIN is %d\n", original_pin);//When both the 'new_pin' and 'new_pin2' are the same this printf will display that tells the user they have successfully change their PIN  and displays their new active PIN 
                     
                    
                     printf("\nPlease press Enter to continue\n"); 
           }//end if()
           
        else
            
        
         if(new_pin!=new_pin2&&new_pin<10000&&new_pin>999&&new_pin!=original_pin)//This means if the PIN re-enter doesn't match match the original new PIN entered, the below statement will execute resulting in the PIN remaining the same/new_pin<10000&&pin>999 makes sure the new pin is a 4-digit one. This means the your PIN will remain the same and doesn't change
           {
               printf("\nSorry these PINs do not match.\nTherefore your active PIN remains as %d\n",original_pin);//the value of the 'original_pin' will display
               
               
               printf("\nPlease press Enter to continue\n");
           }//end if()
        
           
            else
               
               {
                   printf("\n! Error !\nYou have entered an invalid PIN number.\n(You must enter a suitable PIN number which is 4-digits\nand different to your active Pin)\n");//This else is an error message which will only execute if the PIN entered for option 2 is less or more than 4-digits long and if there isn't a difference between your active PIN and the new one you've entered
                  
                   printf("\nPlease press Enter to continue\n");
                }//end else()
           
           
               
           flushall();
               
               
           getchar();
               
            
               
        }//end case2()
        
        
        break;//This break statement terminates the switch statement making sure execution will not continue to the end of the switch statement. Without the break at the end of each switch, execution would continue to the following switch statement without looping back to the main menu 
       
       
    case 3:
           {
               if(selected_option==3)
               {
                   printf("\nThe total number of times your PIN was entered correctly was (i) %d \nand incorrectly (ii) %d \n", successfully_entered_pin, invalid_entered_pin);//These totals will add up as option is executing. The variable successfully_entered_pin will plus one when the PIN is enetered correctly in case 1 and the invalid_entered_pin will plus one when PIN is entered incorrectly in case 1
                    
                   printf("\nPlease press Enter to continue\n");
                }//end if()
               
               
               flushall();
               
               
               getchar();
               
               
               break;//This break statement terminates the switch statement making sure execution will not continue to the end of the switch statement. Without the break at the end of each switch, execution would continue to the following switch statement without looping back to the main menu 
               
               
           }//end case3()
           
           
           
    case 4://This case is only used to exit the program. Therefore only the break statement is only needed in this case
           
           
           break;//This break statement terminates the switch statement making sure execution will not continue to the end of the switch statement. Without the break at the end of each switch, execution would continue to the following switch statement without looping back to the main menu 
           
           
    default:
           {
             printf("\n! WARNING !\nThis is an invalid option. You must select one of the above four options\n");//This warns the user that a number between 1-4 was not entered has not been entered for the 'selected_option'
               
             printf("\nPlease press Enter to continue\n");
           }//end default()
           
           
           flushall();
           
           
           getchar();
           
           
       
    }//end switch()

    
    
    
    }//end do()- Everything held in the curley brackets for the do while statement will execute as long as the while statement after the do while loop is true. This means the menu main will display again(loop around) after the user completes each option as long as the number entered for selected option is not equal to 4(because 4 exits the program)


    
    
     while(selected_option!=4);
    }//end  while loop()


    
    
}//end main()
   
   
   