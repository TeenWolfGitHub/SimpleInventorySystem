#pragma once

#include "I_Displayable.h"
#include "ItemsInitializer.h"

#include <vector>
#include <string>
#include <memory>
#include <functional>

using std::vector;
using std::string;
using std::unique_ptr;

class Item;

class Inventory : public I_Displayable {
private:
    // Inventory attributes
    vector<unique_ptr<Item>> InventoryItems;     // Vector of unique_ptr so that it can store Item or its subclasses objects polymorphically
    double currentWeightKg{0.0};                   // The current weight of the inventory - Equals the sum of the weights of the items contained in it
    double weightCapacityKg{1000.0};                // An inventory has a maximum weight capacity - Exceeding it, will lock it from adding more items

    // Override(s)
    virtual void display(ostream& os) const;   // Display logic
public:
    // Getter(s)
    const vector<unique_ptr<Item>>& get();

    // Methods
    void addItem(ItemsInitializer::ItemsIndex newItemIndex);        // Add item by index
    void removeItemByName(string name);                             // Remove item by name

    void sortBy(const std::function<bool(const unique_ptr<Item>& lhs, const unique_ptr<Item>& rhs)>& comparator);  // Helper function for the sorting methods - takes lambda as argument
    void sortByIndex();             // Sort Inventory following defined order in ItemsInitializer::ItemsIndexes
    void sortByName();              // Sort Inventory alphabetically (by name A-Z)
    void sortByNameInversed();      // Sort Inventory alphabetically (by name Z-A)
    void sortByRarity();            // Sort Inventory by item rarity (Common to Unique)
    void sortByRarityInversed();    // Sort Inventory by item rarity (Unique to Common)
    void sortByType();              // Sort Inventory by Type
};