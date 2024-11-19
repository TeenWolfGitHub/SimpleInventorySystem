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
It features a `vector<unique_ptr<Item>>` where all the items will be stored (support Polymorphism), a `currentWeight` that tracks its total weight and a `weightCapacity` that sets a maximum weight limit to the inventory.
It also provides methods for: adding and removing items from it, sorting and a simple display method to the console (for testing).

## The Item Class
The `Item` class is the root class of a hierarchy of all possible iterations of items we might wanna add.
It provides a simple template from which new item types can expand on.
It has basic attributes all possible items have: a name, weight, description, value, rarity, and item type flag.
The `Item` class has these example subclasses: `Miscellaneous`, `Weapon`
