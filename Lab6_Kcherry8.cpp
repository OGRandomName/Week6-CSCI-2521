/**
 * @file Lab6_kcherry8.cpp
 * @author Kenneth Cherry
 * @date 2026-10-08
 * @brief Compare static arrays and vectors for processing student scores.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief Calculates statistics using a fixed-size static array.
 * @param None
 * @return None (void)
 */
void arraySolution() {
    const int SIZE = 10;
    int scores[SIZE];
    int input;

    cout << "\n--- Static Array Solution ---\n";

    for (int i = 0; i < SIZE; i++) {
        while (true) {
            cout << "Enter score #" << (i + 1) << " (0–100): ";
            cin >> input;

            if (input >= 0 && input <= 100) {
                scores[i] = input;
                break;
            } else {
                cout << "Invalid score. Try again.\n";
            }
        }
    }

    int sum = 0;
    int highest = scores[0];
    int lowest = scores[0];

    for (int i = 0; i < SIZE; i++) {
        sum += scores[i];
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest) lowest = scores[i];
    }

    float average = static_cast<float>(sum) / SIZE;

    cout << "\nArray Results:\n";
    cout << "Average: " << average << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;
}

/**
 * @brief Calculates statistics using a dynamic vector.
 * @param None
 * @return None (void)
 */
void vectorSolution() {
    vector<int> scores;
    int input;

    cout << "\n--- Vector Solution ---\n";
    cout << "Enter scores (0–100). Enter -1 to finish.\n";

    while (true) {
        cout << "Enter score: ";
        cin >> input;

        if (input == -1) break;

        if (input >= 0 && input <= 100) {
            scores.push_back(input);
        } else {
            cout << "Invalid score. Try again.\n";
        }
    }

    if (scores.empty()) {
        cout << "No scores entered.\n";
        return;
    }

    int sum = 0;
    int highest = scores[0];
    int lowest = scores[0];

    for (int s : scores) {
        sum += s;
        if (s > highest) highest = s;
        if (s < lowest) lowest = s;
    }

    float average = static_cast<float>(sum) / scores.size();

    cout << "\nVector Results:\n";
    cout << "Average: " << average << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;

    sort(scores.begin(), scores.end());

    cout << "Sorted Scores: ";
    for (int s : scores) cout << s << " ";
    cout << endl;
}
/**
 * @brief Entry point of the program.
 * @param None
 * @return 0 to indicate success.
 */
int main() {
    arraySolution();
    vectorSolution();
    return 0;
}
