
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

void printStudent(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
    }
}

void addStudent(Student *students, int *n) {
    printf("Nhap id: ");
    scanf("%d", &students[*n].id);
    printf("Nhap name: ");
    scanf("%s", students[*n].name);
    printf("Nhap age: ");
    scanf("%d", &students[*n].age);
    (*n)++;
}
void fixStudent(Student *students, int n) {
    int id;
    printf("Nhap id: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            printf("Nhap name: ");
            scanf("%s", students[i].name);
            printf("Nhap age: ");
            scanf("%d", &students[i].age);
            return;
        }
    }
    printf("Khong tim thay sinh vien co id %d\n", id);
}
void deleteStudent(Student *students, int *n) {
    int id;
    printf("Nhap id: ");
    scanf("%d", &id);
    for (int i = 0; i < *n; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            return;
        }
    }
    printf("Khong tim thay sinh vien co id %d\n", id);
}
void searchStudent(Student *students, int n) {
    int id;
    printf("Nhap id: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            return;
        }
    }
    printf("Khong tim thay sinh vien co id %d\n", id);
}
void sortStudents(Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].age > students[j].age) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
int main() {
    Student students[100];
    int n = 0;
    readData(students, &n);
    int choice;
    do {
        printf("1. danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep sinh vien theo tuoi\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printStudent(students, n);
                break;
            case 2:
                addStudent(students, &n);
                break;
            case 3:
                fixStudent(students, n);
                break;
            case 4:
                deleteStudent(students, &n);
                break;
            case 5:
                searchStudent(students, n);
                break;
            case 6:
                sortStudents(students, n);
                break;
            case 7:
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 7);
    return 0;
}
