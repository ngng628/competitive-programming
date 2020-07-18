public static int Gcd(int a, int b) {
    while (b != 0) {
        var A = a;
        a = b;
        b = A % b;
    }
    return a;
}

public static int Lcm(int a, int b) {
    return a*b / Gcd(a, b);
}
