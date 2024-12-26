/*
Khai báo mảng accounts gồm 100 phần tử. Thông tin tài khoản gồm: tài khoản, mật khẩu. 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char username[50];
    char password[50];
} Account;

Account accounts[100];
int numAccounts = 0;

void login() {
    char username[50];
    char password[50];
    printf("Nhap ten dang nhap: ");
    scanf("%s", username);
    printf("Nhap mat khau: ");
    scanf("%s", password);
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            printf("Dang nhap thanh cong!\n");
            return;
        }
    }
    printf("Sai ten dang nhap hoac mat khau!\n");
}

void registerAccount() {
    char username[50];
    char password[50];
    printf("Nhap ten dang nhap: ");
    scanf("%s", username);
    printf("Nhap mat khau: ");
    scanf("%s", password);
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Ten dang nhap da ton tai!\n");
            return;
        }
    }
    strcpy(accounts[numAccounts].username, username);
    strcpy(accounts[numAccounts].password, password);
    numAccounts++;
    printf("Dang ky thanh cong!\n");
}

int main() {
    int choice;
    do {
        printf("1. Dang nhap\n");
        printf("2. Dang ky\n");
        printf("3. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registerAccount();
                break;
            case 3:
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 3);
    return 0;
}
