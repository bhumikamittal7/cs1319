int main(){
    int * a;
    a = 5;
    char * b;
    b = 'c';
    char * c = b;
    b = a;
    a = c;
    void * d = a;
    return 0;
}