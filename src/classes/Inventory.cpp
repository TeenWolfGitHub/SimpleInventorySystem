#include "Inventory.h"

#include "ItemsInitializer.h"
#include "Item.h"
#include "Weapon.h"
#include "Miscellaneous.h"
#include "EnumIterator.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <functional>

using std::cout;
using std::vector;
using std::string;
using std::ostream;
using std::setw;
using std::left;
using std::unique_ptr;
using std::make_unique;

/*----------------------------------------------------------------------------------------------------------------*/
// HELPERS
/*----------------------------------------------------------------------------------------------------------------*/

// Function to compare the objects pointed to by two unique_ptr<Item> through their name attribute
bool isTheSameAs(const unique_ptr<Item>& item1, const unique_ptr<Item>& item2) {
    return item1->getName() == item2->getName();
}

// Helper function for sorting methods - takes a lamda/function as an argument
void Inventory::sortBy(const std::function<bool(const unique_ptr<Item>& lhs, const unique_ptr<Item>& rhs)>& comparator) {
    std::sort(InventoryItems.begin(), InventoryItems.end() , comparator);
}

/*----------------------------------------------------------------------------------------------------------------*/
// INVENTORY CLASS METHODS
/*----------------------------------------------------------------------------------------------------------------*/

// GETTER(s)
// Return const reference to the vector - This prevents the necessity to pass ownership and problems with unique_ptr
const vector<unique_ptr<Item>>& Inventory::get() {
    return InventoryItems;
}

// OVERRIDE(s)
// Display logic (accessed through operator<<) - Display items in stacks if there are duplicates
void Inventory::display(ostream& os) const {
    if (InventoryItems.empty()){
        os << "Inventory is empty!\n";
        return;
    }
    os <<  "DISPLAYING INVENTORY (" << currentWeightKg << " / " << weightCapacityKg << " Kg)\n";
    // track already printed items
    std::vector<bool> printed(InventoryItems.size(), false);
    // Iterate over all items in the inventory
    for (size_t i = 0; i < InventoryItems.size(); ++i) {
        if (printed.at(i)) {
            continue;  // Skip this item if it's already been displayed as a duplicate
        }
        auto& item = InventoryItems.at(i);
        // Count how many times this item appears in the inventory
        int count = std::count_if(InventoryItems.begin(), InventoryItems.end(),
            [&item](const unique_ptr<Item>& otherItem) {
                return isTheSameAs(item, otherItem);
            });
        // Display the item and the number of duplicates
        os << "x" << setw(10) << left << count << *item << "\n";
        // Mark all instances of this item as printed
        for (size_t j = i; j < InventoryItems.size(); ++j) {
            if (isTheSameAs(item, InventoryItems.at(j))) {
                printed.at(j) = true;
            }
        }
    }
}

// CUSTOM METHODS
// Add an item to the vector by index - Make a copy from the static items map and stores it as a compatible unique_ptr
void Inventory::addItem(ItemsInitializer::ItemsIndex newItemIndex) {
    if (this->currentWeightKg > this->weightCapacityKg) {
        cout << "Inventory is full! Cannot add any more items\n";
        return;
    }

    // Get the shared_ptr<Item> from the map
    auto sharedItemPtr = ItemsInitializer::getItems().at(newItemIndex);
    // Check what type of item - Try to cast to shared_ptr<Subclass> if successful add a new unique_ptr<Subclass> to the vector
    if (auto newItem = std::dynamic_pointer_cast<Weapon>(sharedItemPtr)) {
        InventoryItems.push_back(make_unique<Weapon>(*newItem));
        this->currentWeightKg += newItem->getWeight();
    } else if (auto newItem = std::dynamic_pointer_cast<Miscellaneous>(sharedItemPtr)){
        InventoryItems.push_back(make_unique<Miscellaneous>(*newItem));
        this->currentWeightKg += newItem->getWeight();
    } else InventoryItems.push_back(make_unique<Item>(*sharedItemPtr));
}

