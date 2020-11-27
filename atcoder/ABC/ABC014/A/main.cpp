# include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int r = a % b;
    int ans = r == 0 ? 0 : b - r;

    std::cout << ans << std::endl;

    return 0;
}
