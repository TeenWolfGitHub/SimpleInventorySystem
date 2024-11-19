#pragma once

#include <string>
#include <map>
#include <memory>

using std::string;
using std::map;
using std::shared_ptr;

class Item;

// Wrapper class for Static initializations - Cannot be instantiated
class ItemsInitializer {
public:
    // Enumeration of items indexes
    enum class ItemsIndex {
        _START_,
        // Miscellaneous - Tools
        WOODEN_HAMMER, IRON_TONGS, LEATHER_POUCH, CARPENTER_SAW,
        BLACKSMITH_HAMMER, HUNTER_TRAP, FISHING_ROD, COOKING_POT, HEALER_KIT,
        // Miscellaneous - Magical Items
        ENCHANTED_STONE, ALCHEMIST_KIT, MYSTIC_TALISMAN, ANCIENT_SCROLL,
        WIZARD_CLOAK, MAGE_ORB, SHIMMERING_CRYSTAL, TELEPORTATION_RUNE, CURSED_RING,
        // Miscellaneous - Food
        DRIED_MEAT, HEALING_HERBS, APPLE, HONEY_JAR,
        BREAD_LOAF, CHEESE_WHEEL, HERB_SOUP, SPICED_WINE, DRAGONFRUIT,
        
        // Weapons - Swords
        IRON_SWORD, STEEL_SHORT_SWORD, BRONZE_LONG_SWORD, KNIGHT_BLADE, ASSASSIN_DAGGER,
        RUNE_SWORD, SILVER_RAPIER, SHADOW_FANG, BLOODTHIRST_BLADE, CELESTIAL_SABER,
        FROSTBITE_BLADE, FLAME_TONGUE, STARFIRE_SHORT_SWORD, BLADE_OF_THE_WINDS, ECLIPSE_SWORD,
        
        // Weapons - Greatswords
        IRON_GREATSWORD, SILVER_GREATSWORD, DRAGON_SLAYER, DARKSTEEL_CLAYMORE, ANCIENT_BLADE,
        TITAN_SWORD, BERSERKER_CLAYMORE, SUNFORGED_GREATSWORD, DOOMBRINGER, OBSIDIAN_GREATBLADE,
        CRUSADER_GREATSWORD, WARLORD_BLADE, THUNDERCLAP_GREATSWORD, LIGHTBRINGER_BLADE, ABYSSAL_CLEAVER,
        // Weapons - Axes
        IRON_AXE, STEEL_BATTLEAXE, BRONZE_HANDAXE, BATTLE_AXE_OF_THE_KING, ELVEN_WARAXE,
        FROST_AXE, RUNE_AXE, MYSTIC_AXE, THUNDERSTRIKE_AXE, DARKWOOD_AXE,
        BLOODAXE, FIREAXE, CELESTIAL_BATTLEAXE, VAMPIRIC_AXE, STORMAXE,
        // Weapon - Greataxes
        IRON_GREATAXE, STEEL_GREATAXE, TITAN_GREATAXE, DRAGONBONE_GREATAXE, DEMONIC_GREATAXE,
        SUNFORGED_GREATAXE, CRYSTAL_GREATAXE, WARLORD_GREATAXE, OBSIDIAN_GREATAXE, FROSTGREATAXE,
        BERSERKER_GREATAXE, STORMGREATAXE, CELESTIAL_GREATAXE, BLOODTHIRST_GREATAXE, ECLIPSE_GREATAXE,
        // Weapons - Polearms
        IRON_LANCE, STEEL_SPEAR, PIKE, HALBERD, DRAGONBONE_TRIDENT,
        GLAIVE, LONG_POLEAXE, PHANTOM_SPEAR, VANGUARD_LANCE, WAR_PIKE,
        SPEAR_OF_DESTINY, FROST_HALBERD, FIERY_GLAIVE, TWILIGHT_TRIDENT, HOLY_SPEAR,
        // Weapons - Maces
        IRON_MACE, FLANGED_MACE, SPIKED_MORNINGSTAR, HOLY_FLAIL, DOOM_HAMMER,
        WAR_CLUB, DEMONSMASHER, STONE_CRUSHER, BATTLE_MAUL, SKULL_BREAKER,
        SACRED_MACE, DEATH_BRINGER, NIGHTMARE_MACE, LIGHTNING_MAUL, BLOOD_SPIKE,
        // Weapons - Warhammers
        IRON_WARHAMMER, FLANGED_WARHAMMER, GREAT_WARHAMMER, DOOM_WARHAMMER, MOUNTAIN_CRUSHER,
        SKULL_SMASHER, DEMONBREAKER, STONE_BREAKER, BATTLE_WARHAMMER, THUNDERSTRIKE,
        HOLY_WARHAMMER, FROST_WARHAMMER, LIGHTNING_WARHAMMER, EARTHSHAKER, BLOODHAMMER,
        // Weapons - Bows
        SIMPLE_BOW, LONG_BOW, ELVEN_SHORTBOW, RECURVE_BOW, HUNTER_BOW,
        COMPOSITE_BOW, DARKWOOD_BOW, DRAGONBONE_BOW, EAGLE_EYE, SHADOW_BOW,
        FIREWOOD_BOW, LIGHTBANE_BOW, SPIRITBOW, BLOODED_BOW, MOONLIGHT_BOW,
        // Weapons - Crossbows
        WOODEN_CROSSBOW, STEEL_CROSSBOW, SNIPER_CROSSBOW, REPEATING_CROSSBOW, DRAGONBONE_CROSSBOW,
        HEAVY_CROSSBOW, ASSAULT_CROSSBOW, IRONBOLT_CROSSBOW, OBSIDIAN_CROSSBOW, SIEGE_CROSSBOW,
        QUICKFIRE_CROSSBOW, LONGBOLT_CROSSBOW, ARCANE_CROSSBOW, VENOM_CROSSBOW, FROSTSHOT_CROSSBOW,
        // Weapons - Staves
        WOODEN_STAFF, ENCHANTED_STAFF, ELDER_WAND, FIRE_STAFF, ICE_STAFF,
        THUNDER_STAFF, NATURE_STAFF, BLOOD_STAFF, ARCANE_STAFF, SHADOW_STAFF,
        STAFF_OF_LIGHT, EARTHEN_STAFF, FROSTFIRE_STAFF, STARWOOD_STAFF, HOLY_WAND,
        // Weapons - Orbs
        CRYSTAL_ORB, DARK_ORB, SUNSTONE_ORB, MOONSTONE_ORB, STAR_ORB,
        ELEMENTAL_ORB, SORCERER_ORB, CELESTIAL_ORB, PHANTOM_ORB, BLOOD_ORB,
        ORB_OF_WISDOM, OBSIDIAN_ORB, ETHEREAL_ORB, ORB_OF_DOOM, DIVINE_ORB,
        
        _END_
    };

    // Static methods to initialize static containers
    static const map<ItemsIndex, shared_ptr<Item>> getItems();
    static const map<string, string> getDescriptions();
};