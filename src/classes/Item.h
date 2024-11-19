#pragma once

#include "I_Displayable.h"

#include <iostream>
#include <string>

using std::ostream;
using std::string;

// IMPORTANT: Item is an abstract class (Constructor is protected)
class Item : public I_Displayable {
public:
    // Enumeration(s) to track Item flags
    enum class ItemRarities { INVALID, COMMON, UNCOMMON, RARE, EPIC, LEGENDARY, UNIQUE };
    enum class ItemTypes { INVALID, MISCELLANEOUS, POTION, WEAPON, ARMOR, CURRENCY };
    
    // Multipliers used in the calculation of Item (and its subclasses) goldValue
    static constexpr double COMMON_MULTIPLIER = 1.0;
    static constexpr double UNCOMMON_MULTIPLIER = 2.0;
    static constexpr double RARE_MULTIPLIER = 5.0;
    static constexpr double EPIC_MULTIPLIER = 8.0;
    static constexpr double LEGENDARY_MULTIPLIER = 15.0;
    static constexpr double UNIQUE_MULTIPLIER = 30.0;

protected:
    // Item class attributes
    string name;
    string description;
    double weightKg;
    double goldValue;
    ItemRarities itemRarity;
    ItemTypes itemType;

public:
    // Getter(s)
    const string& getName() const;
    const string& getDescription() const;
    const double& getWeight() const;
    const double& getGoldValue() const;
    const ItemRarities& getItemRarity() const;
    const ItemTypes& getItemType() const;

protected:
    // Setter(s)
    void setName(string newName);
    void setWeight(double newWeight);
    void setGoldValue(double newGoldValue);

    // Override(s)
    /*From I_Displayable*/ virtual void display(ostream& os) const override;   // Display logic

    void inspect() const;

    //Constructor with default values - protected to make class abstract
    Item(string name = "Dummy", double weightKg = 0, ItemRarities itemRarity = ItemRarities::INVALID, ItemTypes itemType = ItemTypes::INVALID);
};