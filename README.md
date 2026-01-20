# C++ Learning & Projects Collection

This repository contains a deeply analyzed and organized collection of C++ source codes covering fundamental to advanced programming concepts, Object-Oriented Programming (OOP), and practical applications.

## 📂 Project Structure

### [01. OOP Fundamentals](./01_OOP_Fundamentals/)
Core concepts of Object-Oriented Programming.
- **AbstractionAndEncapsulation.cpp**: Demonstrates data hiding and simplified interfaces using Student and Professor classes.
- **ConstructorTypesDemo.cpp**: Shows Default, Parameterized, and Copy constructors in action.
- **DeepCopyConstructor.cpp**: Illustrates proper memory management when copying objects with pointers.
- **ShallowCopyConstructor.cpp**: Explains the risks of default pointer copying.
- **FriendFunctionBasic.cpp**: Introduction to accessing private members using `friend`.
- **FriendFunctionMultiClass.cpp**: Advanced usage of friend functions across multiple classes (Student, Professor, Teacher).
- **OOP_Relations_Aggregation_Composition.cpp**: Comprehensive guide to class relationships (HAS-A, Association, Aggregation).

### [02. Inheritance](./02_Inheritance/)
Code samples explaining how classes can derive from one another.
- **SimpleInheritanceDemo.cpp**: Basic Base -> Derived relationship.
- **MultilevelInheritanceDemo.cpp**: Inheritance through multiple levels (Grandparent -> Parent -> Child).
- **MultipleInheritanceDemo.cpp**: A class deriving from more than one base class.
- **HybridInheritanceDemo.cpp**: A mix of multiple and multilevel inheritance.
- **InheritanceHierarchies.cpp**: Advanced examples of complex class structures.

### [03. Polymorphism](./03_Polymorphism/)
Demonstrations of static and dynamic polymorphism.
- **FunctionOverloadingDemo.cpp**: Methods with same name but different parameters (Compile-time).
- **FunctionOverridingDemo.cpp**: Redefining base class methods in derived classes (Runtime).
- **AbstractClassInterfaceDemo.cpp**: Using Pure Virtual functions to create blueprints for other classes.
- **PolymorphismShapes.cpp**: Real-world application of polymorphism calculating areas for different shapes.
- **PolymorphismAnimals.cpp**: Classic animal sound example using virtual functions.
- **PolymorphismInternSystem.cpp**: Complex system combining inheritance and polymorphic behavior.

### [04. Diamond Problem](./04_Diamond_Problem/)
In-depth analysis of the "Deadly Diamond of Death" in multiple inheritance and its solutions.
- **DiamondAmbiguityProblem.cpp**: Demonstrates the error when a class inherits from two classes sharing a common ancestor.
- **DiamondProblemVirtualInheritance.cpp**: Solving the ambiguity using the `virtual` keyword.
- **DiamondProblemDetailed.cpp**: A detailed breakdown of memory and constructor calls in diamond hierarchies.
- **DiamondProblemAutonomousCar.cpp**: Practical application in a complex vehicle hierarchy.

### [05. Arrays and Pointers](./05_Arrays_and_Pointers/)
Memory management and data structure basics.
- **AddressPointerDemo.cpp**: Understanding memory addresses and basic pointer usage.
- **ReferenceVariableDemo.cpp**: Differences between pointers and references.
- **OneDimensionalArrayPtr.cpp** & **TwoDimensionalArrayPtr.cpp**: Accessing arrays using pointer arithmetic.
- **BubbleSortDynamicArray.cpp**: Implementing sorting on dynamically allocated memory.
- **StudentDynamicArrayPointer.cpp**: Managing an array of objects using pointers.
- **SwapPointersByValue.cpp** & **SwapPointersByAddress.cpp**: Different techniques for swapping data.

### [06. File Handling](./06_File_Handling/)
Working with data persistence.
- **FileHandlingStreamDemo.cpp**: Reading, writing, and appending to text files using `fstream`.

### [07. Systems and Games](./07_Systems_and_Games/)
Full-featured applications built with the concepts above.
- **QuizMasterGame.cpp**: An advanced console-based quiz application with player profiles, leaderboards, and lifelines.
- **StudentManagementSystem.cpp**: A system to manage student records using dynamic memory.
- **VehicleManagementSystem.cpp**: An OOP-heavy system for tracking different types of vehicles.

---
## 🚀 Actions Taken
1. **Cleanup**: Removed all `.exe` files to keep the workspace clean.
2. **Analysis**: Analyzed each file to understand its core purpose and logic.
3. **Renaming**: Renamed files from generic names (like `1 d array.cpp`) to descriptive names (like `OneDimensionalArrayPtr.cpp`).
4. **Organization**: Categorized files into logical folders based on their technical difficulty and topic.
