//
// Created by ty024224 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_OZGURTY_GRAPH_H
#define GRAPH_PUZZLE_GAME_OZGURTY_GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <queue> //I will rewrite it
#include <stack> //I will rewrite it
#include <array> //I will rewrite it
#include "WordNode.h"

using namespace std;

bool compare(const string& a, const string& b) {
    return (a.size() < b.size());
}

class Graph {
    friend class WordNode;
public:
    fstream inputFile;
    string temp;
    string file = "dictionary";
    vector<string> dictionary;
    vector<WordNode*> graph;
    WordNode* Node = nullptr;
    int length;
    int startIndex;
    int endIndex;
    WordNode* current;
    int size[16];

    void build() {
        inputFile.open(file);

        if (!inputFile) {
            throw "ERROR! NO FILE!";
        }

        for (int i = 0; i < 16; i++) {
            size[i] = -1;
        }

        while (inputFile >> temp) {
            dictionary.push_back(temp);
            sort(dictionary.begin(), dictionary.end(), compare)
        }

        for (int i = 0; i < dictionary.size(); i++) {
            Node = new WordNode();
            Node->number = i;
            Node->word = dictionary[i];
            graph.push_back(Node);
        }

        for (int i = 0; i < graph.size(); i++) {
            length = graph[i]->word.size();
            if (size[length] == -1){
                size[length] = graph[i]->number;
            }
        }

        for (int i = 0; i < dictionary.size(); i++) {
            if (size[graph[i]->word.size()] != 0) {
                //TODO strartIndex imp.
            }
        }
    }
};

#endif //GRAPH_PUZZLE_GAME_OZGURTY_GRAPH_H
