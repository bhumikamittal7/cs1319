char * fun(char * s, int n){
    char *d = 0;
    return d;
}

int main(){
    int n = 31;
    char s[31] = "pldi2023\"\'?/**/~!@#$%^&*()[]:\n";
    char d = 't';
    int a[2];
    a[2] = 1;
    a[1] = 0;
    a[0] = 2;
    int i = 0;
    s[a[i]] = d;
    int e = (fun(s,n) == 0);

    return 0;
}