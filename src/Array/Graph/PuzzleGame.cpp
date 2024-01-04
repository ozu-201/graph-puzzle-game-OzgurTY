//
// Created by ty024224 on 1/4/2024.
//

#include "PuzzleGame.h"
#pragma execution_character_set("utf-8")

using namespace std;


PuzzleGame::PuzzleGame(string nameOfDictionary) {

    string line;
    ifstream file;
    file.open(nameOfDictionary);

    vector<string> ThreeWords;
    vector<string> FourWords;
    vector<string> FiveWords;

    if (file.is_open()) {
        while (getline(file,line)) {
            if (line.length() == 3) {
                ThreeWords.push_back(line);
            }

            if (line.length() == 4) {
                FourWords.push_back(line);
            }

            if (line.length() == 5) {
                FiveWords.push_back(line);
            }
        }
        file.close();
    }

    ThreeGraph = new array::Graph(ThreeWords.size());
    ThreeGraph->setWords(ThreeWords);

    FourGraph = new array::Graph(FourWords.size());
    FourGraph->setWords(FourWords);

    FiveGraph = new array::Graph(FiveWords.size());
    FiveGraph->setWords(FiveWords);
}

void PuzzleGame::StartBFS(string startingWord, string endingWord) {

    array::Graph *chosenGraph = nullptr;

    if (startingWord.length() != endingWord.length()) {
        std::cout << "Please enter same length words and make them 3-5 characters."<< "\n";
        return;
    } else if (startingWord.length() == 3) {
        chosenGraph = this->ThreeGraph;
    } else if (startingWord.length() == 4) {
        chosenGraph = this->FourGraph;
    } else if (startingWord.length() == 5) {
        chosenGraph = this->FiveGraph;
    } else {
        cout << "Please enter 3-5 character length words!"<< "\n";
    }

    if (checkExists(startingWord) && checkExists(endingWord)) {
        cout << "Valid." << "\n";
    } else {
        cout << "At least one of the inputs don't exist in the dictionary."<< "\n";
        return;
    }

    chosenGraph->connectWords();

    int startingIndex = 0;
    int endingIndex = 0;

    for (int i = 0; i < chosenGraph->words.size(); i++) {
        if (chosenGraph->words[i] == startingWord) {
            startingIndex = i;
        }

        if (chosenGraph->words[i] == endingWord) {
            endingIndex = i;
        }

        if (endingIndex != 0 && startingIndex != 0) {
            break;
        }
    }

    chosenGraph->wordBreadthFirstSearch (startingIndex,endingIndex);

}

bool PuzzleGame::checkExists(string word) {

    array::Graph *graph;

    if (word.length() == 3) {
        graph = this->ThreeGraph;
    } else if (word.length() == 4) {
        graph = this->FourGraph;
    } else if (word.length() == 5) {
        graph = this->FiveGraph;
    } else {
        return false;
    }

    for (int i = 0; i < graph->getWords().size(); i++) {
        if (graph->getWords()[i] == word) {
            return true;
        }
    }
    return false;
}


void PuzzleGame::StartDijkstra(string startingWord, string endingWord) {

    array::Graph *chosenGraph = nullptr;

    if (startingWord.length() != endingWord.length()) {
        cout << "Please enter same length words and make them 3-5 characters."<< "\n";
        return;
    } else if (startingWord.length() == 3) {
        chosenGraph = this->ThreeGraph;
    } else if (startingWord.length() == 4) {
        chosenGraph = this->FourGraph;
    } else if (startingWord.length() == 5) {
        chosenGraph = this->FiveGraph;
    } else {
        cout << "Please enter 3-5 character length words!"<< "\n";
    }

    if (checkExists(startingWord) && checkExists(endingWord)) {
        cout << "Valid." << "\n";
    } else {
        cout << "At least one of the inputs don't exist in the dictionary."<< "\n";
        return;
    }

    chosenGraph->connectWords();

    int startIndx = 0;
    int endIndx = 0;

    for (int i = 0; i < chosenGraph->words.size(); i++) {
        if (chosenGraph->words[i] == startingWord) {
            startIndx = i;
        }

        if (chosenGraph->words[i] == endingWord) {
            endIndx = i;
        }

        if (endIndx != 0 && startIndx != 0) {
            break;
        }
    }

    chosenGraph->wordBreadthFirstSearch (startIndx, endIndx);

}


