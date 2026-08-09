#include <stdio.h>

struct Student {
    int roll, marks[5], total;
    char name[20], grade;
    float per;
};

int main() {
    int n, i, j, fail, top = 0;
    float avg = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for(i = 0; i < n; i++) {
        printf("\nRoll Name: ");
        scanf("%d %s", &s[i].roll, s[i].name);

        s[i].total = 0;
        fail = 0;

        printf("Enter 5 subject marks: ");
        for(j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
            if(s[i].marks[j] < 35)
                fail = 1;
        }

        s[i].per = s[i].total / 5.0;
        avg += s[i].per;

        if(fail)
            s[i].grade = 'F';
        else if(s[i].per >= 90)
            s[i].grade = 'A';
        else if(s[i].per >= 75)
            s[i].grade = 'B';
        else if(s[i].per >= 60)
            s[i].grade = 'C';
        else
            s[i].grade = 'D';

        if(s[i].per > s[top].per)
            top = i;
    }

    printf("\nTopper: %s %.2f\n", s[top].name, s[top].per);

    printf("Failed Students:\n");
    for(i = 0; i < n; i++)
        if(s[i].grade == 'F')
            printf("%s\n", s[i].name);

    printf("Class Average = %.2f\n", avg / n);

    return 0;
}