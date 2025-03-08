#include <stdio.h>
#include <stdlib.h>

void task1(){
    printf("Hello\n");
}

void task2(){
    int num = 10;
    printf("%d\n",num);
}

void task3(){
    float num = 3.14;
    printf("%.2f\n",num);
}

void task4(){
    int a = 5, b = 7;
    printf("Sum: %d\n", (a + b));
}

void task5(){
    printf("Hello\tWorld\n");
}

void task6(){
    float num = 3.1415;
    printf("%8.3f\n", num);
}

void task7(){
    printf("Sum: %.1f\n", (3.5 + 2.7));
}

void task8(){
    float C;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &C);
    float F = C * 9 / 5 + 32;
    printf("Temperature in Fahrenheit: %.2f\n", F);
}

void task9(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("%s\n", (num % 2 == 0) ? "Парне" : "Непарне");
}

void task10(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Greater number: %d\n", (a > b) ? a : b);
}

int main(){
    int choice;
    do {
        printf("\nChoose a task (1-10, 0 to exit): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            case 10: task10(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
