int n = 10;
int r;
char s = 'a';
int a[10];
//pointer
int *p;
//string
char *str = " ";
int i;
void hello(char s, char k);


void fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main() {
    r = fibonacci(n);
    if (r == 55) {
        printf("fibonacci(%d) = %d\n", n, r);
    } else {
        printf("fibonacci(%d) = %d\n", n, r);
    }
    return 0;
}
