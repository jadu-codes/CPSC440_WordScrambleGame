#include "logic.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include <future>
#include <chrono>

using namespace std;

logic::logic() {
    numCorrect = 0;
    smallWordLength = 0;
    mediumWordLength = 0;
    largeWordLength = 0;
    srand((unsigned int)time(0));
}

void logic::introduction() {
    cout << "=====================================\n";
    cout << "       WORD SCRAMBLE INTELLECT GAME\n";
    cout << "=====================================\n";
    cout << "You will unscramble 5 words.\n";
    cout << "You have 60 seconds for each word.\n\n";
}

bool logic::createLists() {
    ifstream file("dictionary.txt");

    if (!file) {
        cout << "Error: dictionary.txt could not be opened.\n";
        return false;
    }

    string word;

    while (file >> word) {
        int len = word.length();

        if ((len == 4 || len == 5) && smallWordLength < 50) {
            smallWords[smallWordLength++] = word;
        }
        else if ((len == 6 || len == 7) && mediumWordLength < 50) {
            mediumWords[mediumWordLength++] = word;
        }
        else if (len >= 8 && largeWordLength < 50) {
            largeWords[largeWordLength++] = word;
        }
    }

    file.close();

    return smallWordLength >= 2 && mediumWordLength >= 2 && largeWordLength >= 1;
}

string logic::scrambler(string word) {
    string scrambled = word;

    random_device rd;
    mt19937 generator(rd());

    do {
        shuffle(scrambled.begin(), scrambled.end(), generator);
    } while (scrambled == word && word.length() > 1);

    return scrambled;
}

string logic::getRandomWord(string words[], int length) {
    int index = rand() % length;
    return words[index];
}

bool logic::playGame() {
    string selectedWords[5];

    selectedWords[0] = getRandomWord(smallWords, smallWordLength);
    selectedWords[1] = getRandomWord(smallWords, smallWordLength);
    selectedWords[2] = getRandomWord(mediumWords, mediumWordLength);
    selectedWords[3] = getRandomWord(mediumWords, mediumWordLength);
    selectedWords[4] = getRandomWord(largeWords, largeWordLength);

    for (int i = 0; i < 5; i++) {
        string answer;
        string scrambled = scrambler(selectedWords[i]);

        cout << "\nWord " << i + 1 << " of 5\n";
        cout << "Unscramble this word: " << scrambled << endl;
        cout << "You have 60 seconds: ";

        auto futureInput = async(launch::async, [] {
            string input;
            cin >> input;
            return input;
            });

        if (futureInput.wait_for(chrono::seconds(60)) == future_status::ready) {
            answer = futureInput.get();

            if (answer == selectedWords[i]) {
                cout << "Correct. Your brain is working.\n";
                numCorrect++;
            }
            else {
                cout << "Wrong. The correct word was: " << selectedWords[i] << endl;
            }
        }
        else {
            cout << "\nTime is up. The correct word was: " << selectedWords[i] << endl;
        }
    }

    return numCorrect >= 3;
}

void logic::end() {
    cout << "\n=====================================\n";
    cout << "              GAME OVER\n";
    cout << "=====================================\n";
    cout << "You got " << numCorrect << " out of 5 correct.\n\n";

    if (numCorrect <= 1) {
        cout << "Mind Level: Sleeping Rock. Wake up, genius.\n";
    }
    else if (numCorrect == 2) {
        cout << "Mind Level: Starter Brain. You showed signs of life.\n";
    }
    else if (numCorrect == 3) {
        cout << "Mind Level: Sharp Thinker. Respectable performance.\n";
    }
    else if (numCorrect == 4) {
        cout << "Mind Level: Brain Beast. You are dangerous.\n";
    }
    else {
        cout << "Mind Level: Supreme Intellect. Certified word assassin.\n";
    }
}