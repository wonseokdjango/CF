#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> colors;
vector<int> dedges;
vector<pair<int, int> > edges;

int main(void)
{
    // input.
    scanf(" %d", &n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        scanf(" %d %d", &u, &v);
        edges.push_back(pair<int, int>(u - 1, v - 1));
    }

    colors.assign(n, 0);
    for (int i = 0; i < n; ++i)
        scanf(" %d", &colors[i]);
    
    // count d-edges.
    int total = 0;
    dedges.assign(n, 0);
    for (int idx = 0; idx < edges.size(); ++idx)
    {
        if (colors[edges[idx].first] != colors[edges[idx].second])
        {
            ++total;
            ++dedges[edges[idx].first];
            ++dedges[edges[idx].second];
        }

    }

    // find root.
    int idx;
    for (idx = 0; idx < n; ++idx)
    {
        if (dedges[idx] == total)
            break;
    }

    if (idx != n)
        printf("YES\n%d\n", idx + 1);
    else
        printf("NO\n");

    return 0;
}
