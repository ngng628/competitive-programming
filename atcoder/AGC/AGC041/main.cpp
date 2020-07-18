# include "YatCoder.hpp"
# include "Color.h"

void PrintBoard(const Array<Array<int32>>& graph, int32 size);

int main()
{
    int32 size;
    size = 9;
    assert(size & 1);

    // 島の数
    int32 N = size * size;

    // 頂点の数
    int32 V = N;
    // 枝の数
    int32 E = 2*size*(size - 1);

    
    Array<Array<int32>> graph(size * size);

    for (int32 i = 0; i < V; ++i)
    {
        // 辺のとき
        bool isTop    = 0 <= i and i <= size - 1;
        bool isLeft   = i % size == 0;
        bool isRight = (i+1) % size == 0;
        bool isBottom = size*(size-1) <= i and i <= size*size - 1;
        if (i == 0)
        {
            graph[i].push_back(9);
            continue;
        }
        if (i == 9)
        {
            graph[i].push_back(0);
            graph[i].push_back(18);
            continue;
        }
        if (!isTop)
        {
            graph[i].push_back(i - size);
        }
        if (!isLeft)
        {
            graph[i].push_back(i - 1);
        }
        if (!isRight)
        {
            graph[i].push_back(i + 1);
        }
        if (!isBottom)
        {
            graph[i].push_back(i + size);
        }
    }

    PrintBoard(graph, size);



    return 0;
}

void PrintBoard(const Array<Array<int32>>& graph, int32 size)
{
    for (int32 i = 0; i < size; ++i)
    {

        for (int32 k = 0; k < size; ++k)
        {
            //cout << "+----";
            if 
            cout << "----";
        }
        cout << "+" << endl;

        for (int32 k = 0; k < size; ++k)
        {
            if (k == 0)
            {
                cout << "| " << std::setw(2) << size*i+k;
            }
            else if ((size*i+k+1) % size == 0)
            {
                cout << " | " << std::setw(2) << size*i+k << " |\n";
            }
            else if (graph[size*i+k-1].count(size*i+k) == 1)
            {
                cout << " | " << std::setw(2) << size*i+k;
            }
            else
            {
                cout << " " << Color::CharRed << "|" << Color::Reset << " " << std::setw(2) << size*i+k;
            }
        }

    }
    for (int32 k = 0; k < size; ++k)
    {
        printf("+----");
    }
    printf("+\n");
}
