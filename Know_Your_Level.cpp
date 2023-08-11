// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

// #include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];

vector<int> bfs(int s, int n)
{
    queue<int> que;

    que.push(s);
    visited[s] = true;
    level[s] = 0;

    vector<int> shops;

    while (!que.empty())
    {
        int curr = que.front();
        que.pop();

        if (level[curr] == n)
        {
            shops.push_back(curr);
        }

        for (int v : adj[curr])
        {
            if (visited[v] == true)
                continue;
            que.push(v);
            visited[v] = true;
            level[v] = level[curr] + 1;
        }
    }
    return shops;
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    int floor;
    cin >> floor;

    vector<int> curr = bfs(0, floor);

    if (curr.empty())
    {
        cout << "-1";
    }

    else
    {
        sort(curr.begin(), curr.end());
        for (int s : curr)
        {
            cout << s << " ";
        }
    }

    return 0;
}