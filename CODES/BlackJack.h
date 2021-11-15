#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define CARDS 52

int balance;
int pot;
int flag230=0;
int deck[52];
int sdeck[52];
char *name;

void play();
void turn();
int hit(int *val);
char *cface(int v);
char *csuit(int v);
char *dealer_name();
int cval(int v);
int bet();
void dealer();
void checkAce(int v1, int v2, int *a1);

void initdeck();
void shuffle();
int quit();

int BlackJack_main()
{   
    printf("\033[0;33m");
     printf("\n\n\t\t\t\t\t\t\t\tWelcome to my BlackJack Simulator!\n\n");
    printf("\033[1;34m");

	printf("\t\t\t#######################################################################\n");
  printf("\t\t\t#                                                                     #\n");
  printf("\033[0;31m");
  
  printf("\t\t\t\033[1;34m#\033[0;31m  ****** *     ******  ******  *    *       * ******  *****  *    *  \033[1;34m#\n");
  printf("\t\t\t\033[1;34m#\033[0;31m  *    * *     *    *  *       *   *        * *    *  *      *   *   \033[1;34m#\n");
  printf("\t\t\t\033[1;34m#\033[0;31m  ****** *     ******  *       * *          * ******  *      * *     \033[1;34m#\n");
  printf("\t\t\t\033[1;34m#\033[0;31m  *    * *     *    *  *       *   *   *    * *    *  *      *   *   \033[1;34m#\n");
  printf("\t\t\t\033[1;34m#\033[0;31m  ****** ***** *    *  ******  *    *  ****** *    *  *****  *    *  \033[1;34m#\n");
  printf("\033[1;34m");
  printf("\t\t\t#                                                                     #\n");
  printf("\t\t\t#######################################################################\n\n\n");
  printf("\033[0m");
    
    
    printf("\033[01;33m");
    printf("Below are the basic rules:\n");
    printf("- Beat the dealer's  hand without going over 21.\n- Face cards are worth 10, Aces are worth 1 or 11, whichever makes a better hand.\n- Each player starts with two cards, and one of the dealer's cards is hidden until the end.\n- Type 'hit' to ask for another card. Type 'stand' to hold your total and end your turn.\n- If you go over 21 you bust, and the dealer wins regardless of his hand.\n- If you are dealt 21 from the start (Ace & 10), you got a blackjack. If you get a blackjack, you win 2 times the amount of your bet automatically, unless the dealer also gets a blackjack, in which case it is a push.\n\n");
    printf("\033[0m");
    printf("- Remember: Type 'hit' to get another card, and 'stand' to hold. At the beginning of the round, type 'bet' followed by the quantity you want to bet (i.e. 'bet 50').\n");
    printf("\033[1;36m");
    printf("\nType 'play' to begin, and 'quit' to return back to the choice. At any time, you may type 'help' to get a list of valid commands.\n");
    name=dealer_name();
    
    char input[6];
    printf("\033[0;35m");
    scanf("%5s", input);
    printf("\033[0m");
    printf("\033[0;32m\nYou will be dealt by: \033[01;33m%s\n\033[0m",name);  
    if(strcmp(input,"play")==0)
    play();
    else if(strcmp(input,"quit")==0)
    {
      flag230=0;
      quit();
      if(flag230==1)
      return 0;

    }
    return 0;
}


void play(){
    printf("Lets start you off with 500 credits.\n");
    balance = 500;
    flag230=0;
    while(balance>0){
        if(flag230!=1)
        bet();
        if(flag230!=1)
        initdeck();
        if(flag230!=1)
        shuffle();
        if(flag230!=1)
        turn();
        if(flag230==1)
        break;
    }
    if(flag230!=1)
    printf("Sorry, it looks like you lost! Type 'play' to play another game.\n");
    else
    return;
}

