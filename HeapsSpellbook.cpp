#include <iostream>
#include <vector>       // library for dynamic arrays
#include <algorithm>    //library for sorting
using namespace std;

// Function to display the heap
void displayTree(const vector<pair<string, int>>& tree) {
    cout << "Spellbook (Array Representation):\n";                                      // Header for display
    for (int i = 0; i < tree.size(); ++i) {                                             // Loop through the tree vector
        cout << "Spell: " << tree[i].first << ", Power: " << tree[i].second
             << " (Index " << i << ")\n";                                               // Display spell and power with index
    }
    cout << endl;
}

// Function to display the heap as a sorted array for clarity
void displaySorted(const vector<pair<string, int>>& tree, bool ascending) {
    vector<pair<string, int>> sortedTree = tree;                                        // Copy the tree for sorting
    if (ascending) {                                                                    // If sorting in ascending order
        sort(sortedTree.begin(), sortedTree.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;                                                 // Compare powers for ascending sort
        });
    } else {                                                                            // If sorting in descending order
        sort(sortedTree.begin(), sortedTree.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;                                                 // Compare powers for descending sort
        });
    }
    cout << "Spellbook (Sorted Representation):\n";                                     // Header for sorted display
    for (const auto& spell : sortedTree) {                                              // Loop through sorted tree
        cout << "Spell: " << spell.first << ", Power: " << spell.second << "\n";        // Display each spell
    }
    cout << endl;
}

// Function to heapify the tree at a given index for Max-Heap
void maxHeapify(vector<pair<string, int>>& tree, int index, int size) {
    int leftChild = 2 * index + 1;                                                      // Left child index
    int rightChild = 2 * index + 2;                                                     // Right child index
    int largest = index;                                                                // Start with the current index as the largest

    // If the left child is larger than the current largest, update largest
    if (leftChild < size && tree[leftChild].second > tree[largest].second) {
        largest = leftChild;
    }

    // If the right child is larger than the current largest, update largest
    if (rightChild < size && tree[rightChild].second > tree[largest].second) {
        largest = rightChild;
    }

    // If the largest value is not the parent, swap and continue heapifying
    if (largest != index) {
        cout << "Swapping " << tree[index].first << " and " << tree[largest].first
             << " (Power: " << tree[index].second << " and " << tree[largest].second << ")\n";
        swap(tree[index], tree[largest]);                                               // Swap parent and largest child
        maxHeapify(tree, largest, size);                                                // Recursively heapify the affected subtree
    }
}

// Function to heapify the tree at a given index for Min-Heap
void minHeapify(vector<pair<string, int>>& tree, int index, int size) {
    int leftChild = 2 * index + 1;                                                      // Left child index
    int rightChild = 2 * index + 2;                                                     // Right child index
    int smallest = index;                                                               // Start with the current index as the smallest

    // If the left child is smaller than the current smallest, update smallest
    if (leftChild < size && tree[leftChild].second < tree[smallest].second) {
        smallest = leftChild;
    }

    // If the right child is smaller than the current smallest, update smallest
    if (rightChild < size && tree[rightChild].second < tree[smallest].second) {
        smallest = rightChild;
    }

    // If the smallest value is not the parent, swap and continue heapifying
    if (smallest != index) {
        cout << "Swapping " << tree[index].first << " and " << tree[smallest].first
             << " (Power: " << tree[index].second << " and " << tree[smallest].second << ")\n";
        swap(tree[index], tree[smallest]);                                              // Swap parent and smallest child
        minHeapify(tree, smallest, size);                                               // Recursively heapify the affected subtree
    }
}

// Function to build a Max-Heap from the tree
void buildMaxHeap(vector<pair<string, int>>& tree) {
    for (int i = (tree.size() / 2) - 1; i >= 0; --i) {                                  // Start from last non-leaf node
        maxHeapify(tree, i, tree.size());                                               // Heapify each node down to the root
    }
}

// Function to build a Min-Heap from the tree
void buildMinHeap(vector<pair<string, int>>& tree) {
    for (int i = (tree.size() / 2) - 1; i >= 0; --i) {                                  // Start from last non-leaf node
        minHeapify(tree, i, tree.size());                                               // Heapify each node down to the root
    }
}

int main() {
    vector<pair<string, int>> tree;                                                     // Binary tree stored as an array of pairs (spell name, power)
    vector<pair<string, int>> originalTree;                                             // To store the original user input for re-heapification

    cout << "Welcome to the Wizard's Spellbook Heap Adventure!\n";
    int n;                                                                              // Number of spells
    cout << "How many spells do you want to add to your spellbook? ";
    cin >> n;                                                                           // Take user input for the number of spells

    cout << "Enter the names and power levels of the spells:\n";                        // Prompt for spell data
    for (int i = 0; i < n; ++i) {                                                       // Loop to take input for each spell
        string spell;                                                                   // Spell name
        int power;                                                                      // Spell power
        cout << "Enter the name of spell #" << i + 1 << ": ";
        cin >> spell;                                                                   // Input spell name
        cout << "Enter the power level of " << spell << ": ";
        cin >> power;                                                                   // Input spell power
        tree.push_back({spell, power});                                                 // Add the spell to the tree
    }

    // Save a copy of the original tree
    originalTree = tree;

    cout << "\nYour Spellbook before building the Max-Heap:\n";
    displayTree(tree);                                                                  // Display the initial spellbook

    // Step 1: Build the Max-Heap
    cout << "\nBuilding Max-Heap (strongest spells will rise to the top):\n";
    buildMaxHeap(tree);                                                                 // Build the Max-Heap
    displayTree(tree);                                                                  // Display the Max-Heap
    displaySorted(tree, false);                                                         // Display sorted descending for Max-Heap clarity

    // Step 2: Convert to Min-Heap
    cout << "\nConverting to Min-Heap (weakest spells will rise to the top):\n";
    tree = originalTree;                                                                // Reset to original list
    buildMinHeap(tree);                                                                 // Build the Min-Heap
    displayTree(tree);                                                                  // Display the Min-Heap
    displaySorted(tree, true);                                                          // Display sorted ascending for Min-Heap clarity

    // Step 3: Heapify the original user input list again
    cout << "\nHeapifying the original list of spells again (Max-Heap):\n";
    tree = originalTree;                                                                // Reset to the original list
    buildMaxHeap(tree);                                                                 // Rebuild the Max-Heap
    displayTree(tree);                                                                  // Display the rebuilt Max-Heap

    cout << "Thank you for using the Wizard's Spellbook Heap Adventure!\n";
    return 0;
}
