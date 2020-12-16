#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int N = 100001;
enum COLOR {WHITE, BLACK};

int n, m;
int count = 0;
vector<int> graph[N]; // graph1[i] - список вершин, в которые можно попасть через вершину i

bool dfs(int v)
{
    ++count;
    for (unsigned i = 1; i < graph[v].size(); ++i)
        dfs(graph[v][i]);
    if (count == n)
        return true;
    else
    {
        --count;
        return false;
    }
}

bool hamiltonian()
{
    for (int i = 1; i <= n; ++i)
        if (dfs(i))
            return true;
    return false;
}

int main()
{
    ifstream in("hamiltonian.in.txt");
    ofstream out("hamiltonian.out.txt");
    int i, u, v;
    in >> n >> m;
    for (i = 0; i <= n; ++i)
        graph[i].push_back(i);
    for (i = 0; i < m; ++i)
    {
        in >> u >> v;
        graph[u].push_back(v);
    }
    if (hamiltonian())
        out << "YES";
    else
        out << "NO";
    in.close();
    out.close();
    return 0;
}
