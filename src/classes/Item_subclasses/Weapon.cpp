#include "Weapon.h"

#include "Item.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using std::ostream;
using std::string;
using std::setw;
using std::left;
using std::map;

/*----------------------------------------------------------------------------------------------------------------*/
// HELPERS PROTOTYPES
/*----------------------------------------------------------------------------------------------------------------*/

// Overloaded toString() function to get string associated to a flag
static string toString(Weapon::WeaponCategories weaponCategoryValue);
static string toString(Weapon::DamageTypes damageTypeValue);
static string toString(Weapon::AttackStyles attackStyleValue);

/*----------------------------------------------------------------------------------------------------------------*/
// WEAPON CLASS METHODS
/*----------------------------------------------------------------------------------------------------------------*/

// GETTER(s)
const double& Weapon::getDamage() const { return weaponDamage; }
const Weapon::WeaponCategories& Weapon::getWeaponCategory() const { return weaponCategory; }
const Weapon::DamageTypes& Weapon::getDamageType() const { return damageType; }
const Weapon::AttackStyles& Weapon::getAttackStyle() const {return attackStyle; }

// SETTER(s)
void Weapon::setDamage(double newDamage) { weaponDamage = newDamage; }
void Weapon::setWeaponCategory(Weapon::WeaponCategories newWeaponCategory) { weaponCategory = newWeaponCategory; }
void Weapon::setDamageType(Weapon::DamageTypes newDamageType) { damageType = newDamageType; }
void Weapon::setAttackStyle(Weapon::AttackStyles newAttackStyle) { attackStyle = newAttackStyle; }

// OVERRIDE(s)
// Display logic (accessed through operator<<)
void Weapon::display(ostream& os) const {
    Item::display(os);
    os << setw(15) << left << toString(weaponCategory)
       << setw(30) << left << toString(attackStyle) + " (" + toString(damageType) + ")"
       << setw(10) << left << weaponDamage;
       //<< "\n\"" + description + "\"\n";
}

// CUSTOM METHOD(s)
void Weapon::equip() const {
    // Placeholder
    std::cout << "Equipping " << name << "\n";
}
void Weapon::attack() {
    // Placeholder
    std::cout << "Attacking with " << name << "\n";
}

// CONSTRUCTOR
Weapon::Weapon(string name, double weightKg, Item::ItemRarities rarity, double weaponDamage, WeaponCategories weaponCategory, DamageTypes damageType, AttackStyles attackStyle)
: Item(name, weightKg, rarity, ItemTypes::WEAPON), weaponDamage{weaponDamage}, weaponCategory{weaponCategory}, damageType{damageType}, attackStyle{attackStyle} {
    // Calculate goldValue of Weapon based on its damage and rarity
    switch (this->itemRarity){
        case ItemRarities::COMMON : goldValue = (this->weaponDamage * 5) * COMMON_MULTIPLIER; break;
        case ItemRarities::UNCOMMON : goldValue = (this->weaponDamage * 5) * UNCOMMON_MULTIPLIER; break;
        case ItemRarities::RARE : goldValue = (this->weaponDamage * 5) * RARE_MULTIPLIER; break;
        case ItemRarities::EPIC : goldValue = (this->weaponDamage * 5) * EPIC_MULTIPLIER; break;
        case ItemRarities::LEGENDARY : goldValue = (this->weaponDamage * 5) * LEGENDARY_MULTIPLIER; break;
        case ItemRarities::UNIQUE : goldValue = (this->weaponDamage * 5) * UNIQUE_MULTIPLIER; break;
    }
}

/*----------------------------------------------------------------------------------------------------------------*/
// HELPERS
/*----------------------------------------------------------------------------------------------------------------*/

// Map(s) to associate flag to a string output
static map<Weapon::WeaponCategories, string> WeaponCategoryAsString {
    {Weapon::WeaponCategories::SWORD, "Sword"},
    {Weapon::WeaponCategories::GREATSWORD, "Greatsword"},
    {Weapon::WeaponCategories::AXE, "Axe"},
    {Weapon::WeaponCategories::GREATAXE, "Greataxe"},
    {Weapon::WeaponCategories::POLEARM, "Polearm"},
    {Weapon::WeaponCategories::MACE, "Mace"},
    {Weapon::WeaponCategories::WARHAMMER, "Warhammer"},
    {Weapon::WeaponCategories::WHIP, "Whip"},
    {Weapon::WeaponCategories::BOW, "Bow"},
    {Weapon::WeaponCategories::CROSSBOW, "Crossbow"},
    {Weapon::WeaponCategories::STAFF, "Staff"},
    {Weapon::WeaponCategories::ORB, "Orb"}
};

static map<Weapon::DamageTypes, string> DamageTypeAsString {
    {Weapon::DamageTypes::SLASH, "Slash"},
    {Weapon::DamageTypes::PIERCE, "Pierce"},    
    {Weapon::DamageTypes::IMPACT, "Impact"},    
    {Weapon::DamageTypes::MAGIC_DAMAGE, "Magic Damage"}    
};

static map<Weapon::AttackStyles, string> AttackStyleAsString {
    {Weapon::AttackStyles::MELEE, "Melee"},
    {Weapon::AttackStyles::RANGED, "Ranged"},
    {Weapon::AttackStyles::MAGIC, "Magic"},
};

// Overloaded toString() function to get string associated to a flag
static string toString(Weapon::WeaponCategories weaponCategoryValue) {
    auto it = WeaponCategoryAsString.find(weaponCategoryValue);
    if (it != WeaponCategoryAsString.end()){
        return it->second;        
    } else return "ERROR";
}

static string toString(Weapon::DamageTypes damageTypeValue) {
    auto it = DamageTypeAsString.find(damageTypeValue);
    if (it != DamageTypeAsString.end()){
        return it->second;
    } else return "ERROR";
}

static string toString(Weapon::AttackStyles attackStyleValue) {
auto it = AttackStyleAsString.find(attackStyleValue);
    if (it != AttackStyleAsString.end()){
        return it->second;
    } else return "ERROR";
}
