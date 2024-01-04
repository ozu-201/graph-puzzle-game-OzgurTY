//
// Created by ty024224 on 12/21/2023.
//
#include <iostream>
#include "src/Array/Graph/PuzzleGame.h"
using namespace std;
int main() {

    
    PuzzleGame *puzzleGame = new PuzzleGame("C:\\Users\\ty024224\\CLionProjects\\graph-puzzle-game-OzgurTY\\dictionary.txt");


//    Test for Dijkstra
    puzzleGame->StartDijkstra("dark", "barn");



//    Test for BFS
    puzzleGame->StartBFS("cat", "dog");



//    Test for All you can implement test cases for trying code. Make sure to chose valid words from dictionary.txt
//    puzzleGame->StartBFS("stone", "score");
//    puzzleGame->StartDijkstra("stone", "score");



}
