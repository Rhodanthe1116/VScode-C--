int md, mdx;
void dfs(int x, int p, int d = 0)
{
    if (d > md)
        md = d, mdx = x;
    for (auto i : arr[x]) {
        if (i != p)
            dfs(i, x, d + 1);
    }
}
int find_diameter()
{
    md = -1;
    dfs(0, 0);
    md = -1;
    dfs(mdx, mdx);
    return md;
}