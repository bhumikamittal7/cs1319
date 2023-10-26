int main() {
    char *c = "\"";
    char *d = " ''\'''\' //";
    char *e = " \n \v \\ \? \a \f /* */";
    char *f = "";
    char g = '\n';
    char h = '\"';
    int s = 0;
    if (s != 0) {
        // do nothing
        /* do nothing */
    } else {
        s = 1;
    }
    if (s == 1)
        s = 10;
    for (; s == 2;)
        s = 2;
    int x = 2 + 05;
    x = 3 +5;
    return 0;
}

// Find fibonacci by co-recursion
int f_odd(int n) {
    return (n == 1) ? 1 : f_even(n - 1) + f_odd(n - 2);
}

int f_even(int n) {
    return (n == 0) ? 0 : f_odd(n - 1) + f_even(n - 2);
}

int fibonacci(int n) {
    return (n % 2 == 0) ? f_even(n) : f_odd(n);
}


int main() {
    int n = 10;
    int r;
    r = fibonacci(n);
    return 0;
}
