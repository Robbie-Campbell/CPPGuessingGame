#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class guesser
{
public:
	void guess()
	{
		srand((unsigned) time(0));
		int computerGuess = rand() % 10 + 1;
		while (tries < 2)
		{
			cout << "Please guess a number between 1 and 10" << endl;
			cin >> guessAttempt;
			if (guessAttempt == computerGuess)
			{
				cout << "Congratulations! " << computerGuess << " was the correct answer!" << endl;
				break;
			}
			else if (tries < 2)
			{
				tries++;
				if (guessAttempt < computerGuess)
				{
					cout << "Your guess is too low" << endl;
					continue;
				}
				else
				{
					cout << "Your guess is too high" << endl;
					continue;
				}
			}
		}
		if ( tries == 2)
		{
			cout << "That was wrong, the number was: " << computerGuess << " better luck next time!" << endl;
		}
		cout << "Would you like to play again? (y/n):" << endl;
		cin >> playAgain;
		if (playAgain == "y")
		{
			tries = 0;
			guess();
		}
		else
		{
			cout << "Thanks for playing!" << endl;
			cin.get();
		}
	}
private:
	int computerGuess;
	int guessAttempt;
	string playAgain;
	int tries = 0;
};

int main()
{
	guesser guessingGame;
	guessingGame.guess();
	return 0;
}