
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
//print block letters
void print_title();   
//Spin roulette
int spin_roulette();

int roulette_main()
{
//Variables    
int betmode;    
int straightbet, cashbet, parity;
int number;
int balance;
char R, B;
char colorbet[1];


//Arrays
int red[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
int black[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    
//Welcome & Title
print_title();
char startcommand[10];
  int flag=0,sl=0,i;
	char start_command[5]={'S','t','a','r','t'};
  printf("To continue please type ");
  printf("\033[0;35m");
  printf("\"Start\" \033[0mand to return to the choice of games, enter \033[0;35m\"Exit\"\033[0m\n") ;
printf("\033[0;35m");
scanf("%s", startcommand);
  printf("\033[0m");
  
  sl=strlen(startcommand);
	for(i=0;i<4;i++)
  {
      if(start_command[i]!=startcommand[i])
      {
          flag=1;
          break;
      }
  }
  if(sl!=5)
  flag=1;
  if(flag==0)
  flag=1;
  else
  {
    printf("\nGOODBYE!!!\n");
    return 0;
  }
//Instructions for game
printf("\033[1;33m");
printf("\n\nYou have been granted 10,000 chips by the gods of Gambling on entering the Casino\n\n");
printf("\033[0m");

balance=10000;



//Loop to keep game going as long as you have cash
do
{
  printf("\nThere are 3 types of bets you can make:");
	printf("\n1) \033[1;34mStraight-up bet\033[0m: Choose a single number. High risk, high payout! (35 to 1)\n");
	printf("2) \033[1;34mRed or black\033[0m: Choose a color.(1 to 1)\n \tRed numbers are  1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n \tBlack numbers are 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n"); 
	printf("3) \033[1;34mOdd or even\033[0m: Choose odd or even (1 to 1)");
	printf("\n4) \033[1;34mExit\033[0m");

//Select game mode
	printf("\nPlease select your preferred type of bet. Enter 1, 2, 3 or 4> ");
  printf("\033[0;35m");
  scanf("%d", &betmode);
  printf("\033[0m");
    if (betmode==1)       //Straight bets
     {
       printf("\n\033[0;33mGoing for the big money, eh?\n\033[0m");
			do
      {
      printf("\nEnter a number between 1-36 you'd like to bet on> ");
      printf("\033[0;35m");
			scanf("%d", &straightbet);
      if(straightbet<1||straightbet>36)
      printf("\nInvalid Entry!! Enter a number between 1 and 36\n\n");
      printf("\033[0m");
      }while(straightbet<1||straightbet>36);
			printf("Now how much money are you willing to risk? Payout is 35 to 1> ");
      printf("\033[0;35m");
			scanf("%d", &cashbet);
      printf("\033[0m");
			printf("\nYou have bet \033[1;33m%d\033[0m chips on the number %d", cashbet, straightbet);
			printf("\nPress ENTER to spin the roulette. Keep your fingers crossed!");
			getchar();
			getchar();
			number=spin_roulette();
      if (number==straightbet)
        {			
					balance += (cashbet*35);
      	  printf("Winner Winner! You now have \033[1;33m%d\033[0m chips in your pocket", balance);
				}
      else
		  	{
          balance -= cashbet;
          printf("Sorry. You've lost \033[1;33m$%d\033[0m. Your new balance is \033[1;33m$%d\033[0m", cashbet, balance);
			  }
        printf("\033[0;32m");
        printf("\n_____________________________________________________________\n");
        printf("\033[0m");
   }
  	else if (betmode==2)         //Red or black bets
     {
        printf("\nAlright pick a color. Choose RED(R) or BLACK(B)> ");
        printf("\033[0;35m");
        scanf("%s",colorbet);
        printf("\033[0m");
        
        
        if(strcmp(colorbet,"R")==0||strcmp(colorbet,"r")==0)
        {
          printf("\nNow how much money are you willing to risk? Payout is 1 to 1> ");
        printf("\033[0;35m");
        scanf("%d", &cashbet);
        printf("\033[0m");
          printf("\nYou have bet \033[1;33m%d\033[0m chips on the color ", cashbet);
        printf("\033[1;33mRED\033[0m");
        }
        else if (strcmp(colorbet,"B")==0||strcmp(colorbet,"b")==0)
        {
          printf("\nNow how much money are you willing to risk? Payout is 1 to 1> ");
        printf("\033[0;35m");
        scanf("%d", &cashbet);
        printf("\033[0m");
          printf("\nYou have bet \033[1;33m%d\033[0m chips on the color ", cashbet);
        printf("\033[1;33mBLACK\033[0m");
        }
        else
        {
          printf("\033[0;32mU have not bet on any color. Please stand asied and wait for the result.\033[0m\n");
        }
        
        
        printf("\nPress ENTER to spin the roulette. Keep your fingers crossed!");
        getchar();
        getchar();
        number=spin_roulette();
        if(strcmp(colorbet,"R")==0||strcmp(colorbet,"r")==0)
          {
        	  if (number==1||number==3||number==5||number==7||number==9||number==12||number==14||number==16||number==18||number==19||number==21||number==23|number==25||number==27||number==30||number==32||number==34||number==36)
          	  {
              	balance += cashbet;
              	printf("Winner Winner! You now have \033[1;33m$%d\033[0m in your pocket", balance);
            	}
            else
    	        {
              	balance -= cashbet;
              	printf("Sorry. You've lost \033[1;33m$%d\033[0m. Your new balance is \033[1;33m$%d\033[0m", cashbet, balance);
              }
	        }                   
        else if (strcmp(colorbet,"B")==0||strcmp(colorbet,"b")==0)
          {
            if (number==2||number==4||number==6||number==8||number==10||number==11||number==13||number==15||number==17||number==20||number==22||number==24||number==26||number==28||number==29||number==31||number==33||number==35)
          	  {
                  balance += cashbet;
                  printf("Winner Winner! You now have \033[1;33m$%d\033[0m in your pocket", balance);
              }
              else
           	    {
                  balance -= cashbet;
                  printf("Sorry. You've lost \033[1;33m$%d\033[0m. Your new balance is \033[1;33m$%d\033[0m", cashbet, balance);
            	  }
          }
          printf("\033[0;32m");
          printf("\n_____________________________________________________________\n");
          printf("\033[0m");
		 }
    else if(betmode==3)           //Odd or even bets
     	{  
    		printf("\n\nAlright enter 1 for odd or 2 for even. Choose wisely!> ");
        printf("\033[0;35m");
      	scanf("%d", &parity);
        printf("\033[0m");
    	  printf("\nNow how much money are you willing to risk? Payout is 1 to 1> ");
        printf("\033[0;35m");
      	scanf("%d", &cashbet);
        printf("\033[0m");
  	    if (parity==1)
        	printf("\nYou have bet \033[1;33m%d\033[0m chips on odds", cashbet);
        else
          printf("\nYou have bet \033[1;33m%d\033[0m chips on evens", cashbet);
     		printf("\nPress ENTER to spin the roulette. Keep your fingers crossed!");
      	getchar();
       	getchar();
       	number=spin_roulette();
        if (parity==1)
       		{
          	if (number%2==1)
          		{
            		balance += cashbet;
            		printf("\nWinner Winner! You now have \033[1;33m%d\033[0m Chips in your pocket", balance);
          		}
          	else
          		{
            		balance -= cashbet;
            		printf("\nSorry. You've lost \033[1;33m%d\033[0m chips. Your new balance is \033[1;33m%d\033[0m chips", cashbet, balance);
							}
       		}
       else
        	{
         		if (number%2==0)
          		{
            		balance += cashbet;
            		printf("\nWinner Winner! You now have \033[1;33m%d\033[0m chips in your pocket", balance);
							}
            else
          		{
              	balance -= cashbet;
              	printf("\nSorry. You've lost \033[1;33m%d\033[0m chips. Your new balance is \033[1;33m%d\033[0m Chips", cashbet, balance);
							}//else
       		}
           printf("\033[0;32m");
            printf("\n_____________________________________________________________\n");
            printf("\033[0m");
                              
				}
		else if(betmode==4)
    {
      printf("\nGOODBYE!!!\n");
        
			return 0;
    }
		else
    {
      
			printf("You've entered a wrong choice\nPlease Enter either 1, 2, 3 or 4.\n");
      printf("\033[0;32m");
          printf("\n_____________________________________________________________\n");
          printf("\033[0m");
    }
			
}while(balance>0&&betmode!=4);
getchar();
getchar();
return (0);
}

void print_title()
{
	printf("\033[1;34m");
	printf("\t\t\t########################################################\n");
  printf("\t\t\t#                                                      #\n");
  printf("\033[0;31m");
  printf("\t\t\t\033[1;34m#\033[0;31m  *****   ****** *    * *    ***** ***** ***** *****  \033[1;34m#\n");
  printf("\t\t\t\033[1;34m#\033[0;31m  *   *   *    * *    * *    *       *     *   *      \033[1;34m#\n");
  printf("\t\t\t\033[1;34m#\033[0;31m  * *     *    * *    * *    *****   *     *   *****  \033[1;34m#\n");
  printf("\t\t\t\033[1;34m#\033[0;31m  *  *    *    * *    * *    *       *     *   *      \033[1;34m#\n");
  printf("\t\t\t\033[1;34m#\033[0;31m  *    *  ****** ****** **** *****   *     *   *****  \033[1;34m#\n");
  printf("\033[1;34m");
  printf("\t\t\t#                                                      #\n");
  printf("\t\t\t########################################################\n\n\n");
  printf("\033[0m");
    	
}


int spin_roulette ()
{
	
  	int number;
    srand(time(NULL));
    number=1+(rand()%36);
    printf("\033[0;34m");
    printf("The ball has landed on %d\n", number);
    printf("\033[0m");
    return number;
} 
