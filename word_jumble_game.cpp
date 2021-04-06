#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main() {
	enum Fields { WORD, HINT, NUM_FIELDS };
	const int wordsTotal = 5;
	const std::string wordMix[wordsTotal][NUM_FIELDS]
	{
		{ "burger", "Something delicious..." },
		{ "knuckles", "A red echidna..." },
		{ "nintendo", "Legendary gaming company" },
		{ "rayman", "Limbless gaming icon!" },
		{ "michael", "Hee-hee!" }
	};
	
	gameRepeat:
	//randomized word selection
	srand(static_cast<unsigned int>(time(0)));
	int numberGen = (rand() % wordsTotal);
	std::string theWord = wordMix[numberGen][WORD];
	std::string hint = wordMix[numberGen][HINT];
	
	//jumble:
	std::string jumble(theWord);
	int length = theWord.size();
	char temp;

	for (int i = 0; i < length; ++i) {
		int index1 = (rand() % length); // rand() generates a new number each time it's called
		int index2 = (rand() % length); // this and the above code each find a random number between 0 and theWord's total index size
		temp = jumble[index1]; // this code "saves" the specific char in the word's first selected index slot so it's not lost
		jumble[index1] = jumble[index2]; // this code makes the code in one position equal to that of another
		jumble[index2] = temp; // this code completes the "swap" by setting the second position's char to the first's that was saved
	}

	//game and loop:

	int tries(5), score(10);
	std::string guess;

	std::cout << "\t\tWelcome to Word Jumble!\n\n";
	std::cout << "In this game, you try to guess what the jumbled word is.\n";
	std::cout << "You have " << tries << " tries and start with a score of " << score << "\n";
	std::cout << "If you're stuck, you can ask for a hint. You can also quit at any time.\n\n";
	std::cout << "Here's the jumbled word: " << jumble << "\n";
	std::cout << "Please enter your guess: ";
	std::cin >> guess;

	while (tries > 0) {
		
		if (tries > 0 && guess != theWord && guess != "hint" && guess != "quit") {
			
			score -= theWord.size();
			score < 0 ? score = 0 : score = score;
			tries -= 1;
			std::cout << "\nSorry fam...try again...\n";
			std::cout << "Current Score: " << score << "\n";
			std::cout << "Tries Remaining: " << tries << "\n\n";
			std::cout << "Again, the jumbled word is: " << jumble << "\n";
			std::cout << "Your next guess: ";
			std::cin >> guess;
		}
		else if (tries > 0 && guess == "hint") {
			score -= length;
			tries -= 1;
			score < 0 ? score = 0 : score = score;
			std::cout << "\n" << hint;
			std::cout << "\nCurrent Score: " << score;
			std::cout << "\nTries remaining: " << tries;
			std::cout << "\nAgain, the jumbled word is: " << jumble;
			std::cout << "\nYour next guess: ";
			std::cin >> guess;
		}
		else if (guess == "quit") {
			std::cout << "\nLittle bitch....bye then...\n\n";
			std::cout << "Bonus for remaining tries: " << (tries *= 2) << "\n";
			std::cout << "Final Score: " << score + tries + length << "\n\n";
			break;
		}
		else if (tries > 0 && guess == theWord) {
			score < 0 ? score = 0 : score = score;
			std::cout << "\nBITCH YOU GUESSED IT......HOO...!!!...you was right...\n\n";
			std::cout << "Bonus for remaining tries: " << (tries *= 2) << "\n";
			std::cout << "Final Score: " << score + tries + length << "\n\n";
			break;
		}
	}
	char playAgain;
	std::cout << "\t\tPlay again? (y or n)\n";
	std::cin >> playAgain;
	switch (playAgain) {
	case ('y'):
		goto gameRepeat;
		break;
	default:
		std::cout << "\nThanks for playing! Now get the hell on.";
	}


	return 0;
}