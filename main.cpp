#include "Item.h"
#include "Inventory.h"
#include "I_Displayable.h"
#include "ItemsInitializer.h"
#include "EnumIterator.h"

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

using std::cout;
using std::move;
using std::make_unique;

int main(){

    Inventory TestInventory;

    // Use a Mersenne Twister engine for better randomness
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, static_cast<int>(ItemsInitializer::ItemsIndex::_END_) - 1);

    for (int i  = 0; i < 1000; i++){
        // get random index
        int num = dis(gen);

        auto index = static_cast<ItemsInitializer::ItemsIndex>(num);
        TestInventory.addItem(index);
    }


    // TEST INVENTORY
    TestInventory.sortByName();
    cout << TestInventory << "\n\n";

    string testInput;
    cout << "What item would you like to remove from the Inventory? ";
    std::getline(std::cin, testInput);

    TestInventory.removeItemByName(testInput);

    //TestInventory.sortByIndex();

    cout << TestInventory << "\n\n";
    
    return 0;
}
