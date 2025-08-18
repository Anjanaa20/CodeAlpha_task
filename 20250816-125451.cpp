#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of courses: ";
    cin >> n;

    string courseName[50];
    double grade[50], credit[50];
    double totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of course " << i + 1 << ": ";
        cin >> courseName[i];
        cout << "Enter grade points (e.g., A=10, B=9, etc.) for " << courseName[i] << ": ";
        cin >> grade[i];
        cout << "Enter credit hours for " << courseName[i] << ": ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    double cgpa = totalGradePoints / totalCredits;

    // Display result
    cout << "\n---------------------------------\n";
    cout << setw(15) << "Course" << setw(10) << "Grade" << setw(10) << "Credits\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(15) << courseName[i] 
             << setw(10) << grade[i] 
             << setw(10) << credit[i] << endl;
    }
    cout << "---------------------------------\n";
    cout << "Final CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}