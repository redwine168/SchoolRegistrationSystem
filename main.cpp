// Jonathan Redwine
// CS 231
// Homework 4
// Copyright 2018

// #include "pch.h"
#include <iostream>
#include <string>
using namespace std;


// Course class
class Course {
public:
    Course();
    Course(int newCode, string newTitle);
    ~Course();
    int getCode();
    string getTitle();
    void putCode(int newCode);
    void putTitle(string newTitle);
private:
    int code;
    string title;
};


// Student Class
class Student {
public:
    Student();
    Student(int newID, string newName);
    ~Student();
    void addCourse(Course* coursePtr);
    void displayCourses();
    int getID();
    string getName();
    void putID(int newID);
    void putName(string newName);
private:
    int ID;
    string name;
    Course* courses[5];
};


// Default constructor for Course class
Course::Course() {
    code = 0;
    title = "";
}

// Overload constructor for Course class
Course::Course(int newCode, string newTitle) {
    code = newCode;
    title = newTitle;
}

// Deconstructor for Course class
Course::~Course() {
    // nothing here because we don't allocate any memory in the Course class
}


// Get and put methods for Course class
int Course::getCode() {
    return code;
}
string Course::getTitle() {
    return title;
}
void Course::putCode(int newCode) {
    code = newCode;
}
void Course::putTitle(string newTitle) {
    title = newTitle;
}


// Default constructor for Student class
Student::Student() {
    ID = 0;
    name = "";
    for (int i = 0; i < 5; i++) {
        courses[i] = NULL;
    }
}

// Overload constructor for Student class
Student::Student(int newID, string newName) {
    ID = newID;
    name = newName;
    for (int i = 0; i < 5; i++) {
        courses[i] = NULL;
    }
}

// Deconstructor for Student class
Student::~Student() {
    for (int i = 0; i < 5; i++) {
        delete courses[i];
    }
}

// Add course method
void Student::addCourse(Course* coursePtr) {
    int j = 0;
    for (int i = 4; i >= 0; i--) {
        if (courses[i] == NULL) {
            j = i; // find the lowest index where there is a default constructed course
        }
    }
    courses[j] = coursePtr;  // put the new course in the appropriate location in courses array
}

// Display courses method
void Student::displayCourses() {
    for (int i = 0; i < 5; i++) {
        if (courses[i] != NULL) {
            cout << courses[i]->getCode() << " - " << courses[i]->getTitle() << endl;
        }
    }
}

// Get and put methods for Student class
int Student::getID() {
    return ID;
}
string Student::getName() {
    return name;
}
void Student::putID(int newID) {
    ID = newID;
}
void Student::putName(string newName) {
    name = newName;
}



