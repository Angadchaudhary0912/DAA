#include <stdio.h>

struct Book {
    int id, total, avail;
    char title[30], author[30];
};

int main() {
    struct Book b[50];
    int n = 0, ch, id, i, f;

    while(1) {
        printf("\n1.Add\n2.Search\n3.Issue\n4.Return\n5.Unavailable\n6.Exit\n");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("ID Title Author Total Copies: ");
            scanf("%d%s%s%d", &b[n].id, b[n].title, b[n].author, &b[n].total);
            b[n].avail = b[n].total;
            n++;
        }

        else if(ch == 2) {
            printf("Enter ID: ");
            scanf("%d", &id);
            f = 0;
            for(i = 0; i < n; i++) {
                if(b[i].id == id) {
                    printf("%d %s %s %d/%d\n", b[i].id, b[i].title, b[i].author, b[i].avail, b[i].total);
                    f = 1;
                }
            }
            if(f == 0)
                printf("Book not found\n");
        }

        else if(ch == 3) {
            printf("Enter ID: ");
            scanf("%d", &id);
            for(i = 0; i < n; i++)
                if(b[i].id == id && b[i].avail > 0)
                    b[i].avail--;
        }

        else if(ch == 4) {
            printf("Enter ID: ");
            scanf("%d", &id);
            for(i = 0; i < n; i++)
                if(b[i].id == id && b[i].avail < b[i].total)
                    b[i].avail++;
        }

        else if(ch == 5) {
            printf("Unavailable Books:\n");
            for(i = 0; i < n; i++)
                if(b[i].avail == 0)
                    printf("%d %s\n", b[i].id, b[i].title);
        }

        else if(ch == 6)
            break;
    }

    return 0;
}