class Solution {
public:
    int n;
    long long maxi = -1, count = 0;

    int solver(vector<vector<int>>& adj, int node) {
        long long score = 1;
        int childs = adj[node].size();
        int leftNode = 0, rightNode = 0;
        if (childs > 0)
            leftNode = solver(adj, adj[node][0]);
        if (childs > 1)
            rightNode = solver(adj, adj[node][1]);
        if (leftNode > 0)
            score *= leftNode;
        if (rightNode > 0)
            score *= rightNode;
        int parentNode = n - leftNode - rightNode - 1;
        if (parentNode > 0)
            score *= parentNode;

        if (score > maxi) {
            maxi = score;
            count = 1;
        } else if (score == maxi) {
            count++;
        }
        return leftNode + rightNode + 1;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parents[i]].push_back(i);
        }

        solver(adj, 0);
        return count;
    }
};