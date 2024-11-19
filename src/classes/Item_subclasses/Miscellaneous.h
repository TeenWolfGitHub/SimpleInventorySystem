#pragma once

#include "Item.h"

#include <iostream>

using std::ostream;

class Miscellaneous : public Item {
public:
    // Enumeration(s) to track Miscellaneous flags
    enum class MiscellaneousCategories { INVALID, TOOL, MAGICAL, FOOD };
protected:
    // Miscellaneous class specific attributes
    MiscellaneousCategories miscellaneousCategory;
public:
    // Getter(s)
    const MiscellaneousCategories& getMiscellaneousCategory() const;
protected:
    // Setter(s)
    void setMiscellaneousCategory(MiscellaneousCategories newMiscellaneousCategory);

    // Override(s)
    /* From I_Displayable through Item */
    void display(ostream& os) const override;    // Display logic

public:
    // Custom method(s)
    void use();         // Use interaction logic

    // Constructor with default values
    Miscellaneous(string name = "Dummy Miscellaneous", double weightKg = 0.0, ItemRarities itemRarity = ItemRarities::COMMON,
                  MiscellaneousCategories miscellaneousCategory = MiscellaneousCategories::INVALID);
};