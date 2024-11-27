Stephanie B. Morin

Christine N. Samar

Title: The Wizard’s Spellbook Heap Adventure

Theme: Organize magical spells in a wizard's spellbook using heaps, prioritizing their power levels for various tasks!

Tasks:
1. Insert Spells into the Spellbook: Collect spell names and their corresponding power levels to create the foundation of the spellbook.

2. Create a Powerful Spellbook (Max-Heap):
Build a Max-Heap to prioritize the strongest spells at the top, perfect for battle-ready wizards.

3. Prepare a Beginner’s Spellbook (Min-Heap):
Convert the Max-Heap into a Min-Heap to reorder spells by their weakest powers, ideal for novice spellcasters.

4. Heapify the Spellbook:
Take a random, unordered list of spells and use heapification magic to reorganize it into a well-structured Max-Heap.

Learning Goals:
Through these tasks, wizards will gain insight into:
* How heaps work as binary tree structures.
* Efficient methods to prioritize data using Max and Min-Heaps.
* Transforming and restoring data using heap operations.
This magical heap adventure ensures Harry Potter (and you) can organize spells for any situation, whether facing Voldemort or training novice wizards!

Instructions:
Input:
The user will list spells with their names and power levels (e.g., Incendio: 30, Lumos: 10, Expecto Patronum: 50).

Output:
Heap at each transformation step (e.g., Max-Heap → Min-Heap → Heapified Spellbook).

A sorted view of the spells for clarity.


Sample Input/Output:

Welcome to the Wizard's Spellbook Heap Adventure!

How many spells do you want to add to your spellbook? 5

Enter the names and power levels of the spells:

Enter the name of spell #1: expelliarmus

Enter the power level of expelliarmus: 90

Enter the name of spell #2: lumos

Enter the power level of lumos: 60

Enter the name of spell #3: obliviate

Enter the power level of obliviate: 35

Enter the name of spell #4: alohomora

Enter the power level of alohomora: 99

Enter the name of spell #5: crucio

Enter the power level of crucio: 15




Your Spellbook:

Spellbook (Array Representation):

Spell: expelliarmus, Power: 90 (Index 0)

Spell: lumos, Power: 60 (Index 1)

Spell: obliviate, Power: 35 (Index 2)

Spell: alohomora, Power: 99 (Index 3)

Spell: crucio, Power: 15 (Index 4)




Building Max-Heap (strongest spells will rise to the top):

Swapping lumos and alohomora (Power: 60 and 99)

Swapping expelliarmus and alohomora (Power: 90 and 99)

Spellbook (Array Representation):

Spell: alohomora, Power: 99 (Index 0)

Spell: expelliarmus, Power: 90 (Index 1)

Spell: obliviate, Power: 35 (Index 2)

Spell: lumos, Power: 60 (Index 3)

Spell: crucio, Power: 15 (Index 4)



Spellbook (Sorted Representation):

Spell: alohomora, Power: 99

Spell: expelliarmus, Power: 90

Spell: lumos, Power: 60

Spell: obliviate, Power: 35

Spell: crucio, Power: 15



Converting to Min-Heap (weakest spells will rise to the top):

Swapping lumos and crucio (Power: 60 and 15)

Swapping expelliarmus and crucio (Power: 90 and 15)

Swapping expelliarmus and lumos (Power: 90 and 60)


Spellbook (Array Representation):

Spell: crucio, Power: 15 (Index 0)

Spell: lumos, Power: 60 (Index 1)

Spell: obliviate, Power: 35 (Index 2)

Spell: alohomora, Power: 99 (Index 3)

Spell: expelliarmus, Power: 90 (Index 4)



Spellbook (Sorted Representation):

Spell: crucio, Power: 15

Spell: obliviate, Power: 35

Spell: lumos, Power: 60

Spell: expelliarmus, Power: 90

Spell: alohomora, Power: 99




Heapifying the original list of spells again (Max-Heap):

Swapping lumos and alohomora (Power: 60 and 99)

Swapping expelliarmus and alohomora (Power: 90 and 99)


Spellbook (Array Representation):

Spell: alohomora, Power: 99 (Index 0)

Spell: expelliarmus, Power: 90 (Index 1)

Spell: obliviate, Power: 35 (Index 2)

Spell: lumos, Power: 60 (Index 3)

Spell: crucio, Power: 15 (Index 4)



Thank you for using the Wizard's Spellbook Heap Adventure!
