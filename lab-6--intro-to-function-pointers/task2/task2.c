#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) { 
    printf("Adding 'a' and 'b'\n"); 
    return a + b; 
}

int subtract(int a, int b) { 
    printf("Subtracting 'b' from 'a'\n"); 
    return a - b; 
}

int multiply(int a, int b) { 
    printf("Multiplying 'a' and 'b'\n"); 
    return a * b; 
}

int divide(int a, int b) { 
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    printf("Dividing 'a' by 'b'\n"); 
    return a / b; 
}

int exit_program(int a, int b) {
    printf("Exiting program.\n");
    exit(0);
}

int main(void) {
    int a = 6;
    int b = 3;
    int result;
    char input;


    int (*operations[])(int, int) = { add, subtract, multiply, divide, exit_program };

    while (1) {
        printf("Operand 'a' : %d | Operand 'b' : %d\n", a, b);
        printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : multiply | 3 : divide | 4 : exit): ");
        input = getchar();
        getchar();  

        if (input >= '0' && input <= '4') {
            int operation_index = input - '0';  
            result = operations[operation_index](a, b);
            if (operation_index != 4) {  
                printf("x = %d\n", result);
            }
        } else {
            printf("Invalid input. Please enter a valid option.\n");
        }
    }
    return 0;
}
