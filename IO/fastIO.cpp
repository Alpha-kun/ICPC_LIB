//put at beginning of main() for fast I/O
ios::sync_with_stdio(0);
cin.tie(NULL);

//in case of ridiculously large I/O
void fastscan(int &number) {
    int sign = 1;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-') {
        sign = -1;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    number *= sign;
}