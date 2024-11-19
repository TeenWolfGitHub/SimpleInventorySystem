cmake_minimum_required(VERSION 3.5.0)
project(SimpleInventorySystem VERSION 0.1.0 LANGUAGES C CXX)

# Specify the source files
set(SOURCE_FILES
    main.cpp
    src/classes/I_Displayable.cpp
    src/classes/ItemsInitializer.cpp
    src/classes/Inventory.cpp
    src/classes/Item.cpp
    src/classes/Item_subclasses/Weapon.cpp
    src/classes/Item_subclasses/Miscellaneous.cpp
)

# Create the executable from the source files
add_executable(SimpleInventorySystem ${SOURCE_FILES})

# Include directories (use target_include_directories more efficiently)
target_include_directories(SimpleInventorySystem PRIVATE 
    src
    src/classes
    src/classes/Item_subclasses
    src/classes/Helper_classes
)

# Ensure the compiler uses C++20 standard
target_compile_features(SimpleInventorySystem PUBLIC cxx_std_20)

# Optional: Set C++ standard for all target types
set_target_properties(SimpleInventorySystem PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)