void turn(){
    int inc=0;

    int d1 = hit(&inc);
    char *cn1 = csuit(d1);
    char *cf1 = cface(d1);
    int cv1 = cval(d1);
    printf("\033[1;31m");
    printf("\nYou got a %s of %s worth %d, and ", cf1, cn1, cv1);
    
    int d2 = hit(&inc);
    char *cn2 = csuit(d2);
    char *cf2 = cface(d2);
    int cv2 = cval(d2);

    printf("a %s of %s worth %d.\n", cf2, cn2, cv2);
    
    int d3 = hit(&inc);
    char *cn3 = csuit(d3);
    char *cf3 = cface(d3);
    int cv3 = cval(d3);
    printf("\033[0m");
    printf("The dealer face up card is a %s of %s worth %d, and has XX.\n\n", cf3, cn3, cv3);
    
    int d4 = hit(&inc);
    char *cn4 = csuit(d4);
    char *cf4 = cface(d4);
    int cv4 = cval(d4);

    int ptotal = cv1 + cv2;
    int dtotal = cv3;

    checkAce(cv1, cv2, &ptotal);

    printf("You have a total of \033[0;33m%d\033[0m points, and the dealer has \033[0;33m%d\033[0m.\n", ptotal, dtotal);  

    if(ptotal == 21){
        printf("Congrats! You got a blackjack!! Your payout is 2-to-1, %d.\n", (int)(pot*2));
        balance += (pot*2);
    }else{
        char input[6];
        printf("\033[0;35m");
        scanf("%5s", input);
        printf("\033[0m");
        while(strcmp(input,"stand")!=0){
            if(strcmp(input,"hit") == 0){
                int val = hit(&inc);
                char *ns = csuit(val);
                char *nf = cface(val);
                int nv = cval(val);
                ptotal += nv;
                printf("\033[1;31m");
                printf("You got a %s of %s worth %d.\n\n", nf, ns, nv);
                printf("\033[0m");
                if(ptotal < 21){
                    if(nv==1){
                        if(ptotal+10 == 21){
                            ptotal += 10;
                            printf("Congrats! You got BLACKJACK! Payout is 2-to-1.\n");
                            balance += (pot*2);                         
                            break;
                        }else{
                            int input;
                            printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                            printf("\033[0;35m");
                            scanf("%d",&input);
                            printf("\033[0m");
                            if(input == 11)
                                ptotal += 10;
                        }
                    }
                }else if(ptotal == 21){
                    printf("Congrats! You got 21!\n");
                    break;
                }else{
                    printf("\033[0;33mOh no, you've busted with %d. Try Again!\n\033[0m", ptotal);
                    break;
                }
            }else if(strcmp(input,"help")==0)
                printf("Type 'hit' to be dealt another card. Type 'stand' to hold.\n");
            else if(strcmp(input, "quit")==0){
                  flag230=0;
                  quit();
                  if(flag230==1)
                      return ;
            }else
                printf("Invalid command, try again.\n");
            
            printf("Your new total is \033[0;33m%d\033[0m.\n", ptotal);
            printf("\033[0;35m");
            scanf("%5s", input);
            printf("\033[0m");
        }
    }

    if(ptotal < 21){

        printf("The dealer's flips a %s of %s worth %d.\n", cf4, cn4, cv4);
        dtotal += cv4;
        if(cv4 == 1){
            if(dtotal+11 < 21)
                dtotal += 10;
        }

        if(dtotal >= 16){
            printf("The dealer stands with %d.\n", dtotal);
        }

        while(dtotal < 16){
            int val = hit(&inc);
            char *ns = csuit(val);
            char *nf = cface(val);
            int nv = cval(val);
            dtotal += nv;
            printf("The dealer got a %s of %s worth %d.\n", nf, ns, nv);
            if(dtotal < 16){
                if(nv==1){
                    if(dtotal+11<21)
                        dtotal += 10;
                }
            }else if(dtotal == 21){
                printf("The dealer just got 21.\n");
                break;
            }else if(dtotal > 21){
                printf("\033[0;32m");
              
                printf("The dealer busted with %d! You win!\n\n", dtotal);
                 printf("\033[0m");
                break;
            }else{
                printf("The dealer,stands with %d.\n",dtotal);
                break;
            }
            printf("The dealer new total is %d.\n", dtotal);
        }
        if(dtotal<ptotal){
            printf("You beat the dealer! Your payout is %d.\n",(int)(pot*2)); 
            balance += (pot*2);
        }else if(dtotal==ptotal){
            printf("\033[0;32m");
            printf("Its a tie! Push pot, 1-to-1 payout of %d.\n", pot);
            balance += pot;
            printf("\033[0m");
        }else if(dtotal>ptotal && dtotal <= 21){
             printf("\033[0;32m");
            printf("Oh no! Looks like the dealer won. Try again!\n");
            printf("\033[0m");   
        }else{
            printf("\033[0;32m");
            printf("You beat the dealer! Your payout is %d.\n",(int)(pot*2)); 
            printf("\033[0m");
            balance += (pot*2);
        }
    }
    if(balance > 0)
    {
        printf("\033[0;31m");
        printf("\n\nYour new balance is %d.\n", balance);
        printf("\033[0m");
    }
    printf("\033[01;33m_________________________________________________________________________\033[0m\n");
}

