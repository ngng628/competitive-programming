using System;
using System.Text;
using System.Diagnostics;
using System.Numerics;
using System.Collections.Generic;
using System.Linq;

class AtCoder
{
    public AtCoder() { }
    public static int Main()
    {
        cin = new Scanner();
        new AtCoder().calc();
        return 0;
    }

    static Scanner cin;

    void calc()
    {
        long n = cin.nextLong();

        long ans = long.MaxValue;
        for (long i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                long a = i;
                long b = n / i;
                ans = Math.Min(ans, a + b - 2);
            }
        }

        Console.WriteLine(ans);
    }
}

class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }
}