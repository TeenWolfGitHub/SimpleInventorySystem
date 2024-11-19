#pragma once

#include "Item.h"

#include <iostream>

using std::ostream;

class Weapon : public Item {
public:
    // Enumeration(s) for tracking Weapon flags
    enum class WeaponCategories { INVALID, SWORD, GREATSWORD, AXE, GREATAXE, POLEARM, MACE, WARHAMMER, WHIP, BOW, CROSSBOW, STAFF, ORB};
    enum class DamageTypes { INVALID, SLASH, PIERCE, IMPACT, MAGIC_DAMAGE};
    enum class AttackStyles { INVALID, MELEE, RANGED, MAGIC};

protected:
    // Weapon class specific attributes
    double weaponDamage;
    WeaponCategories weaponCategory;
    DamageTypes damageType;
    AttackStyles attackStyle;

public:
    // Getter(s)
    const double& getDamage() const;
    const WeaponCategories& getWeaponCategory() const;
    const DamageTypes& getDamageType() const;
    const AttackStyles& getAttackStyle() const;

protected:
    // Setter(s)
    void setDamage(double newDamage);
    void setWeaponCategory(WeaponCategories newWeaponCategory);
    void setDamageType(DamageTypes newDamageType);
    void setAttackStyle(AttackStyles newAttackStyle);

    // Override(s)
    /*from I_Displayable through Item*/ 
    void display(ostream& os) const override;   // Display logic

    // Custom method(s)
    void equip() const;          // Equip interaction logic
    void attack();               // Attack interaction logic
public:
    // Constructor with default values
    Weapon(string name = "Dummy Weapon", double weightKg = 0.0, Item::ItemRarities rarity = ItemRarities::INVALID, double damage = 0.0,
           WeaponCategories weaponCategory = WeaponCategories::INVALID, DamageTypes damageType = DamageTypes::INVALID, AttackStyles attackStyle = AttackStyles::INVALID);

};