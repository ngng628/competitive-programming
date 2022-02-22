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
        int a = cin.nextInt();
        int b = cin.nextInt();

        int ans = 1;
        for (int i = 0; i < a - b; i++)
        {
            ans *= 32;
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
}