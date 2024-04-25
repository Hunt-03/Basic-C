#include <stdio.h>
#include <stdlib.h>
struct Account {
    int acc_no;
    int pin;
    int balance;
};

int main() {
    struct Account accounts[7];
    accounts[0].acc_no = 1234567;
    accounts[0].pin = 1111;
    accounts[0].balance = 1000;
    accounts[1].acc_no = 2345678;
    accounts[1].pin = 2222;
    accounts[1].balance = 1000;
    accounts[2].acc_no = 3456789;
    accounts[2].pin = 3333;
    accounts[2].balance = 1000;
    accounts[3].acc_no = 4567890;
    accounts[3].pin = 4444;
    accounts[3].balance = 1000;
    accounts[4].acc_no = 5678901;
    accounts[4].pin = 5555;
    accounts[4].balance = 1000;
    accounts[5].acc_no = 6789012;
    accounts[5].pin = 6666;
    accounts[5].balance = 1000;
    accounts[6].acc_no = 7890123;
    accounts[6].pin = 7777;
    accounts[6].balance = 1000;

    int acc, p, i, choice, amount, new_pin, feedback, flag = 1;

    do {
        flag = 1;
        printf("\033[1;36m+===============================================================================================+");
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|\033[1;37m\t\t\t\tWELCOME TO THE TERV ATM\t\t\t\t\t\t\033[1;36m|");
        printf("\n|\033[1;37m\t\t\t\t  BANK OF KRCT\t\t\t\t\t\t\033[1;36m\t|");
        printf("\n|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
        printf("+===============================================================================================+\033[1;37m");
        printf("\nEnter your Account Number: ");
        scanf("%d", &acc);
        printf("Enter your PIN: ");
        scanf("%d", &p);

        for (i = 0; i < 7; i++) {
            if (acc == accounts[i].acc_no && p == accounts[i].pin) {
                flag = 0;
                printf("\nLogin Successful!\n");
                do {
                    printf("\033[1;36m+===============================================================================================+\033[1;37m");
                    printf("\n\t\t\t\tMain Menu\n");
                    printf("\033[1;36m+===============================================================================================+\033[1;37m");
                    printf("\n1. CHECK BALANCE\n");
                    printf("2. DEPOSIT\n");
                    printf("3. WITHDRAW\n");
                    printf("4. CHANGE PIN\n");
                    printf("5. EXIT\n");
                    printf("\033[1;36m+===============================================================================================+\033[1;37m");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                    case 1:
                        printf("\n\t\t\033[1;33m<<<Your current balance is ₹%d >>>\n\033[1;37m", accounts[i].balance);
                        break;
                    case 2:
                        printf("\nEnter the amount to deposit: ");
                        scanf("%d", &amount);
                        accounts[i].balance += amount;
                        printf("\n\t\t\033[1;33m<<<₹%d has been deposited into your account>>>", amount);
                        printf("\n\t\t<<<Your current balance is ₹%d >>>\n\033[1;37m", accounts[i].balance);
                        break;
                    case 3:
                        printf("\nEnter the amount to withdraw: ");
                        scanf("%d", &amount);
                        if (amount > accounts[i].balance) {
                            printf("\n\t\t\033[1;33m<<<Insufficient balance>>>");
                            printf("\n\t\t<<<Your current balance is ₹%d>>>\n\033[1;37m", accounts[i].balance);
                        } else {
                            accounts[i].balance -= amount;
                            printf("\n\t\t\033[1;33m<<<₹%d has been withdrawn from your account>>>", amount);
                            printf("\n\t\t<<<Your current balance is ₹%d>>>\n\033[1;37m", accounts[i].balance);
                        }
                        break;
                    case 4:
                        reset:
                        int t;
                        printf("\nEnter your old PIN: ");
                        scanf("%d", &t);
                        if (t == accounts[i].pin) {
                            printf("\nEnter your new PIN: ");
                            scanf("%d", &new_pin);
                            accounts[i].pin = new_pin;
                            printf("\n\t\t\033[1;33m<<<Your PIN has been changed successfully.>>>\n\t\t<<<Please login again with your new PIN.>>>\033[1;37m\n");
                        } else {
                            printf("\n\t\t\033[1;33m<<<\033[1;31mPIN Invalid\e[0m\033[1;33m>>>\033[1;37m\n");
                            goto reset;
                        }
                        break;
                    case 5:
                        printf("\nThank you for using the ATM Machine\n");
                        printf("Please rate your experience (1-5): ");
                        scanf("%d", &feedback);

                        printf("\n\t\t\t\033[1;33mTHANK YOU FOR YOUR FEEDBACK!\033[1;37m\n");
                        exit(0);
                    default:
                        printf("\n\033[3;31mInvalid choice\e[0m\n");
                    }
                } while (choice != 4);
            }
        }
        if (flag) {
            printf("\n\033[3;31m Invalid Account Number OR PIN\033[1;37m\e[0m\n");
        }
    } while (1);

    return 0;
}
