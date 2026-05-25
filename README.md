# CPSC440 Word Scramble Game

## Description
This is a C++ word scramble game created for CPSC440. The game challenges players to unscramble five randomly scrambled words within a 60-second time limit for each word. At the end of the game, the player's intellect level is measured based on the number of correctly unscrambled words.

## Features
- Reads words from `dictionary.txt`
- Stores words into three difficulty arrays:
  - Small words (4–5 letters)
  - Medium words (6–7 letters)
  - Large words (8+ letters)
- Randomly scrambles words
- Gives players 60 seconds to answer each word
- Tracks correct answers
- Displays a fun intellect ranking at the end

## How the Game Works
1. The player is presented with 5 scrambled words.
2. The first 2 words are small words.
3. The next 2 words are medium words.
4. The final word is a large word.
5. The player has 60 seconds to unscramble each word.
6. The final score determines the player's intellect level.

## Intellect Levels
- 0–1 Correct: Sleeping Rock
- 2 Correct: Starter Brain
- 3 Correct: Sharp Thinker
- 4 Correct: Brain Beast
- 5 Correct: Supreme Intellect

## Files Included
- `main.cpp` → Main program execution
- `logic.h` → Class declarations
- `logic.cpp` → Game logic implementation
- `dictionary.txt` → Word list used by the game

## Requirements
- C++
- Visual Studio
- `dictionary.txt` must be in the project folder

## Author
Joel Adu