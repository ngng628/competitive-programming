using System;
class Myon
{
    public Myon() {}
	static int Main(string[] args)
	{
        cin = new Scanner();
        new Myon().calc();
        return 0;
	}

    static Scanner cin;

    void calc()
    {
        int N = cin.nextInt();
        int[] xs = cin.ArrayInt(N);

        double A = 0.0;
        foreach (int x in xs)
        {
            A += x;
        }
        A /= N;

        foreach (int x in xs)
        {
            Console.WriteLine(Math.Floor(50.0 - (A - x) / 2.0));
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
