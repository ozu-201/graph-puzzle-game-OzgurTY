//
// Created by ty024224 on 1/4/2024.
//

#ifndef GRAPH_PUZZLE_GAME_OZGURTY_PUZZLEGAME_H
#define GRAPH_PUZZLE_GAME_OZGURTY_PUZZLEGAME_H

#include "Graph.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class PuzzleGame {

public:
    array::Graph * ThreeGraph;
    array::Graph * FourGraph;
    array::Graph * FiveGraph;

    PuzzleGame(std::string nameOfDictionary);

    void StartBFS(std::string startingWord, std::string endingWord);

    bool checkExists(std::string word);

    void StartDijkstra(std::string startingWord, std::string endingWord);

};


#endif //GRAPH_PUZZLE_GAME_OZGURTY_PUZZLEGAME_H
