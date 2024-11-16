#include <iostream>
#include <string>
using namespace std;

int main() {

    const int AGE_LIMIT = 30;  // Maximum age allowed
    const int MIN_AGE = 5;     // Minimum age allowed

    string name[5];  // Store up to 5 student names
    int age[5];      // Store up to 5 student ages
    int grade[5];    // Store up to 5 student grades
    int studentCount = 0;  // Count of how many students have been added
    int choice;

    do {
        // Display the menu
        cout << "\nStudent Information System:\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Exit\n\n";
        cout << "Choose an option (1-4): ";
        cin >> choice;

        if (choice == 1) {
            if (studentCount >= 5) {
                cout << "Student limit reached. Cannot add more students.\n";
            } else {
                cout << "Enter student name: ";
                cin >> name[studentCount];  // Store name in the array

                // Validate age input
                cout << "Enter student age: ";
                cin >> age[studentCount];
                while (age[studentCount] < MIN_AGE || age[studentCount] > AGE_LIMIT) {
                    cout << "Invalid age. Enter an age between " << MIN_AGE << " and " << AGE_LIMIT << ": ";
                    cin >> age[studentCount];
                }

                // Validate grade input
                cout << "Enter student grade (0-100): ";
                cin >> grade[studentCount];
                while (grade[studentCount] < 0 || grade[studentCount] > 100) {
                    cout << "Invalid grade. Enter a grade between 0 and 100: ";
                    cin >> grade[studentCount];
                }

                cout << "Student added successfully!\n";
                studentCount++;  // Increment the count of students
            }

        } else if (choice == 2) {
            // View All Students
            if (studentCount == 0) {
                cout << "No students to display.\n";
            } else {
                cout << "All Students:\n";
                for (int i = 0; i < studentCount; i++) {
                    cout << i + 1 << ". Name: " << name[i]
                         << ", Age: " << age[i]
                         << ", Grade: " << grade[i] << "\n";
                }
            }

        } else if (choice == 3) {
            // Calculate Average Grade
            if (studentCount == 0) {
                cout << "No students to calculate an average grade.\n";
            } else {
                int sum = 0;
                for (int i = 0; i < studentCount; i++) {
                    sum += grade[i];  // Sum all grades
                }
                float average = (float)sum / studentCount;
                cout << "Average grade of all students: " << average << "\n";
            }

        } else if (choice == 4) {
            // Exit
            cout << "Thank you for using the Student Information System!!\n";
        } else {
            // Invalid option
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);  // Repeat until the user chooses to exit

    return 0;
}
    