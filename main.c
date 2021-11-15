
#include <stdio.h>
#include"CODES/Roulette.h"
#include"CODES/BlackJack.h"
#include"CODES/Slots.h"
int main()
{
  int choice;
  printf("\033[0;31m");
  printf("\t\t\t#########################################################################\n");
  printf("\t\t\t#                                                                       #\n");
  printf("\033[0;31m");
  
  printf("\t\t\t\033[0;31m#\033[0;32m         ******  ****  ******  *** *      * ******* \033[0;31m                   #\n");
  printf("\t\t\t\033[0;31m#\033[0;32m         *      *    * *        *  * *    * *     * \033[0;31m                   #\n");
  printf("\t\t\t\033[0;31m#\033[0;32m         *      ****** ******   *  *   *  * *     * \033[0;31m                   #\n");
  printf("\t\t\t\033[0;31m#\033[0;32m         *      *    *      *   *  *    * * *     * \033[0;31m                   #\n");
  printf("\t\t\t\033[0;31m#\033[0;32m         ****** *    * ******  *** *      * ******* \033[0;31m                   #\n");
	printf("\t\t\t\033[0;31m#\033[0;34m                       ****** ****** *     *  ****  *     ****** \033[0;31m      #\n");
  printf("\t\t\t\033[0;31m#\033[0;34m                       *   *  *    *  *   *  *    * *     *      \033[0;31m      #\n");
  printf("\t\t\t\033[0;31m#\033[0;34m                       * *    *    *    *    ****** *     ****** \033[0;31m      #\n");
  printf("\t\t\t\033[0;31m#\033[0;34m                       *   *  *    *    *    *    * *     *      \033[0;31m      #\n");
  printf("\t\t\t\033[0;31m#\033[0;34m                       *    * ******    *    *    * ***** ****** \033[0;31m      #\n");
  printf("\033[0;31m");
  printf("\t\t\t#                                                                       #\n");
  printf("\t\t\t#########################################################################\n\n\n");
  printf("\033[0m");
  char name[50];
  printf("Enter your name: ");
	printf("\033[1;31m");
  scanf("%s",name) ;
  printf("\033[0m\n\n");
   printf("\033[01;33m");
   printf("We have 3 superb fun games for you all, to test your luck and Shine your fortune!\n\n");
   do
  {
    choice=0;
    printf("\033[01;33m");
   printf("1] Blackjack\n");
   printf("2] Roulette\n");
   printf("3] Slots\n");
   printf("4] Exit\n\n");
   printf("\033[0m");
   printf("Choose 1,2 or 3 in order to play the respective games and 4 to exit Casino Royale > ");
   printf("\033[1;31m");
   scanf("%d",&choice);
   printf("\033[0m");
  
	switch(choice)
  {
		case 1: BlackJack_main();
						break;
		case 2: roulette_main();
						break;
	  case 3: slots_main();
						break;
		case 4: printf("\n\033[1;34mThanks for playing!! Goodbye!!\033[0m\n");
            printf("\033[01;33m_________________________________________________________________________\033[0m\n");
            exit(0);
            break;
    default: printf("Enter a value between 1,2,3 and 4");
              break;
    
  }
  printf("\n\n");
  printf("\033[01;33m_________________________________________________________________________\033[0m\n\n");
  }while(choice!=4);
	return 0;
}
