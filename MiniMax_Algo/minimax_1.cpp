#include <bits/stdc++.h>

#define ll  long long
#define ull unsigned long long
#define INF 1e18

bool IsTie(char Board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] >= '0' && Board[i][j] <= '9')
            {
                return false;
            }
        }
    }
    return true;
}

char CheckWinner(char Board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2])
        {
            return Board[i][0];
        }
        if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i])
        {
            return Board[0][i];
        }
    }
    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])
    {
        return Board[0][0];
    }
    if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])
    {
        return Board[0][2];
    }
    return '0';
}

char Player = 'O';
char AI = 'X';

ll MiniMax(char Board[3][3], bool ismaxing, ll alpha, ll beta, ll depth)
{
    char winner = CheckWinner(Board);
    if (winner == AI) return 10 - depth;
    if (winner == Player) return depth - 10;
    if (IsTie(Board)) return 0;

    if (ismaxing)
    {
        ll MaxScore = -INF;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Board[i][j] >= '0' && Board[i][j] <= '9')
                {
                    char temp = Board[i][j];
                    Board[i][j] = AI;
                    ll score = MiniMax(Board, false, alpha, beta, depth + 1);
                    MaxScore = std::max(MaxScore, score);
                    Board[i][j] = temp;
                    alpha = std::max(alpha, score);
                    if (beta <= alpha) break;
                }
            }
        }
        return MaxScore;
    }
    else
    {
        ll MinScore = INF;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Board[i][j] >= '0' && Board[i][j] <= '9')
                {
                    char temp = Board[i][j];
                    Board[i][j] = Player;
                    ll score = MiniMax(Board, true, alpha, beta, depth + 1);
                    MinScore = std::min(MinScore, score);
                    Board[i][j] = temp;
                    beta = std::min(beta, score);
                    if (beta <= alpha) break;
                }
            }
        }
        return MinScore;
    }
}

int main()
{
    return 0;
}
