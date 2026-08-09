#include <stdio.h>

int main() {
    int ch, i;
    float balance = 1000, amount;
    char trans[5][50];
    int count = 0;

    while(1) {
        printf("\n1.Check Balance\n2.Deposit\n3.Withdraw\n4.Last 5 Transactions\n5.Exit\n");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Balance = %.2f\n", balance);
        }

        else if(ch == 2) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            balance += amount;
            sprintf(trans[count % 5], "Deposited %.2f", amount);
            count++;
        }

        else if(ch == 3) {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if(amount <= balance) {
                balance -= amount;
                sprintf(trans[count % 5], "Withdrew %.2f", amount);
                count++;
            }
            else {
                printf("Insufficient Balance\n");
            }
        }

        else if(ch == 4) {
            printf("Last Transactions:\n");
            int start = count > 5 ? count - 5 : 0;

            for(i = start; i < count; i++)
                printf("%s\n", trans[i % 5]);
        }

        else if(ch == 5) {
            break;
        }
    }

    return 0;
}