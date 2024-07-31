class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int i = 0, j = 0;

        // Sort both greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Use a two-pointer approach to find the number of content children
        while (i < n && j < m) {
            if (g[i] <= s[j]) {
                // This child is content with this cookie
                i++;
                j++;
            } else {
                // Try the next cookie for the same child
                j++;
            }
        }

        return i; // The number of content children
    }
};
