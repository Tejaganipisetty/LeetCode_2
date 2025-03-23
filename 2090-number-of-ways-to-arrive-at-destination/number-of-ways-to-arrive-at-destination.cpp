class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> ways(n, 0);
        vector<long long> dist(n, 1e18);
        vector<vector<pair<int, int>>> graph(n);

        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        ways[0] = 1;
        dist[0] = 0;
        int mod = 1e9 + 7;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, curr] = pq.top();
            pq.pop();

            if (d > dist[curr]) continue;

            for (auto& neighbor : graph[curr]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    ways[nextNode] = ways[curr];
                    pq.push({dist[nextNode], nextNode});
                } else if (d + weight == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[curr]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
