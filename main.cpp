#include <iostream>
#include <string>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int year;
    string section;
    string course;
};

void displayMenu() {
    system("cls");
    cout << "\t-----------\n";
    cout << "\t   Menu:\n";
    cout << "\t-----------\n";
    cout << "1. Add\n";
    cout << "2. Show\n";
}

void clearInputBuffer() {
    cin.clear();
    while (cin.get() != '\n');
}

void showStudents(Student students[], int studentCount);

int main() {
    const int MAX_STUDENTS = 5;
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        displayMenu();
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (studentCount < MAX_STUDENTS) {
                cout << "Enter first name: ";
                cin.ignore();
                getline(cin, students[studentCount].firstName);

                cout << "Enter Last name: ";
                getline(cin, students[studentCount].lastName);

                cout << "Enter year: ";
                cin >> students[studentCount].year;

                cout << "Enter course: ";
                cin.ignore();
                getline(cin, students[studentCount].course);

                cout << "Enter section: ";
                getline(cin, students[studentCount].section);

                studentCount++;
            }
            else {
                cout << "Maximum number of students reached.\n";
            }
            break;
        }

        case 2: {
            if (studentCount == 0) {
                cout << "No student information to display.\n";
            }
            else {
                showStudents(students, studentCount);
            }
            break;
        }

        default:
            cout << "Invalid! Just choose an option from the menu.\n";
        }

    } while (true);

    return 0;
}

void showStudents(Student students[], int studentCount) {
    const int STUDENTS_PER_PAGE = 5;
    int totalPages = (studentCount - 1) / STUDENTS_PER_PAGE + 1;
    int currentPage = 0;

    char option;
    do {
        system("cls");
        cout << "Page " << currentPage + 1 << " of " << totalPages << "\n";
        for (int i = currentPage * STUDENTS_PER_PAGE; i < min((currentPage + 1) * STUDENTS_PER_PAGE, studentCount); ++i) {
            cout << "\nStudent " << i + 1 << "\n"
                << "First Name: " << students[i].firstName << "\n"
                << "Last Name: " << students[i].lastName << "\n"
                << "Course: " << students[i].course << "\n"
                << "Year: " << students[i].year << "\n";
        }

        cout << "N - Next Page, P - Previous Page, E - Exit to Main Menu\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
        case 'N':
        case 'n':
            if (currentPage < totalPages - 1) {
                currentPage++;
            }
            break;
        case 'P':
        case 'p':
            if (currentPage > 0) {
                currentPage--;
            }
            break;
        }
    } while (option != 'E' && option != 'e');
}

