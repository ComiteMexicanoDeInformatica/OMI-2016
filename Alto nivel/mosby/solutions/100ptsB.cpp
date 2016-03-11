#include <stdio.h>

long long Euclides(int a, int b) {
    if (b == 0) return 0;
    return a / b + Euclides(b, a % b);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%lld\n", Euclides(n, m));
    return 0;
}