// Remove an item from the vector by name
void Inventory::removeItemByName(string name) {
    // Count items with the specified name
    int count = std::count_if(InventoryItems.begin(), InventoryItems.end(),
                              [&name](const std::unique_ptr<Item>& item) { return item->getName() == name; });

    // Early exit if no corresponding item is found
    if (count == 0) {
            cout << name << "not found in inventory!\n";
            return;
    }

    cout << "There are " << count << " " + name + ".\n";
    int numToRemove{0};

    // Ask user how many of them to remove - Check for valid input (no type checking for now)
    do
    {
        cout << "How many would you like to toss? ";
        std::cin >> numToRemove; 
    } while (numToRemove > count || numToRemove < 0);

    // Early exit if user enters 0
    if (numToRemove == 0) {
        cout << "Not Removing any.\n";
        return;
    }

    // Loop through vector and remove correspoding items numToRemove times
    for (int i = 0; i < numToRemove; i++) {
        for (auto it = InventoryItems.begin(); it != InventoryItems.end(); it ++){
            auto& item = *it;
            if (item->getName() == name) {
                this->currentWeightKg -= item->getWeight();
                InventoryItems.erase(it);
                break;
            } else continue;
        }
    }
    cout << "Removed " << numToRemove << " " + name + " successfully!\n";
}

// Sort Inventory following defined order in ItemsInitializer::ItemsIndexes
void Inventory::sortByIndex() {
    // Check if inventory is empty
    if (InventoryItems.empty()) {
        return;
    }
    std::cout << "\n\nSorting by index...\n\n";
    // Create a multimap to store items by their name (allows duplicates)
    std::multimap<std::string, unique_ptr<Item>> itemMap;
    // Populate the multimap with items from the inventory
    for (auto& item : InventoryItems) {
        itemMap.emplace(item->getName(), std::move(item));
    }
    // Create a temporary vector to store the sorted items
    std::vector<unique_ptr<Item>> temp;
    // Initialize a EnumIterator
    typedef EnumIterator<ItemsInitializer::ItemsIndex, ItemsInitializer::ItemsIndex::WOODEN_HAMMER, ItemsInitializer::ItemsIndex::_END_> ItemsIndexes;
    // Iterate through the predefined order of items (from ItemsIndex)
    for (auto i : ItemsIndexes()) {
        const auto& predefinedItem = ItemsInitializer::getItems().at(i);
        // Find all items with the name of the predefined item in the multimap
        auto range = itemMap.equal_range(predefinedItem->getName());
        for (auto it = range.first; it != range.second; ++it) {
            // Move each matching item to the temp vector
            temp.push_back(std::move(it->second));
        }        
        // Erase the items from the multimap after moving them
        itemMap.erase(range.first, range.second);
    }
    // Add remaining items (those not in the predefined order) to temp
    for (auto& pair : itemMap) {
        temp.push_back(std::move(pair.second));  // Move the remaining items to temp
    }
    // Swap the temp vector back to InventoryItems
    temp.swap(InventoryItems);
}

// Sort Inventory alphabetically (by name A-Z)
void Inventory::sortByName() {
    sortBy([](const unique_ptr<Item>& lhs, const unique_ptr<Item>& rhs) { return lhs->getName() < rhs->getName(); });
}

// Sort Inventory alphabetically (by name Z-A)
void Inventory::sortByNameInversed() {
    sortBy([](const unique_ptr<Item>& lhs, const unique_ptr<Item>& rhs) { return lhs->getName() > rhs->getName(); });
}

// Sort Inventory by item rarity (Common to Unique)
void Inventory::sortByRarity() {
    sortBy([](const unique_ptr<Item>& lhs, const unique_ptr<Item>& rhs) { return lhs->getItemRarity() < rhs->getItemRarity(); });
}

// Sort Inventory by item rarity (Unique to Common)
void Inventory::sortByRarityInversed() {
    sortBy([](const unique_ptr<Item>& lhs, const unique_ptr<Item>& rhs) { return lhs->getItemRarity() > rhs->getItemRarity(); });
}

// Sort Inventory by Type
void Inventory::sortByType() {
    sortBy([](const unique_ptr<Item>& lhs, const unique_ptr<Item>& rhs) { return lhs->getItemType() < rhs->getItemType(); });
}