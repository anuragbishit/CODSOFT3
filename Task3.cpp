// TASK:-3 = Create a program that manages student grades. Allow the use to input student names and their corresponding grades.
// Calculate the average grade and display it along with the highestand lowest grades.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int studentId;
    string fullName;
    float average;
    int totalMarks;
    vector<string> subjectNames;
    string className;
    char grade; 
};

bool compareStudents(const Student& a, const Student& b) {
    return a.average > b.average;
}

char calculateGrade(float average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'E';
    }
}

bool isUniqueId(const vector<Student>& students, int id) {
    for (const auto& student : students) {
        if (student.studentId == id) {
            return false;
        }
    }
    return true;
}

int main() {
    int totalStudentsInClass;

    cout << "Enter the total number of students to find grades/results: ";
    cin >> totalStudentsInClass;

    vector<Student> students;

    for (int studentBox = 0; studentBox < totalStudentsInClass; ++studentBox) {
        Student studentCommons;
        int totalSubjects;
        int sum = 0;

        
        do {
            cout << "Enter the unique ID for student " << studentBox + 1 << ": ";
            cin >> studentCommons.studentId;

            if (!isUniqueId(students, studentCommons.studentId)) {
                cout << "This ID already exists. Please enter a different ID." << endl;
            }
        } while (!isUniqueId(students, studentCommons.studentId));

        cout << "Enter the full name of student " << studentBox + 1 << ": ";
        cin.ignore();
        getline(cin, studentCommons.fullName);

        if (studentBox > 0) {
            cout << "Class for the previous student will be marked here, that is: " << students[studentBox - 1].className << endl;
            cout << "Enter class for " << studentCommons.fullName << ": ";
            cin >> studentCommons.className;
        } else {
            cout << "Class name can only be entered once, so ";
            cout << "Enter class name correctly for " << studentCommons.fullName << ": ";
            cin >> studentCommons.className;
        }
        cout << "Insert the number of total subjects for " << studentCommons.fullName << ": ";
        cin >> totalSubjects;

        vector<string> subjectNames(totalSubjects);
        vector<int> maximumMarks(totalSubjects);
        int marks;

        for (int i = 0; i < totalSubjects; i++) {
            cout << "Enter the name of subject " << i + 1 << ": ";
            cin.ignore();
            getline(cin, subjectNames[i]);

            cout << "Enter the maximum marks of subject " << i + 1 << ": ";
            cin >> maximumMarks[i];

            cout << "Insert the obtained marks of " << subjectNames[i] << " for " << studentCommons.fullName << ": ";
            cin >> marks;

            if (marks > maximumMarks[i]) {
                cout << "Error: Marks cannot exceed the maximum marks. Please re-enter." << endl;
                i--;
                continue;
            }

            studentCommons.subjectNames.push_back(subjectNames[i]);
            sum += marks;
        }

        studentCommons.totalMarks = sum;
        studentCommons.average = static_cast<float>(sum) / totalSubjects;
        cout<<"\n";
        cout << studentCommons.fullName << " Your total marks are: " << studentCommons.totalMarks << endl;
        cout << studentCommons.fullName << " Your average marks are: " << studentCommons.average << endl;

        do {
            cout << "Enter the grade for " << studentCommons.fullName << " according to their above average marks (A/B/C/D/E): ";
            cin >> studentCommons.grade;

            if (!(studentCommons.grade == 'A' || studentCommons.grade == 'B' ||
                  studentCommons.grade == 'C' || studentCommons.grade == 'D' ||
                  studentCommons.grade == 'E')) {
                cout << "Invalid grade entered. Please enter A, B, C, D, or E." << endl;
            }

        } while (!(studentCommons.grade == 'A' || studentCommons.grade == 'B' ||
                   studentCommons.grade == 'C' || studentCommons.grade == 'D' ||
                   studentCommons.grade == 'E'));

        students.push_back(studentCommons);

         cout << studentCommons.fullName << " Your grade is: " << studentCommons.grade << endl;
        cout << studentCommons.fullName << " Your class is: " << studentCommons.className << endl;
        cout << studentCommons.fullName << " Your unique ID is: " << studentCommons.studentId << endl;
        cout << studentCommons.fullName << " It's your Progress Report!" << endl;
    }

    sort(students.begin(), students.end(), compareStudents);

    cout << "\nStudents are arranged according to their average grade marks:\n";
    for (const auto& student : students) {
        cout << student.fullName << " Your average marks are: " << student.average << " and your grade is: " << student.grade << endl;
    }
    cout << "\nHighest Grade : " << students.front().fullName << " with an average of " << students.front().average << " and a grade of " << students.front().grade << endl;
    cout << "\nMediest Grade : " << students[students.size() / 2].fullName << " with an average of " << students[students.size() / 2].average << " and a grade of " << students[students.size() / 2].grade << endl;
    cout << "\nLowest Grade : " << students.back().fullName << " with an average of " << students.back().average << " and a grade of " << students.back().grade << endl;

    return 0;
}
