#include "Item.h"

#include "ItemsInitializer.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using std::ostream;
using std::string;
using std::setw;
using std::left;
using std::map;

/*----------------------------------------------------------------------------------------------------------------*/
// HELPERS PROTOTYPE
/*----------------------------------------------------------------------------------------------------------------*/

// Overloaded toString() function to get string associated to a flag
static string toString(const Item::ItemTypes itemTypeValue);
static string toString(const Item::ItemRarities rarityValue);

/*----------------------------------------------------------------------------------------------------------------*/
// ITEM CLASS METHODS
/*----------------------------------------------------------------------------------------------------------------*/

// GETTER(s)
const string& Item::getName() const { return name; }
const string& Item::getDescription() const { return description; }
const double& Item::getWeight() const { return weightKg; }
const double& Item::getGoldValue() const { return goldValue; }
const Item::ItemRarities& Item::getItemRarity() const { return itemRarity; }
const Item::ItemTypes& Item::getItemType() const { return itemType; }

// SETTER(s)
void Item::setName(string newName) { name = newName; }
void Item::setWeight(double newWeight) { weightKg = newWeight; }
void Item::setGoldValue(double newGoldValue) { goldValue = newGoldValue; }

// OVERRIDE(s)
// Display logic (accessed through operator<<)
void Item::display(ostream& os) const {
    os << setw(15) << left << toString(itemType)
       << setw(25) << left << name 
       // << setw(50) << left << "\"" + description + "\""
       << setw(10) << left << toString(itemRarity) 
       << setw(8) << left << weightKg 
       << setw(12) << left << goldValue;
}

// CUSTOM METHOD(s)
void Item::inspect() const {
    // Placeholder
    std::cout << "Inspecting...\n";
    std::cout << name << ": \"" + description + "\"\n";
}

// CONSTRUCTOR
Item::Item(string name, double weightKg, ItemRarities itemRarity, ItemTypes itemType)
: name{name}, weightKg{weightKg}, goldValue{0}, itemRarity{itemRarity}, itemType{itemType} {
    auto Descriptions = ItemsInitializer::getDescriptions();
    if (Descriptions.find(name) != Descriptions.end()){
        description = Descriptions.at(name);
    }
    else description = "No descriptions - This is a test item!";
}

/*----------------------------------------------------------------------------------------------------------------*/
// HELPERS
/*----------------------------------------------------------------------------------------------------------------*/

// Map(s) to associate flag to a string output
static const map<Item::ItemTypes, string> itemTypeAsString {
    {Item::ItemTypes::MISCELLANEOUS, "MISCELLANEOUS"},
    {Item::ItemTypes::POTION, "POTION"},
    {Item::ItemTypes::WEAPON, "WEAPON"},
    {Item::ItemTypes::ARMOR, "ARMOR"},
    {Item::ItemTypes::CURRENCY, "CURRENCY"},
};

static const map<Item::ItemRarities, string> itemRarityAsString {
    {Item::ItemRarities::COMMON, "Common"},
    {Item::ItemRarities::UNCOMMON, "Uncommon"},
    {Item::ItemRarities::RARE, "Rare"},
    {Item::ItemRarities::EPIC, "Epic"},
    {Item::ItemRarities::LEGENDARY, "Legendary"},
    {Item::ItemRarities::UNIQUE, "Unique"}
};

// Overloaded toString() function to get string associated to a flag
static string toString(const Item::ItemTypes itemTypeValue) {
    auto it = itemTypeAsString.find(itemTypeValue);
    if (it != itemTypeAsString.end()){
        return it->second;
    } else return "Invalid!";
}

static string toString(const Item::ItemRarities rarityValue) {
    auto it = itemRarityAsString.find(rarityValue);
    if (it != itemRarityAsString.end()){
    return it->second;
    } else return "ERROR";
}
