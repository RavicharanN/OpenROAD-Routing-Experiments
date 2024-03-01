#include <iostream>
#include "source/AStar.hpp"
#include <chrono>
#include <random>
using namespace std;

void createMaze(AStar::Generator &generator)
{
    std::mt19937 rng(1203);
    int lower = 1;
    int upper  = 500; 
    vector<int> x_coords;
    vector<int> y_coords;

    for (int i = 0; i < 70; i++)
    {
        int rand_num = rng() % (upper - lower + 1) + lower;
        x_coords.push_back(rand_num);
        //cout << rand_num << " ";
    }
    cout << "\n";

    for (int i = 0; i < 70; i++)
    {
        int rand_num = rng() % (upper - lower + 1) + lower;
        y_coords.push_back(rand_num);
        //cout << rand_num << " ";
    }
    cout << "\n";

    for (int i = 0; i < x_coords.size(); i++)
    {
        for (int j = 0; j < y_coords.size(); j++)
        {
            generator.addCollision({x_coords[i], y_coords[j]});
        }
    }
}

int main()
{
    AStar::Generator generator;
    generator.setWorldSize({100, 100});
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(false);

    // Add obstacles to the maze
    createMaze(generator);

    std::cout << "Generate path ... \n";

    // Target method to time: 
    auto start_time = chrono::steady_clock::now();
    auto path = generator.findPath({0, 0}, {99, 99});
    auto end_time = chrono::steady_clock::now();

    for(auto& coordinate : path) {
        std::cout << coordinate.x << " " << coordinate.y << "\n";
    }

    cout << "Time Taken to finsih execution: ";
    auto duration = std::chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << duration.count() << " ms \n";
}