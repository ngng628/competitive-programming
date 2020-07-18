import std.stdio;
import std.string;

void main()
{
    int a, b, c;
    string s;
    readf("%d\n", &a);
    readf("%d %d\n", &b, &c);
    s = readln.strip;

    writeln(a+b+c, " ", s);
}
