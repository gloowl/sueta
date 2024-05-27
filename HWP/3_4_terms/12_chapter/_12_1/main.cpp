#include <iostream>
#include <vector>

void FW(std::vector<std::vector<int>> &dist)
{
  int n = dist.size();

  for (int k = 1; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dist[i][j] = std::min(dist[i][j], dist[i][k-1] + dist[k-1][j]);
}

void g_input(std::vector<std::vector<int>> &dist)
{
  std::cout << '\n';

  int n = dist.size();

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      std::cin >> dist[i][j];

  std::cout << '\n';
}

void g_output(const std::vector<std::vector<int>> &dist)
{
  std::cout << '\n';

  int n = dist.size();

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      std::cout << dist[i][j] << ' ';

    std::cout << '\n';
  }

  std::cout << '\n';
}

int main()
{
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> dist(n, std::vector<int>(n));

  g_input(dist);

  FW(dist);

  g_output(dist);

  return 0;
}

/*

4
0 10 0 0
10 0 5 1
0 5 0 7
0 1 7 0

*/