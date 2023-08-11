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

void dfs(int u, int &count)
{
    visited[u] = true;
    count++;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v, count);
    }
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
    }

    int k;
    cin >> k;

    int count = 0;

    if (!adj[k].empty())
    {
        dfs(k, count);
        if (visited[k]) // check if k is visited more than once due to a cycle
            count--;    // exclude k from the count
    }

    cout << count << endl;

    return 0;
}

/*

*/
/*
here is my code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u, int &count)
{
    visited[u] = true;
    count++;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v, count);
    }
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
    }

    int k;
    cin >> k;

    int count = 0;

    if (!adj[k].empty())
    {
        dfs(k, count);
    }

    cout << count - 1 << endl;

    return 0;
}


please check all the possible test casses for this and give me back the revised code, Thanks

this input:
10 8
999 1000
100 500
500 600
110 120
100 600
110 1000
100 150
50 20


why I'm not receiving any output for this input:
5 3
100 500
500 600
999 1000


Iwould like to print the number nodes in each component in ascending order.
Note: There will be no component with single node.

for this input:
9
7
0 1
1 2
0 2
2 3
4 5
5 7
8 9

my expected output is:
2 3

but I'm getting this output:
1 1 1 1 1


I need to work both tescases by same code
*/

/*
Problem Statement

You will be given an undirected graph as input. You need to tell the number nodes in each component in ascending order.

Note: There will be no component with single node.

Input Format

First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 1000.
Next E lines will contain A, B which means there is a edge between node A and B.
Constraints

1 <= N, E <= 1000
Output Format

Output the number of nodes in each component in ascending order.

Sample Input:
9 7
0 1
1 2
0 2
2 3
4 5
5 7
8 9

Sample Output:
2 3 4

*/