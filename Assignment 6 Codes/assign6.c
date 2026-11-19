#include <stdio.h>

// Recursive function to calculate factorial
int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int n;
    printf("Enter any number : ");
    scanf("%d", &n);
    
    // Call the correct function name 'fact'
    int result = fact(n);
    
    // Print the calculated result
    printf("Factorial of entered number: %d\n", result);
    
    return 0;
}
