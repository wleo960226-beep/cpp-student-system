#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}

struct Student {
    string id;
    string name;
    int score;
};

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "\n=== Add Student ===\n";
    cout << "Enter ID: ";
    cin >> newStudent.id;

    for (const auto& s : students) {
        if (s.id == newStudent.id) {
            cout << "Error: Student ID already exists! Registration rejected.\n";
            return;
        }
    }
    
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter Score: ";
    cin >> newStudent.score;
    
    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

void listStudents(const vector<Student>& students) {
    cout << "\n=== Student List ===\n";
    if (students.empty()) {
        cout << "No student data available.\n";
        return;
    }
    cout << left << setw(12) << "ID" << setw(15) << "Name" << setw(6) << "Score" << endl;
    cout << "-----------------------------------\n";
    for (const auto& s : students) {
        cout << left << setw(12) << s.id << setw(15) << s.name << setw(6) << s.score << endl;
    }
}

void sortByScore(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });
    cout << "\nStudents sorted by score (Highest to Lowest)!\n";
    listStudents(students);
}

void searchStudent(const vector<Student>& students) {
    cout << "\n=== Search Student ===\n";
    cout << "Enter Student ID to search: ";
    string searchId;
    cin >> searchId;
    
    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << s.id << "\nName: " << s.name << "\nScore: " << s.score << endl;
            return;
        }
    }
    cout << "Error: Student with ID " << searchId << " not found.\n";
}

void showStatistics(const vector<Student>& students) {
    cout << "\n=== Score Statistics ===\n";
    if (students.empty()) {
        cout << "No data to calculate statistics.\n";
        return;
    }
    
    double sum = 0;
    int maxScore = students[0].score;
    int minScore = students[0].score;
    int passCount = 0;
    int failCount = 0;
    
    for (const auto& s : students) {
        sum += s.score;
        
        maxScore = getMax(maxScore, s.score);
        getMin(minScore, s.score); 
        minScore = (minScore < s.score) ? minScore : s.score; 
        
        if (s.score >= 60) {
            passCount++;
        } else {
            failCount++;
        }
    }
    
    cout << "Class Average : " << fixed << setprecision(2) << (sum / students.size()) << endl;
    cout << "Highest Score : " << maxScore << " (Validated via Template getMax)" << endl;
    cout << "Lowest Score  : " << minScore << endl;
    cout << "Passed Count  : " << passCount << endl;
    cout << "Failed Count  : " << failCount << endl;
}

int main() {
    vector<Student> students;
    int choice;

    students.push_back({"B11001", "Alice", 85});
    students.push_back({"B11002", "Bob", 52});
    students.push_back({"B11003", "Charlie", 95});

    do {
        cout << "\n===============================";
        cout << "\n 1. Add student";
        cout << "\n 2. List all students";
        cout << "\n 3. Sort by score";
        cout << "\n 4. Search by id";
        cout << "\n 5. Show statistics";
        cout << "\n 0. Exit";
        cout << "\n===============================";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addStudent(students); break;
            case 2: listStudents(students); break;
            case 3: sortByScore(students); break;
            case 4: searchStudent(students); break;
            case 5: showStatistics(students); break;
            case 0: cout << "Exiting system. Goodbye!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}
