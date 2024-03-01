## A* algorithm [![Build Status](https://travis-ci.org/daancode/a-star.svg?branch=master)](https://travis-ci.org/da-an/SHA-1)
A* search algorithm written in C++ programming language.
 - requires compiler support for C++11

## Parallel A* 

* All experiments were on a Virtual Box with 2 cores and 3 gigs RAM and were controlled
* To mimic the experiment we added a uniform noise while computing the cost
* To keep things consistent accross experiments we were using the same grid to compare performances 
* Did not see as much improment as expected - machine limitations (?)
* Alternatives for compute / bencharmking suggestions needed ?? 

#### Experiment1: 25x25 grid (40 percent occupied) : ~1ms sleep on prcoessing every successor

* Single thread runtime: ~ 1700 ms
* 2 threads OMP ~ 1400 ms
* 3,4 threads OMP ~ 1600 ms 

#### Experiment1: 100x100 grid (50 percent occupied) : ~100ns sleep on prcoessing every successor

* Single thread runtime: ~ 6000 ms
* 2 threads OMP ~ 5500 ms
* 3,4 threads OMP ~ 6000 ms 



#### Usage example
```cpp
#include <iostream>
#include "source/AStar.hpp"

int main()
{
    AStar::Generator generator;
    // Set 2d map size.
    generator.setWorldSize({25, 25});
    createMaze()
    // You can use a few heuristics : manhattan, euclidean or octagonal.
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(true);

    std::cout << "Generate path ... \n";
    // This method returns vector of coordinates from target to source.
    auto path = generator.findPath({0, 0}, {20, 20});

    for(auto& coordinate : path) {
        std::cout << coordinate.x << " " << coordinate.y << "\n";
    }
}
```
