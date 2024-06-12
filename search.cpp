#include <bits/stdc++.h>
using namespace std;

int m, mq, a, b;
long long FULL_MASK;

struct Move
{
    int start;
    int length;
};

vector<Move> isVacant(long long state, int u, int d)
{
    vector<Move> moves;
    long long mask = 0;
    for (int i = 0; i <= 3; ++i)
    {
        mask |= (1ll << (u + i * d));
    }
    if ((state & mask) == 0 && u + 3 * d < mq)
    {
        moves.push_back({u, d});
    }
    return moves;
}

long long addElement(long long state, int u, int d)
{
    for (int i = 0; i <= 3; ++i)
    {
        state |= (1ll << (u + i * d));
    }
    return state;
}

vector<vector<Move>> search(long long state, vector<Move> path)
{
    vector<vector<Move>> solutions;
    if (state == FULL_MASK)
    {
        solutions.push_back(path);
        return solutions;
    }
    for (int i = 0; i < mq; ++i)
    {
        if ((state & (1ll << i)) == 0)
        {
            for (int j = 1; j <= mq / 3; ++j)
            {
                auto validMoves = isVacant(state, i, j);
                if (!validMoves.empty())
                {
                    Move move = validMoves[0];
                    vector<Move> newPath = path;
                    newPath.push_back(move);
                    long long newState = addElement(state, move.start, move.length);
                    auto subSolutions = search(newState, newPath);
                    solutions.insert(solutions.end(), subSolutions.begin(), subSolutions.end());
                }
            }
            break;
        }
    }
    return solutions;
}

int main()
{
    cout << "请输入m,a,b"<<endl;
    cin >> m >> a >> b;
    mq = 4 * m + 2;
    FULL_MASK = (1ll << mq) - 1;
    vector<Move> initialPath;
    long long ab = (1ll << (a - 1)) + (1ll << (b - 1));
    auto solutions = search(ab, initialPath);
    for (const auto &solution : solutions)
    {
        for (const auto &move : solution)
        {
            for (int i = 0; i < 4; i++)
            {
                cout << move.start + i * move.length + 1 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}#include <bits/stdc++.h>
using namespace std;

int m, mq, a, b;
long long FULL_MASK;

struct Move
{
    int start;
    int length;
};

vector<Move> isVacant(long long state, int u, int d)
{
    vector<Move> moves;
    long long mask = 0;
    for (int i = 0; i <= 3; ++i)
    {
        mask |= (1ll << (u + i * d));
    }
    if ((state & mask) == 0 && u + 3 * d < mq)
    {
        moves.push_back({u, d});
    }
    return moves;
}

long long addElement(long long state, int u, int d)
{
    for (int i = 0; i <= 3; ++i)
    {
        state |= (1ll << (u + i * d));
    }
    return state;
}

vector<vector<Move>> search(long long state, vector<Move> path)
{
    vector<vector<Move>> solutions;
    if (state == FULL_MASK)
    {
        solutions.push_back(path);
        return solutions;
    }
    for (int i = 0; i < mq; ++i)
    {
        if ((state & (1ll << i)) == 0)
        {
            for (int j = 1; j <= mq / 3; ++j)
            {
                auto validMoves = isVacant(state, i, j);
                if (!validMoves.empty())
                {
                    Move move = validMoves[0];
                    vector<Move> newPath = path;
                    newPath.push_back(move);
                    long long newState = addElement(state, move.start, move.length);
                    auto subSolutions = search(newState, newPath);
                    solutions.insert(solutions.end(), subSolutions.begin(), subSolutions.end());
                }
            }
            break;
        }
    }
    return solutions;
}

int main()
{
    cout << "请输入m,a,b"<<endl;
    cin >> m >> a >> b;
    mq = 4 * m + 2;
    FULL_MASK = (1ll << mq) - 1;
    vector<Move> initialPath;
    long long ab = (1ll << (a - 1)) + (1ll << (b - 1));
    auto solutions = search(ab, initialPath);
    for (const auto &solution : solutions)
    {
        for (const auto &move : solution)
        {
            for (int i = 0; i < 4; i++)
            {
                cout << move.start + i * move.length + 1 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
