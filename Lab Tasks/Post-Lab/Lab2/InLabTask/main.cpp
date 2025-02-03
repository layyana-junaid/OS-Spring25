#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

int main() {
    Student student1("Layyana");
    Student student2("Laiba");

    Teacher teacher1("Mr. Farooq");
    Teacher teacher2("Ms. Nazia");

    Course course1("Mathematics");
    Course course2("Physics");

    student1.enrollInCourse("Mathematics");
    student2.enrollInCourse("Physics");

    course1.addTeacher("Mr. Farooq");
    course2.addTeacher("Ms. nazia");

    course1.addStudent("Layyana");
    course2.addStudent("Laiba");

    student1.printCourses();
    student2.printCourses();
    
    teacher1.printCourses();
    teacher2.printCourses();
    
    course1.printDetails();
    course2.printDetails();

    return 0;
}
