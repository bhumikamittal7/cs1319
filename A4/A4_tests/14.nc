char * add_array(char * s, char * t, int n){
    int i = 0;
    for(i = 0; i < n; i = i + 1){
        int a = s[i];
        a = a + t[i];
        s[i] = a;
    }
    return s;
}

int main(){
    char * s = "abc";
    char * t = "def";
    int n = 3;
    add_array(s, t, n);
    return 0;
}