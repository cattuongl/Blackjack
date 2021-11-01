/*
Name: Cattuong Le
Date: October 13, 2015
Program Used: Dev. C++ 5.5.1
Purpose: Game of blackjack for users to play
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

main()
{
	//Makes random integers work
	srand (time(NULL));
	
	//Declaring variables
	bool stand, quit = false, blackjack, bust;
	char playagain, hit;
	string usercard[10], dealercard[10], deck[13] = {"ACE   ", "TWO   ", "THREE   ", "FOUR   ",  "FIVE   ", "SIX   ", "SEVEN   ", "EIGHT   ", "NINE   ", "TEN   ", "JACK   ", "QUEEN   ", "KING   "};
	int cardrandomizer, usercardvalue, dealercardvalue, usercardcounter, dealercardcounter, games = 0, wins = 0, losses = 0, draws = 0, i;
	
	//Welcome user to game
	cout << "\nWelcome to Blackjack!\n\n";
	system ("pause");
	system ("cls");
	
	//Game
	while (quit == false && losses < 10)
	{
		//Clears the screen
		system ("cls");
		
		//Counts how games you have played
		games += 1;
		
		//Setting variable and array values
		usercardvalue = 0;
		dealercardvalue = 0;
		usercardcounter = 1;
		dealercardcounter = 3;
		int cardsused[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		bool useraceisone[4] = {true, true, true, true}, dealeraceisone[4] = {true, true, true, true};
		stand = false;
		blackjack = false;
		bust = false;
		
		//Setting cards
		for (i = 0; i <= 3; i++)
		{
			//Randomize cards
			cardrandomizer = rand() % 13;
			
			//Counts how many times the card has been used
			cardsused[cardrandomizer] += 1;
			
			//Setting card faces
			if (i == 0 || i == 1)
			{
				usercard[i] = deck[cardrandomizer];
			}
			else
			{
				dealercard[i] = deck[cardrandomizer];
			}
			
			//Setting card values
			if (i <= 1)
			{
				if (cardrandomizer <= 9 && cardrandomizer > 0)
				{
					usercardvalue = usercardvalue + cardrandomizer + 1;
				}
				else if (cardrandomizer > 9)
				{
					usercardvalue += 10;
				}
				else if (cardrandomizer == 0)
				{
					if (usercardvalue <= 10)
					{
						useraceisone[cardsused[0]] = false;
						usercardvalue += 11;
					}
					else
					{
						useraceisone[cardsused[0]] = true;
						usercardvalue += 1;
					}
				}
			}
			else if (i == 2 || i == 3)
			{
				if (cardrandomizer <= 9 && cardrandomizer > 0)
				{
					dealercardvalue = dealercardvalue + cardrandomizer + 1;
				}
				else if (cardrandomizer > 9)
				{
					dealercardvalue += 10;
				}
				else if (cardrandomizer == 0)
				{
					if (dealercardvalue <= 10)
					{
						dealeraceisone[cardsused[0]] = false;
						dealercardvalue += 11;
					}
					else
					{
						dealeraceisone[cardsused[0]] = true;
						dealercardvalue += 1;
					}
				}
			}
		}
		
		//Keeps asking you to hit until you stand, get blackjack or bust
		while (stand == false && blackjack == false && bust == false)
		{
			//Checks if the user has busted, but can change the value of their ace
			for (i = 0; i <= 3; i++)
			{
				if (useraceisone[i] == false && usercardvalue > 21)
				{
					usercardvalue = usercardvalue - 10;
					useraceisone[i] = true;
				}
			}
				
			cout << "\nYour hand: \n\n";
			
			//Displays the user's cards
			for (i = 0; i <= usercardcounter; i++)
			{
				cout << usercard [i];
			}
			
			//Displays the total value of the user's cards
			cout << "\n\nThe total value of your cards is: " << usercardvalue << "\n\n\n";
			
			//Displays the dealer's hand
			cout << "The dealer's hand: \n\n" << dealercard[2] << "   ???\n\n\n";
			
			//Checks if the user has gotten blackjack, busted, or needs to hit again
			if (usercardvalue == 21)
			{
				blackjack = true;
			}
			else if (usercardvalue > 21 && useraceisone[0] == true && useraceisone[1] == true && useraceisone[2] == true && useraceisone[3] == true)
			{
				bust = true;
			}
			else
			{	
				//Asks the user if they would like to hit
				cout << "Would you like to hit? (Y/N)\n\n";
				cin >> hit;
				
				//If the user inputted the wrong character
				if (hit != 'n' && hit != 'N' && hit != 'y' && hit != 'Y')
				{
					cout << "\nPlease type Y or N.\n\n";
					cin >> hit;
				}
				
				//Checks if the user wanted to hit or not		
				if (hit == 'y' || hit == 'Y')
				{
					//Clears the screen
					
					system ("cls");
					
					//Counts the number of hits the user has had
					usercardcounter += 1;
					
					//Randomize cards
					cardrandomizer = rand() % 13;
					
					//If there are no more of that number, pick another
					while (cardsused[cardrandomizer] == 4)
					{
						cardrandomizer = rand() % 13;
					}
					
					//Counts how many times the card has been used
					cardsused[cardrandomizer] += 1;
					
					//Sets new card face
					usercard[usercardcounter] = deck[cardrandomizer];
					
					//Setting the card values
					if (cardrandomizer <= 9 && cardrandomizer > 0)
					{
						usercardvalue = usercardvalue + cardrandomizer + 1;
					}
					else if (cardrandomizer > 9)
					{
						usercardvalue += 10;
					}
					else
					{
						if (usercardvalue <= 10)
						{
							useraceisone[cardsused[0]] = false;
							usercardvalue += 11;
						}
						else
						{
							useraceisone[cardsused[0]] = true;
							usercardvalue += 1;
						}
					}
				}
				else if (hit == 'n' || hit == 'N')
				{
					//The user will stand
					stand = true;
				}
				
				//Clears the screen
				system ("cls");
			}
		}
		
		//The dealer hits
		while (dealercardvalue < 16)
		{	
			//Counts the number of hits the dealer has had
			dealercardcounter += 1;
			
			//Randomize cards
			cardrandomizer = rand() % 13;
			
			//If there are no more of that number, pick another
			while (cardsused[cardrandomizer] == 4)
			{
				cardrandomizer = rand() % 13;
			}
			
			//Counts how many times the card has been used
			cardsused[cardrandomizer] += 1;
			
			//Sets new card face
			dealercard[dealercardcounter] = deck[cardrandomizer];
			
			//Setting the card values
			if (cardrandomizer <= 9 && cardrandomizer > 0)
			{
				dealercardvalue = dealercardvalue + cardrandomizer + 1;
			}
			else if (cardrandomizer > 9)
			{
				dealercardvalue += 10;
			}
			else
			{
				if (dealercardvalue <= 10)
				{
					dealeraceisone[cardsused[0]] = false;
					dealercardvalue += 11;
				}
				else
				{
					dealeraceisone[cardsused[0]] = true;
					dealercardvalue += 1;
				}
			}
			
			//Checks if the dealer has busted, but can change the value of their ace
			for (i = 0; i <= 3; i++)
			{
				if (dealeraceisone[i] == false && dealercardvalue > 21)
				{
					dealercardvalue = dealercardvalue - 10;
					dealeraceisone[i] = true;
				}
			}
		}
		
		//Checks if user got a blackjack, busted, or stood
		if (blackjack == true)
		{
			cout << "BLACKJACK! YOU WIN!\n\n";

			//Counts how many wins the user has
			wins += 1;
		}
		else if (bust == true)
		{
			cout << "BUST! YOU LOSE!\n\n";
			
			//Counts how many losses the user has
			losses += 1;
		}
		else if (stand == true)
		{
			cout << "\nYour hand was: \n\n";
			
			//Displays the user's cards
			for (i = 0; i <= usercardcounter; i++)
			{
				cout << usercard [i];
			}
			
			//Displays the total value of the user's cards
			cout << "\n\nThe total value of your cards was: " << usercardvalue << "\n\n\n";
			
			//Displays the dealer's hand
			cout << "The dealer's hand was: \n\n";
			
			//Displays the dealer's cards
			for (i = 0; i <= dealercardcounter; i++)
			{
				cout << dealercard [i];
			}
			
			//Displays the total value of the dealer's cards
			cout << "\n\nThe total value of the dealer's cards was: " << dealercardvalue << "\n\n\n";
			
			//Checks if user wins or not
			if (usercardvalue > dealercardvalue || dealercardvalue > 21)
			{
				cout << "YOU WIN!\n\n";
				
				//Counts how many wins the user has
				wins += 1;
			}
			else if (usercardvalue < dealercardvalue)
			{
				cout << "YOU LOSE\n\n";
				
				//Counts how many losses the user has
				losses += 1;
			}
			else
			{
				cout << "IT'S A DRAW\n\n";
				
				//Counts how many draws the user has
				draws += 1;
			}
		}
		
		//Waits for the user to continue and clears the screen
		system ("pause");
		system ("cls");
		
		//Displays how games you have won, lost and gotten a draw in
		if (games == 1)
		{
			cout << "\nYou have won " << wins << " out of " << games << " game.";
			cout << "\n\nYou have lost " << losses << " out of " << games << " game.";
			cout << "\n\nYou have gotten a draw in " << draws << " out of " << games << " game.";
		}
		else
		{
			cout << "\nYou have won " << wins << " out of " << games << " games.";
			cout << "\n\nYou have lost " << losses << " out of " << games << " games.";
			cout << "\n\nYou have gotten a draw in " << draws << " out of " << games << " games.";
		}
		
		//Exit command if user has not already lost 10 times
		if (losses < 10)
		{
			cout << "\n\n\nPlay again? (Y/N)\n\n";
			cin >> playagain;
			
			//If the user inputted the wrong character
			if (playagain != 'n' && playagain != 'N' && playagain != 'y' && playagain != 'Y')
			{
				cout << "\nPlease type Y or N.\n\n";
				cin >> playagain;
			}
			
			//Checks if the user wants to play again
			if (playagain == 'n' || playagain == 'N')
			{
				quit = true;
			}
		}
		else
		{
			cout << "\n\n\nYou have lost too many times. Please go do something else.\n\n";
		}
	}
}
