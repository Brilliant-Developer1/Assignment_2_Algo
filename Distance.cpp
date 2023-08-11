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

int bfs(int s, int dst)
{
    queue<int> que;
    vector<bool> visited(N, false);
    vector<int> level(N, -1);

    que.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!que.empty())
    {
        int curr = que.front();
        que.pop();

        // section 1: A node is being processed
        if (curr == dst)
        {
            return level[curr];
        }

        for (int v : adj[curr])
        {
            // section 2 : child processing
            if (visited[v] == true)
                continue;
            que.push(v);
            visited[v] = true;
            level[v] = level[curr] + 1;
            // section 3 : child processing
        }
        // section 4 same as section 1
    }
    return -1;
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

    int Q;
    cin >> Q;

    while (Q--)
    {
        int x, y;
        cin >> x >> y;

        int ans = bfs(x, y);

        cout << ans << endl;
    }
    return 0;
}
/*


*/