int main() {
    // Create array of school courses (each entry in the array is a pointer to a Course object)
    Course* schoolCourses[6];
    Course* first;
    first = new Course(101, "English Literature from Chaucer to JD Salinger");
    Course* second;
    second = new Course(113, "European Literature: Dante and Cervantes");
    Course* third;
    third = new Course(135, "Physics from Aristotle to Einstein and Heisenburg");
    Course* fourth;
    fourth = new Course(173, "Mathematics of Pythagoras, Euclid and Averroes");
    Course* fifth;
    fifth = new Course(211, "Computer Programming according to G. Booch");
    Course* sixth;
    sixth = new Course(231, "Computer Programming using C++");
    schoolCourses[0] = first;
    schoolCourses[1] = second;
    schoolCourses[2] = third;
    schoolCourses[3] = fourth;
    schoolCourses[4] = fifth;
    schoolCourses[5] = sixth;
    // Create array of school students (each entry in the array is a Student object)
    Student schoolStudents[20];
    for (int i = 0; i < 20; i++) {
        schoolStudents[i] = Student();
    }
    
    cout << "Welcome to the ABC College Registration System!" << endl;
    while (!cin.eof() && cin.good()) {
        cout << "Please enter one of the following options (1, 2, 3, 4, or 5), or enter EOF to exit." << endl;
        cout << "1 - Add a student." << endl;
        cout << "2 - Add a course assignment to a student." << endl;
        cout << "3 - Display the list of available courses." << endl;
        cout << "4 - Display the list of all students." << endl;
        cout << "5 - Display the course enrollment of a specific student." << endl;
        int sel;
        cin >> sel;
        if (!cin.eof() && cin.good()) {
            switch (sel) {
                case 1: { // if the user selects to add a new student
                    int ID;
                    cout << "Please enter the student's 9 digit ID. " << endl;
                    cin >> ID;
                    string name;
                    cout << "Now enter the student's name." << endl;
                    cin >> name;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!cin.eof() && cin.good()) {
                        Student newStudent = Student(ID, name); // create the new student object
                        int i = 19;
                        int j = 20;
                        while (i >= 0) { // here the program finds the location in schoolStudents for the new student (lowest index with a default constructed Student object)
                            if (schoolStudents[i].getID() == 0) {
                                j = i;
                            }
                            i--;
                        }
                        if (j == 20) { // if the array is already full of students, j will stay at 20
                            cout << "No more students may be added.  School full." << endl;
                        }
                        else { // otherwise, add the new student
                            schoolStudents[j] = newStudent;
                        }
                    }
                    break;
                }
                case 2: { // if user selects to add a course to a student
                    int ID;
                    cout << "Please enter the student's 9 digit ID." << endl;
                    cin >> ID;
                    if (!cin.eof() && cin.good()) {
                        int i = 0;
                        while ((schoolStudents[i].getID() != ID) && (i < 20)) {
                            i++; // search for the correct student
                        }
                        if (i >= 20) { // if the provided ID is not a student in the array
                            cout << "Student not found." << endl;
                        }
                        else {
                            int courseCode;
                            cout << "Please enter the course code (Either 101, 113, 135, 173. 211. or 231)." << endl;
                            cin >> courseCode;
                            if (!cin.eof() && cin.good()) {
                                switch (courseCode) { // if the student is found, the user provides the code of the course to add
                                    case 101:
                                        schoolStudents[i].addCourse(schoolCourses[0]);
                                        break;
                                    case 113:
                                        schoolStudents[i].addCourse(schoolCourses[1]);
                                        break;
                                    case 135:
                                        schoolStudents[i].addCourse(schoolCourses[2]);
                                        break;
                                    case 173:
                                        schoolStudents[i].addCourse(schoolCourses[3]);
                                        break;
                                    case 211:
                                        schoolStudents[i].addCourse(schoolCourses[4]);
                                        break;
                                    case 231:
                                        schoolStudents[i].addCourse(schoolCourses[5]);
                                        break;
                                    default:
                                        cout << "Invalid course code entered." << endl;
                                        break;
                                }
                            }
                        }
                    }
                    break;
                }
                case 3: { // if the user selects to display the list of available courses
                    for (int i = 0; i < 6; i++) {
                        cout << schoolCourses[i]->getCode() << " - " << schoolCourses[i]->getTitle() << endl;
                    }
                    cout << endl;
                    break;
                }
                case 4: { // if the user selects to display the list of students (only displays the students that were not default constructed)
                    for (int i = 0; i < 20; i++) {
                        if (schoolStudents[i].getID() != 0) {
                            cout << schoolStudents[i].getID() << " - " << schoolStudents[i].getName() << endl;
                        }
                    }
                    cout << endl;
                    break;
                }
                case 5: { // if the user selects to display a specific student's courses
                    int studentID;
                    cout << "Please enter the student's 9 digit ID." << endl;
                    cin >> studentID;
                    if (!cin.eof() && cin.good()) {
                        int i = 0;
                        while (i < 20) { // iterate through the student array and display the courses for the student whose ID matches the one provided
                            if (studentID == schoolStudents[i].getID()) {
                                schoolStudents[i].displayCourses();
                            }
                            i++;
                        }
                        break;
                    }
                }
                default: {
                    cout << "Invalid selection entered." << endl;
                    break;
                }
            }
        }
        else if (!cin.good()) {
            cout << "Invalid input entered." << endl;
        }
        else if (cin.eof()) {
            cout << "Thank you for using the program." << endl;
        }
    }
    cout << endl << "Terminating program..." << endl;
}
