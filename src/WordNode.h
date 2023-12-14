//
// Created by ty024224 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_OZGURTY_WORDNODE_H
#define GRAPH_PUZZLE_GAME_OZGURTY_WORDNODE_H

#include <string>

using namespace std;

class WordNode {
public:
    string word;
    WordNode* next;
    WordNode* prev;
    int number;
    bool visited;
    WordNode() {
        word = "";
        next = nullptr;
        prev = nullptr;
        visited = false;
    }
};

#endif //GRAPH_PUZZLE_GAME_OZGURTY_WORDNODE_H
