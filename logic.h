#pragma once
#include <string>
using namespace std;

class logic {
public:
    logic();
    void introduction();
    bool createLists();
    bool playGame();
    string scrambler(string word);
    void end();

private:
    int numCorrect;
    int smallWordLength;
    int mediumWordLength;
    int largeWordLength;

    string smallWords[50];
    string mediumWords[50];
    string largeWords[50];

    string getRandomWord(string words[], int length);
};