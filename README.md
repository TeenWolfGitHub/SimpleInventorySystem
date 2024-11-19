# RPG INVENTORY SYSTEM by Rhommel Casabar

## Overview
This is my first project using C++ as a self-taught programmer (still learning the language and its more complex tools and properties).
So, this project is about creating an **Inventory System, specifically with the intent to combine properties of Videogames and DnD own inventory systems**.
My goal is to structure it in a way that makes this system *easy to use and understand, easily implementable in an ongoing game project and expandable*.
The code will probably be unoptimized and full of 'beginner' errors, but this project will serve as a learning experience too.
Feel free to review, make suggestions or yell at me: all in the sake of learning and grow as a programmer. Thank you and enjoy(?).

## The Inventory Class
The `Inventory` class is the main focus of this code.
It is a very simple class, but that is intended to be expanded on with methods growing in complexity.
It has only one attribute: a `vector<unique_ptr<Item>>` where all the items will be stored.
It also provides methods for: adding and removing items from it, sorting and a simple display method to the console (for testing).

## The Item Class
The `Item` class is the root class of a hierarchy of all possible iterations of items we might wanna add.
It provides a simple template from which new item types can expand on.
It has basic attributes all possible items have: a name, weight, description, value, rarity, and item type flag.
It is intended to be used as a class semi-interface as it provides essential virtual functions that its subclasses can override to fit their needs.
The `Item` class has these subclasses: `Miscellaneous`, `Consumable`, `Weapon`, `Armor` (!!To be expanded)

### Miscellaneous Class
The `Miscellaneous` class is an abstract subclass of `Item`.
This item subclass adds a category system with a miscellaneous type flag.
It also provide an overridable `use()` method.

(!! Concrete subclasses to be implemented still !!)

### Consumable Class
The `Consumable` class is an abstract subclass of `Item`.
This item subclass adds a category system with a consumable type flag.
It also provide an overridable `consume()` method.

(!! Concrete subclasses to be implemented still !!)


### Weapon Class
The `Weapon` class is an abstract subclass of `Item`.
This item subclass adds a new appropriate attribute in damage and a category system with flags such as weapon type, damage type and attack type.
It also provide overridables methods: `attack()` and `equip()` .
The `Weapon` class has the following concrete subclasses: `Sword`, `Axe`, `Spear`, `Mace`, `Warhammer`, `ShortBow`, `LongBow`, `Wand`, `Staff`.

(!! Concrete subclasses partially implemented !!)

### Armor Class
The `Armor` class is an abstract subclass of `Item`.
This item subclass adds new appropriate attributes (physical and magical defense) and a category system with an armor type flag.
It also provide an overridable `equip()` method.

(!! Concrete subclasses to be implemented still !!)
