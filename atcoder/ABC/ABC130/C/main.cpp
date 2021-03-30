# include <bits/stdc++.h>
using namespace std;

int main() {
   long long width, height;
   cin >> width >> height;
   int x, y;
   cin >> x >> y;

   long double area = (long double)(width * height) / 2.0;
   int can = (width % 2 == 0 and width / 2 == x and height % 2 == 0 and height / 2 == y ? 1 : 0);
   printf("%.10Lf %d", area, can);
}
