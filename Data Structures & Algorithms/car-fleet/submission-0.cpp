class Solution {
public:
    int carFleet(int target, vector<int>& position,
                 vector<int>& speed) {
        vector<pair<int, int>> cars;

        int n = static_cast<int>(position.size());

        for (int i = 0; i < n; ++i) {
            cars.push_back({position[i], speed[i]});
        }

        // 从最靠近终点的车开始处理
        sort(cars.begin(), cars.end(),
             [](const auto& a, const auto& b) {
                 return a.first > b.first;
             });

        stack<double> fleets;

        for (const auto& car : cars) {
            double time =
                static_cast<double>(target - car.first) / car.second;

            if (fleets.empty() || time > fleets.top()) {
                // 追不上前面的车队，形成新车队
                fleets.push(time);
            }

            // 否则合并到前车队，不增加数量，也不改变其到达时间
        }

        return static_cast<int>(fleets.size());
    }
};