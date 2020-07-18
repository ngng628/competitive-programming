import std.stdio;
import std.algorithm;
import std.string;
import std.conv;

void main()
{
    int N;
    readf("%d\n", &N);
    int[] A = readln.split.to!(int[]);
    auto f(int x) {
        int cnt = 0;
        while (x % 2 == 0)
        {
            cnt++;
            x /= 2;
        }
        return cnt;
    }
    writeln(A.map!f.reduce!min);
}
