🎮 What is Hangman?
Hangman is a classic word guessing game where you try to guess a hidden word one letter at a time. With each incorrect guess, a part of a stickman is drawn. If the full hangman is drawn before you guess the word — you lose!

✅ Features of This Game
🧠 3 Difficulty Levels — Easy, Medium, and Hard

🖼️ ASCII Art Hangman Drawing — updates with each wrong guess

🔁 Replay Option — Play as many rounds as you like

🧍‍♂️ Object-Oriented Design — Clean, modular code

✅ Validates Input — Prevents repeated or invalid guesses

💬 User-Friendly Prompts — Easy to understand instructions

🕹️ How to Play
Run the program — It will ask you to choose a difficulty level:

markdown
Copy
Edit
1. Easy
2. Medium
3. Hard
Select the level by typing 1, 2, or 3 and pressing Enter.

The game will:

Randomly choose a word of that difficulty.

Show you blank spaces _ _ _ representing the letters in the word.

Give you 6 lives (wrong guesses allowed).

Your job: Guess one letter at a time.

Example:

less
Copy
Edit
Enter a letter: a
✅ Good guess!
If you guess wrong, you lose a life and the hangman drawing progresses.

Game ends when:

You guess the full word → 🎉 You win!

You use up all 6 lives → 💀 You lose. The word is revealed.

After the game, you will be asked:

vbnet
Copy
Edit
🔁 Do you want to play again? (y/n):
📝 Rules
You must enter a single letter each time (no numbers or special characters).

You cannot guess the same letter twice.

The game is case-insensitive (both A and a are treated the same).

Guess the whole word before the hangman is fully drawn!

💡 Sample Game
less
Copy
Edit
Choose difficulty level:
1. Easy
2. Medium
3. Hard
Enter your choice (1-3): 2

🎮 HANGMAN STARTED! Word has 5 letters. You have 6 lives.

_ _ _ _ _

Enter a letter: a
✅ Good guess!

a _ _ _ _

Enter a letter: z
❌ Wrong guess. Tries left: 5

[ASCII Hangman drawing appears]

Keep guessing until you win or lose!
🧑‍💻 How to Compile and Run
Save the file as hangman.cpp.

Open terminal / command prompt and run:

bash
Copy
Edit
g++ hangman.cpp -o hangman
./hangman   # (or hangman.exe on Windows)
📦 Requirements
A C++ compiler (like g++)

Console or terminal access

✨ Credits
Built with ❤️ using C++

ASCII art sourced from classic Hangman visuals

