#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
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
	string answer;
	do {
		srand(time(NULL));
		cout << "Welcome to this training exercise." << endl;
		cout << "You are tasked with finding the enemy's jumbled words in order to better your country." << endl;
		cout << "While these words may not be the enemy's code words, they are still excellent practice for you." << endl;
		cout << "Enter 'hint' for a hint and 'quit' to quit the game" << endl;
		for (int j = 0; j < 3; ++j)
		{
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

			string guess;
			cout << "Your guess: ";
			cin >> guess;

			while ((guess != word) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << hint << endl;;
				}
				else
				{
					cout << "Incorrect" << endl;
				}
				cout << "Your guess: ";
				cin >> guess;
			}

			if (guess == word)
			{
				cout << "Correct!" << endl << endl << endl;
			}
		}
		cout << "Good work soldier. Train again? (Y/N) ";
		cin >> answer;
	} while (answer == "Y");
	cout << "Dismissed" << endl;
}