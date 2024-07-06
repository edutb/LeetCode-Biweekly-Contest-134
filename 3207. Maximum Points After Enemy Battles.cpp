class Solution
{
public:
    long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
    {

        int weakest = 1e9;
        long long sum = 0;
        for (auto &v : enemyEnergies)
        {
            sum += v;
            weakest = min(weakest, v);
        }

        if (weakest > currentEnergy)
            return 0;
        sum += currentEnergy - 2 * weakest;
        return 1 + sum / weakest;
    }
};