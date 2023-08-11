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

using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p = -1)
{
    bool cycleExist = false;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        cycleExist = cycleExist | dfs(v, u);
    }
    return cycleExist;
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // weited hole

        adj[v].push_back(u); // weited hole
    }

    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        isCycle = isCycle | dfs(i);
    }

    if (isCycle)
    {
        cout << "True";
    }
    else
        cout << "False";

    return 0;
}
/*
cycle
8
7
1 2
2 3
3 5
2 4
6 7
6 8
7 8

no cycle

*/