#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cctype>
#include <algorithm>

int main() {
	//setup
	
	std::vector<std::string> wordList;
	wordList.push_back("NINTENDO");
	wordList.push_back("SEGA");
	wordList.push_back("SONY");
	wordList.push_back("MICROSOFT");

	std::cout << "Welcome to Hangman, where you try to guess a word one letter at a time. Good luck!\n";

	//Entering the game loop(s)

	char playGame('y');

	while (playGame == 'y') {

		srand(static_cast<unsigned int>(time(0))); //seeding for the random_shuffle algorithm
		random_shuffle(wordList.begin(), wordList.end()); //This and the above ensure a random word each playthrough
		std::string theWord = wordList[0];
		std::string soFar(theWord.size(), '_');
		std::string used("");
		int tries(8);
		char guess;
		
		while (tries > 0 && soFar != theWord) {
			std::cout << "\nRemaining tries: " << tries;
			std::cout << "\nLetters used so far: " << used;
			std::cout << "\nThe word so far: " << soFar;
			std::cout << "\nYour guess: ";
			std::cin >> guess;
			guess = toupper(guess);

			//This section notifies the player if they already guessed certain letter
			
			while (used.find(guess) != std::string::npos) {
				std::cout << "\nSorry, you've already guessed this letter.";
				std::cout << "\nRemaining tries: " << tries;
				std::cout << "\nLetters used so far: " << used;
				std::cout << "\nThe word so far: " << soFar;
				std::cout << "\nYour guess: ";
				std::cin >> guess;
				guess = toupper(guess);
			}

			used += guess;

			if (theWord.find(guess) != std::string::npos) {
				for (int i = 0; i < theWord.size(); ++i) {
					if (theWord[i] == guess) {
						soFar[i] = theWord[i];
					}
				}
				std::cout << "\nYes! The letter '" << guess << "' is in the word.";
			}
			else if (theWord.find(guess) == std::string::npos) {
				std::cout << "\nSorry, that letter is not in the word.";
				--tries;
			}
		}
		
		//Shut down Area

		if (soFar == theWord) {
			std::cout << "\t\t\t\t\n\nBITCH U GUESSED IT......HOOO...!!!!.....you was right...";
			std::cout << "\nThe word was: " << theWord;
		}
		else if (soFar != theWord || tries == 0) {
			std::cout << "\t\t\t\t\n\nTime for a hanging NIGGER!!!";
			std::cout << "\nThe word was: " << theWord;
		}
		
		std::cout << "\n\nWould you like to play again? (y or n): ";
		std::cin >> playGame;
		if (playGame == 'y') {
			continue;
		}
		else if (playGame == 'n') {
			break;
		}
	}

	std::cout << "\t\t\t\t\n\nThank you so much for playing! Have a great day." << std::endl;

	return 0;
}