using System;

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
        int a = cin.nextInt();
        int b = cin.nextInt();
        Console.WriteLine(6 - a - b);
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