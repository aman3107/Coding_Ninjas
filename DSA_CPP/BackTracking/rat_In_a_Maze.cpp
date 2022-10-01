#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void printMaze(int **sol, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << sol[i][j] << " ";
    }
  }
  cout << endl;
}

void mazeHelper(int **maze, int n, int **sol, int x, int y)
{
  if (x == n - 1 && y == n - 1)
  {
    sol[x][y] = 1;
    printMaze(sol, n);
    sol[x][y] = 0;
    return;
  }
  if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || sol[x][y] == 1)
    return;
  sol[x][y] = 1;
  mazeHelper(maze, n, sol, x - 1, y);
  mazeHelper(maze, n, sol, x + 1, y);
  mazeHelper(maze, n, sol, x, y - 1);
  mazeHelper(maze, n, sol, x, y + 1);
  sol[x][y] = 0;
}

void ratInAMaze(int **maze, int n)
{
  int **sol;
  sol = new int *[n];
  for (int i = 0; i < n; i++)
  {
    sol[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      sol[i][j] = 0;
    }
  }

  mazeHelper(maze, n, sol, 0, 0);
}

int main()
{
  int n;
  cin >> n;
  int **maze;
  maze = new int *[n];
  for (int i = 0; i < n; i++)
  {
    maze[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      cin >> maze[i][j];
    }
  }
  ratInAMaze(maze, n);
  delete[] maze;
}