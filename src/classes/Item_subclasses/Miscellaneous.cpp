#include "Miscellaneous.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using std::ostream;
using std::setw;
using std::left;
using std::map;

/*----------------------------------------------------------------------------------------------------------------*/
// HELPERS PROTOTYPE
/*----------------------------------------------------------------------------------------------------------------*/

// toString() function to get string associated to a flag
static const string toString(Miscellaneous::MiscellaneousCategories miscellaneousCategoryValue);

/*----------------------------------------------------------------------------------------------------------------*/
// MISCELLANEOUS CLASS METHODS
/*----------------------------------------------------------------------------------------------------------------*/

// GETTER(s)
const Miscellaneous::MiscellaneousCategories& Miscellaneous::getMiscellaneousCategory() const { return miscellaneousCategory; }

// SETTER(s)
void Miscellaneous::setMiscellaneousCategory(Miscellaneous::MiscellaneousCategories newMiscellaneousCategory) { miscellaneousCategory = newMiscellaneousCategory; }

// OVERRIDE(s)
// Display logic (accessed through operator<<)
void Miscellaneous::display(ostream& os) const {
    Item::display(os);
    os << setw(15) << left << toString(miscellaneousCategory);
       //<< "\n\"" + description + "\"\n";
}

// CUSTOM METHOD(s)
void Miscellaneous::use() {
    // Placeholder
    std::cout << "Using " << name << "\n";
};

// CONSTRUCTOR
Miscellaneous::Miscellaneous(string name, double weightKg, ItemRarities itemRarity, MiscellaneousCategories miscellaneousCategory) 
: Item(name, weightKg, itemRarity, ItemTypes::MISCELLANEOUS), miscellaneousCategory{miscellaneousCategory} {
    // Calculate goldValue of Miscellaneous based on its weightKg and rarity
    switch (this->itemRarity) {
        case ItemRarities::COMMON : goldValue = (this->weightKg * 5) * COMMON_MULTIPLIER; break;
        case ItemRarities::UNCOMMON : goldValue = (this->weightKg * 5) * UNCOMMON_MULTIPLIER; break;
        case ItemRarities::RARE : goldValue = (this->weightKg * 5) * RARE_MULTIPLIER; break;
        case ItemRarities::EPIC : goldValue = (this->weightKg * 5) * EPIC_MULTIPLIER; break;
        case ItemRarities::LEGENDARY : goldValue = (this->weightKg * 5) * LEGENDARY_MULTIPLIER; break;
        case ItemRarities::UNIQUE : goldValue = (this->weightKg * 5) * UNIQUE_MULTIPLIER; break;
    }
}

/*----------------------------------------------------------------------------------------------------------------*/
// HELPERS
/*----------------------------------------------------------------------------------------------------------------*/

// Map(s) to associate flag to a string output
const map<Miscellaneous::MiscellaneousCategories, string> MiscellaneousCategoryAsString {
    {Miscellaneous::MiscellaneousCategories::TOOL, "Tool"},
    {Miscellaneous::MiscellaneousCategories::MAGICAL, "Magical"},
    {Miscellaneous::MiscellaneousCategories::FOOD, "Food"}
};

// toString() function to get string associated to a flag
static const string toString(Miscellaneous::MiscellaneousCategories miscellaneousCategoryValue) {
    auto it = MiscellaneousCategoryAsString.find(miscellaneousCategoryValue);
    if (it != MiscellaneousCategoryAsString.end()){
        return it->second;
    } else return "ERROR";
}