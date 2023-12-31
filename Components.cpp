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

const long long int N = 1e5 + 5;
vector<long long int> adj[N];
bool visited[N];

void dfs(long long int u, long long int &cmpSize)
{
    visited[u] = true;
    cmpSize++;

    for (long long int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v, cmpSize);
    }
}

int main()
{
    long long int n = 1000, m, o;
    cin >> o >> m;

    for (long long int i = 0; i < m; i++)
    {
        long long int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long int> cmp;

    for (long long int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        long long int cmpSize = 0;
        dfs(i, cmpSize);
        cmp.push_back(cmpSize);
    }

    sort(cmp.begin(), cmp.end());

    for (long long int s : cmp)
    {
        if (s == 1)
            continue;
        else
            cout << s << " ";
    }

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