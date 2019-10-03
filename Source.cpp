#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
 
int main()
{
	//Lines 11-25 initialize the criteria for the array, the number of words possible, and the words/hints themselves, respectively
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"russia", "1960's enemy"},
		{"president", "Your commanding officer"},
		{"dotmatrix", "Ask your parents"},
		{"cia", "...really? You need a hint for this?"},
		{"mcduck", "Woo-oo!"},
		{"python", "Has a nasty sting"},
		{"alternate", "Try another option"},
		{"reality", "Fiction's better"},
		{"game", "Let's play"},
		{"sequel", "Electric Boogaloo"},
	};
	//A string variable to hold the player's response on if they want to start the game over again
	string answer;
	//An integer variable that holds the amount of times a player gets an answer wrong
	int WrongAnswers = 0;

	//Introduction
	cout << "\t\t***Welcome to this training exercise.***" << endl;
	cout << "\tYou are tasked with finding the enemy's jumbled words in order to better your country." << endl;
	cout << "\tWhile these words may not be the enemy's code words, they are still excellent practice for you." << endl;
	cout << "\tEnter 'hint' for a hint and 'quit' to quit the game" << endl << endl << endl;

	//Run the game while the player wants to keep playing
	do {
		//RNG seed
		srand(time(NULL));

		//For each game, give three jumbles
		for (int j = 0; j < 3; ++j)
		{
			//Lines 46-58 jumble the words themselves by putting each letter into a random position
			int choice = (rand() % NUM_WORDS);
			string word = WORDS[choice][WORD];
			string hint = WORDS[choice][HINT];
			string jumble = word;
			int length = jumble.size();
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}


			
			cout << "Your jumble is: " << jumble << endl;
			//A string variable that hold the player's guess
			string guess;
			cout << "Your guess: ";
			cin >> guess;

			//If the player doesn't input the correct word and doesn't answer "quit"...
			while ((guess != word) && (guess != "quit"))
			{
				//If they ask for a hint...
				if (guess == "hint")
				{
					//...give the hint for that jumble
					cout << hint << endl;;
				}
				//Otherwise, if the answer is incorrect...
				else
				{
					//...tell the player they are wrong and add one to the incorrect answers variable.
					cout << "Incorrect" << endl;
					WrongAnswers += 1;
				}
				cout << "Your guess: ";
				cin >> guess;
			}

			//If they get the jumble correct...
			if (guess == word)
			{
				//...tell them so and move on to the next jumble
				cout << "Correct!" << endl << endl << endl;
			}
			
			//If the player wants to quit...
			if (guess == "quit")
			{
				//...quit out of the program
				cout << "Quitter." << endl;
				return 0;
			}
		}
		//Asks the player if they want to keep playing
		cout << "Good work soldier. A perfect score is 0 incorrect answers. You got " << WrongAnswers << " answer(s) wrong. Train again? (Y/N) ";
		cin >> answer;
	} while (answer == "Y"); //If they answer "Y", then the loop plays again
	//Otherwise, the program exits.
	cout << "Dismissed" << endl;
}