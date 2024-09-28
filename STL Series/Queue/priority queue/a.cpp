#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    // Declare the priority queue
    priority_queue<pair<int, pair<int, int>>> q;

    // Push some elements
    q.push({ 2, {3, 5} });
    q.push({ 1, {4, 6} });
    q.push({ 3, {7, 8} });

    // Example input numbers to search for
    vector<int> searchNumbers = { 8, 6 }; // Example numbers to find

    // Create a temporary vector to hold the elements of the priority queue
    vector<pair<int, pair<int, int>>> temp;

    // Check for each number in the searchNumbers
    for (int number : searchNumbers) {
        bool found = false;

        // Temporary storage for current elements in the queue
        while (!q.empty()) {
            auto currentElement = q.top();
            temp.push_back(currentElement); // Store in temporary vector

            // Check if the number is found in the nested pair
            if (currentElement.second.first == number || currentElement.second.second == number) {
                cout << "Found " << number << " in pair: {"
                    << currentElement.second.first << ", "
                    << currentElement.second.second << "}" << endl;
                found = true;
            }

            // Pop the top element from the priority queue
            q.pop();
        }

        // Restore the priority queue from the temporary vector
        for (const auto& element : temp) {
            q.push(element);
        }

        // If the number was not found, print a message
        if (!found) {
            cout << number << " not found in any pairs." << endl;
        }

        // Clear temporary storage for the next search
        temp.clear();
    }

    return 0;
}
