class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {

        int ans = 0;
        int n = colors.size();
        int cur = 1;

        for (int i = 1; i < n + k - 1; i++)
        {
            cur = (colors[i % n] != colors[(i - 1) % n] ? cur + 1 : 1);

            if (cur == k)
            {
                ans++;
                cur--;
            }
        }

        return ans;
    }
};