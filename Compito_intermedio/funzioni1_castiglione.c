// Funzioni per le operazioni:
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
float divi(int a, int b) { 
    return (b != 0) ? (float)a / b : 0; 
}
int mod(int a, int b) {
    return (b != 0) ? a % b : 0;
}
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}

// Funzione per testare tutte le operazioni:
void test_all_operations(int arr[], int size) {
    printf("\nTest delle operazioni sui numeri {2, 4, 6, 8, 10}:\n");
    for (int i = 0; i < size - 1; i++) {
        printf("%d + %d = %d\n", arr[i], arr[i+1], add(arr[i], arr[i+1]));
        printf("%d - %d = %d\n", arr[i+1], arr[i], sub(arr[i+1], arr[i]));
        printf("%d * %d = %d\n", arr[i], arr[i+1], mul(arr[i], arr[i+1]));
        printf("%d / %d = %.2f\n", arr[i+1], arr[i], divi(arr[i+1], arr[i]));
        printf("%d %% %d = %d\n", arr[i], arr[i+1], mod(arr[i], arr[i+1]));
        printf("%d ^ %d = %d\n", arr[i], arr[i+1], power(arr[i], arr[i+1]));
    }
}
