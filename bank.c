#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear_screen() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux/Mac
#endif
}

typedef struct BankAccount {
    char account_holder[50];
    char bank_name[100];
    int account_number;
    int account_balance;
} BankAccount;

void deposit(BankAccount *account, int amount) {
    if (amount < 0) {
        printf("Amount can't be negative!!\n");
        return;
    } else {
        account->account_balance += amount;
    }
}

void withdraw(BankAccount *account, int amount) {
    if (amount < 0) {
        printf("Amount can't be negative!!\n");
        return;
    } else {
        account->account_balance -= amount;
    }
}

BankAccount create_account() {
    BankAccount account;

    FILE *file = fopen("last_user_id_created.txt", "r");
    int last_user_id;
    fscanf(file, "%d", &last_user_id);
    account.account_number = last_user_id;
    fclose(file);

    last_user_id++;

    FILE *file2 = fopen("last_user_id_created.txt", "w");
    fprintf(file2, "%d", last_user_id);
    fclose(file2);

    printf("\nEnter account holder name: ");
    scanf("%s", account.account_holder);
    printf("Enter bank name: ");
    scanf("%s", account.bank_name);
    printf("Enter account balance: ");
    scanf("%d", &account.account_balance);
    return account;
}

void save_accounts_to_file(BankAccount users[], int user_count) {
    FILE *file = fopen("accounts.dat", "wb");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    fwrite(users, sizeof(BankAccount), user_count, file);
    fclose(file);
}

int load_accounts_from_file(BankAccount users[]) {
    FILE *file = fopen("accounts.dat", "rb");
    if (!file) {
        // If the file doesn't exist, return 0 accounts
        return 0;
    }
    int count = 0;
    while (fread(&users[count], sizeof(BankAccount), 1, file)) {
        count++;
    }
    fclose(file);
    return count;
}

void save_data_to_text_file(BankAccount users[], int user_count) {
    FILE *file = fopen("accounts.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "Account holder: %s\nBank name: %s\nAccount number: %d\nAccount balance: %d\n\n",
                users[i].account_holder, users[i].bank_name, users[i].account_number, users[i].account_balance);
    }
    fclose(file);
}

int main() {
    clear_screen();
    BankAccount users[10];
    int user_count = load_accounts_from_file(users); // Load accounts on startup
    printf("          Welcome to Bank System\n\n");

    while (1) {
        printf("1. Create account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            FILE *file = fopen("last_user_id_created.txt", "r");
            int last_user_id;
            fscanf(file, "%d", &last_user_id);
            fclose(file);

            if (user_count >= 10) {
                printf("User limit reached!\n");
                continue;
            }
            users[user_count] = create_account();
            user_count++;
            printf("\nAccount created:\nAccount holder: %s\nBank name: %s\nAccount number: %d\nAccount balance: %d\n\n",
                   users[user_count - 1].account_holder, users[user_count - 1].bank_name,
                   users[user_count - 1].account_number, users[user_count - 1].account_balance);
        } else if (choice == 2) {
            printf("\nEnter account number: ");
            int account_number;
            scanf("%d", &account_number);
            if (account_number >= user_count || account_number < 0) {
                printf("Invalid account number!\n");
                continue;
            }
            printf("Enter amount to deposit: ");
            int amount;
            scanf("%d", &amount);
            deposit(&users[account_number], amount);
        } else if (choice == 3) {
            printf("\nEnter account number: ");
            int account_number;
            scanf("%d", &account_number);
            if (account_number >= user_count || account_number < 0) {
                printf("Invalid account number!\n");
                continue;
            }
            printf("Enter amount to withdraw: ");
            int amount;
            scanf("%d", &amount);
            withdraw(&users[account_number], amount);
        } else if (choice == 4) {
            printf("\nEnter account number: ");
            int account_number;
            scanf("%d", &account_number);
            if (account_number >= user_count || account_number < 0) {
                printf("Invalid account number!\n");
                continue;
            }
            printf("\nAccount Holder: %s\nAccount balance: %d\n\n", users[account_number].account_holder,users[account_number].account_balance);
        } else if (choice == 5) {
            save_accounts_to_file(users, user_count); // Save accounts on exit
            save_data_to_text_file(users, user_count);
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
