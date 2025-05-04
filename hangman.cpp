#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

class Hangman {
private:
    vector<string> easyWords = {"cat", "dog", "sun", "hat", "box"};
    vector<string> mediumWords = {"apple", "chair", "plant", "guitar", "green"};
    vector<string> hardWords = {"hangman", "computer", "difficult", "keyboard", "question"};
    string secretWord;
    vector<char> guessedLetters;
    int tries;
    int maxTries;

    string chooseWord(int level) {
        srand(time(0));
        if (level == 1) return easyWords[rand() % easyWords.size()];
        if (level == 2) return mediumWords[rand() % mediumWords.size()];
        return hardWords[rand() % hardWords.size()];
    }

    void displayWord() {
        for (char ch : secretWord) {
            if (find(guessedLetters.begin(), guessedLetters.end(), ch) != guessedLetters.end()) {
                cout << ch << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }

    void displayHangman() {
        static const string hangmanPics[] = {
            "   +---+\n"
            "       |\n"
            "       |\n"
            "       |\n"
            "      ===",
            "   +---+\n"
            "   O   |\n"
            "       |\n"
            "       |\n"
            "      ===",
            "   +---+\n"
            "   O   |\n"
            "   |   |\n"
            "       |\n"
            "      ===",
            "   +---+\n"
            "   O   |\n"
            "  /|   |\n"
            "       |\n"
            "      ===",
            "   +---+\n"
            "   O   |\n"
            "  /|\\  |\n"
            "       |\n"
            "      ===",
            "   +---+\n"
            "   O   |\n"
            "  /|\\  |\n"
            "  /    |\n"
            "      ===",
            "   +---+\n"
            "   O   |\n"
            "  /|\\  |\n"
            "  / \\  |\n"
            "      ==="
        };
        cout << hangmanPics[maxTries - tries] << endl;
    }

    bool isWordGuessed() {
        for (char ch : secretWord) {
            if (find(guessedLetters.begin(), guessedLetters.end(), ch) == guessedLetters.end()) {
                return false;
            }
        }
        return true;
    }

public:
    void startGame() {
        int level;
        cout << "Choose difficulty level:\n1. Easy\n2. Medium\n3. Hard\nEnter your choice (1-3): ";
        while (!(cin >> level) || level < 1 || level > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter 1, 2, or 3: ";
        }

        secretWord = chooseWord(level);
        guessedLetters.clear();
        maxTries = 6;
        tries = maxTries;

        cout << "\n🎮 HANGMAN STARTED! Word has " << secretWord.length() << " letters. You have " << tries << " lives.\n";

        while (tries > 0) {
            displayHangman();
            displayWord();
            cout << "\nGuessed letters: ";
            for (char c : guessedLetters) cout << c << " ";
            cout << "\n\nEnter a letter: ";
            char guess;
            cin >> guess;
            guess = tolower(guess);

            if (!isalpha(guess)) {
                cout << "❌ Invalid input. Please enter a letter." << endl;
                continue;
            }

            if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
                cout << "⚠️ You already guessed that letter." << endl;
                continue;
            }

            guessedLetters.push_back(guess);

            if (secretWord.find(guess) != string::npos) {
                cout << "✅ Good guess!" << endl;
            } else {
                tries--;
                cout << "❌ Wrong guess. Tries left: " << tries << endl;
            }

            if (isWordGuessed()) {
                cout << "\n🎉 YOU WON! The word was: " << secretWord << endl;
                return;
            }
        }

        displayHangman();
        cout << "\n💀 GAME OVER! The word was: " << secretWord << endl;
    }
};

int main() {
    char playAgain;
    do {
        Hangman game;
        game.startGame();
        cout << "\n🔁 Do you want to play again? (y/n): ";
        cin >> playAgain;
        playAgain = tolower(playAgain);
    } while (playAgain == 'y');

    cout << "\n👋 Thanks for playing Hangman. Goodbye!" << endl;
    return 0;
}
