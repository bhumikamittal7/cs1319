// Find fibonacci by co-recursion
int fibonacci(int n);
int f_odd(int n);
int f_even(int n);
void printStr(char * s);
void printInt(int n);

int fibonacci(int n) {
    return (n % 2 == 0)? f_even(n): f_odd(n);
}

int f_odd(int n) {
    return (n == 1)? 1: f_even(n-1) + f_odd(n-2);
}

int f_even(int n) {
    return (n == 0)? 0: f_odd(n-1) + f_even(n-2);
}

int main() {
    int n = 10;
    int r;
    r = fibonacci(n);
    printStr("fibo(");
    printInt(n);
    printStr(") = ");
    printInt(r);
    return 0;
}