void checkAce(int v1, int v2, int *a1){
    if(v1 == 1 || v2 == 1){
        int input;
        if(v1 == 1 && v2 == 1){
            v1 = 11;
            v2 = 1;
            *a1 = 12;
            printf("Since you got 2 Aces, we set one to be worth 11 and the other to be worth 1.\n");
        }else if(v1 == 1 || v2 == 1){
            if(v1+10+v2 == 21)
                *a1 = 21;
            else{
                printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                printf("\033[0;35m");
                scanf("%d",&input);
                printf("\033[0m");
                if(input == 11)
                    *a1 += 10;
            }
        }
    }
}

int cval(int v){
    int a;
    if(((v%13)+1)<10)
        a = v%13+1;
    else 
        a = 10;
    return a;
}

char *csuit(int v)
{
    v = v%4;
    switch(v){
        case 0 :
            return "Hearts";
        case 1 :
            return "Clubs";
        case 2 :
            return "Diamonds";
        case 3 :
            return "Spades";
    }
		return 0;
}
char *cface(int v){
    v = v%13+1;
    char *output;
    switch(v){
        case 1 :
            output = "Ace";
            break;
        case 2 :
            output = "Two";
            break;
        case 3 :
            output = "Three";
            break;
        case 4 :
            output = "Four";
            break;
        case 5 :
            output = "Five";
            break;
        case 6 :
            output = "Six";
            break;
        case 7 :
            output = "Seven";
            break;
        case 8 :
            output = "Eight";
            break;
        case 9 :
            output = "Nine";
            break;
        case 10 :
            output = "Ten";
            break;
        case 11 :
            output = "Jack";
            break;
        case 12 :
            output = "Queen";
            break;
        case 13 :
            output = "King";
    }
    return output;
}

int quit(){
    printf("Are you sure you want to quit? Type 'y' or 'n'.\n");
    char input[6];
    printf("\033[0;35m");
    scanf("%s",input);
    printf("\033[0m");
    if(strcmp(input,"y")==0)
    {
        printf("\nGOODBYE!!!\n");
        flag230=1;
        return 0;
    }
    else 
        printf("Quit cancelled.\n");
		return 0;
}

int hit(int *i){
    int a = sdeck[*i];
    *i = *i + 1;
    return a;
}

int bet()
{

  //trying to DeBUG
  char input[10];
  int b,flag=0,flag67=1,i,pt;
	printf("\nEnter the amount you want to bet\n");
  do
  {
    scanf("%s",input);
    
    flag=0;
    if(strcmp(input,"quit")==0)
        {
          flag230=0;
          quit();
          flag67=0;
          if(flag230==1)
          return 0;
        }
    else 
    {
      flag=0;
      for(i=0;i<strlen(input);i++)
      {
        pt=(int)input[i];
        pt-=48;
        if(pt<0||pt>9)
        {
          flag++;
          break;
        }
      }
      if(flag!=0)
      printf("Invalid entry. Enter a valid bet ammount\n");
      else
      {
        b=atoi(input);
        if(b>balance)
        {
          printf("Invalid entry.Enter a value less than your ammount left\n");
          flag=1;
          continue;
        }
        balance -= b;
        printf("\033[0;32m");
        printf("\nYou've made a bet of %d. Good luck!\n", b);
        printf("\033[0m");
        pot = b; 
        flag67=0;
        return 0; 
      }
    }

    
  }while(flag!=0);
   return 0;
}

void initdeck()
{
    int i=0;
    for(i=0;i<52;i++)
    {
        deck[i] = i+1;  
    }
}

void shuffle()
{
    srand(time(NULL));
    int i=0;
    for(i=0;i<52;i++){
        sdeck[i] = deck[i];
    }
    i=0;
    for(i=CARDS-1;i>0;i--){
        int j = rand()%(i+1);
        int n = sdeck[i];
        sdeck[i] = sdeck[j];
        sdeck[j] = n;
    }
}

char *dealer_name()
{
    int g;
    srand(time(NULL));
    g=(rand()%3);
    switch(g){
        case 0 :
            return "ABHINN";
        case 1 :
            return "NEELAK";
        case 2 :
            return "ATULYA";
    }
		return 0;
}