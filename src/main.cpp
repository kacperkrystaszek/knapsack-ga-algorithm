#include "GeneticAlgorithm.h"
#include "Item.h"
#include "Knapsack.h"

int main (int argc, char* argv[]) {
    int numItems = 20;
    int maxWeight = 100;
    int maxValue = 200;
    int capacity = 250;

    std::vector<Item> items;
    if(argc > 1){
        numItems = std::stoi(argv[1]);
    }
    if(argc > 2){
        numItems = std::stoi(argv[2]);
    }
    if(argc > 3){
        numItems = std::stoi(argv[3]);
    }
    if(argc > 4){
        numItems = std::stoi(argv[4]);
    }

    Knapsack knapsack = Knapsack::generateRandom(numItems, maxWeight, maxValue, capacity);
    
    GeneticAlgorithm solver(knapsack);
    auto[bestSolution, lastGenSolution] = solver.solve();
    std::cout << "Best solution" << std::endl;
    knapsack.printSolution(bestSolution);
    std::cout << "Last gen solution" << std::endl;
    knapsack.printSolution(lastGenSolution);

    return 0;
}   