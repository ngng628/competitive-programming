import std.stdio;

void main()
{
    int a, b;
    readf("%d %d\n", &a, &b);
    if ((a*b) % 2 == 1)
    {
        writeln("Odd");
    }
    else
    {
        writeln("Even");
    }
}
