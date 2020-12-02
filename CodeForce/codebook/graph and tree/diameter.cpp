int ans;
int dfs(int x, int p)
{
    int mh1 = 0, mh2 = 0, cur;
    for (auto i : arr[x]) {
        if (i != p) {
            cur = dfs(i, x);
            if (cur > mh1)
                mh2 = mh1, mh1 = cur;
            else if (cur > mh2)
                mh2 = cur;
        }
    }
    ans = max(ans, mh1 + mh2);
    return mh1 + 1;
}