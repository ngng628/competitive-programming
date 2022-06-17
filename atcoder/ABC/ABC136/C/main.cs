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
        new AtCoder().solve();
        return 0;
    }

    static Scanner cin;

    void solve()
    {
        int n = cin.nextInt();
        int[] a = cin.ArrayInt(n);

        a[0] -= 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] < a[i])
            {
                a[i] -= 1;
            }
        }

        bool ok = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
            {
                ok = false;
            }
        }

        if (ok)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
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

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}