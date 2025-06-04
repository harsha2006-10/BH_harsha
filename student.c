#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float mathMarks;
    float scienceMarks;
    float englishMarks;
    float totalMarks;
    float percentage;
    float attendance;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }
    Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Math Marks: ");
    scanf("%f", &s.mathMarks);
    printf("Enter Science Marks: ");
    scanf("%f", &s.scienceMarks);
    printf("Enter English Marks: ");
    scanf("%f", &s.englishMarks);
    printf("Enter Attendance (in percentage): ");
    scanf("%f", &s.attendance);

    s.totalMarks = s.mathMarks + s.scienceMarks + s.englishMarks;
    s.percentage = (s.totalMarks / 300) * 100;

    students[studentCount++] = s;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students in the database.\n");
        return;
    }
    printf("\nStudent Database:\n");
    printf("ID\tName\t\tMath\tScience\tEnglish\tTotal\tPercentage\tAttendance\n");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%-10s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f%%\t\t%.2f%%\n", 
               students[i].id, students[i].name, students[i].mathMarks, 
               students[i].scienceMarks, students[i].englishMarks, 
               students[i].totalMarks, students[i].percentage, students[i].attendance);
    }
}

void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Math Marks: %.2f\n", students[i].mathMarks);
            printf("Science Marks: %.2f\n", students[i].scienceMarks);
            printf("English Marks: %.2f\n", students[i].englishMarks);
            printf("Total Marks: %.2f\n", students[i].totalMarks);
            printf("Percentage: %.2f%%\n", students[i].percentage);
            printf("Attendance: %.2f%%\n", students[i].attendance);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Database Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


