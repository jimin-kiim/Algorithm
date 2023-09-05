//
// Created by 김지민 on 2023/09/04.
//
#include <bits/stdc++.h>
using namespace std;

int city[51][51];
int is_survived[14];
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                house.push_back({i, j});
            } else if (city[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    int ans = 999999; // 도시의 치킨 거리의 최솟값
    for (int k = m; k > 0; k--) { // 남겨둘 치킨 집의 개수 M .. 1
        fill(is_survived, is_survived + k, 1); // 남겨둔 치킨 집
        fill(is_survived + k, is_survived + chicken.size(), 0); // 폐업된 치킨 집
        do {
            int city_chicken = 0; // 도시의 치킨 거리
            for (int i = 0; i < house.size(); i++) {
                int house_chicken = 2 * n;
                for (int j = 0; j < chicken.size(); j++) { // 집의 치킨 거리 구하기
                    if (is_survived[j] == 0) continue;
                    int distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                    house_chicken = min(house_chicken, distance);
                }
                city_chicken += house_chicken; // 도시의 치킨 거리
            }
            ans = min(ans, city_chicken); // 도시의 치킨 거리의 최솟값
        } while (next_permutation(is_survived, is_survived + chicken.size()));
    }
    cout << ans;
}

// 각 집의 치킨 거리: 집과 가장 가까운 치킨 집까지의 거리
// 각 도시의 치킨 거리: 모든 집의 치킨 거리의 합
// 치킨 집 중 최대 M 개만 남기고 모두 폐업시킨다. 도시의 치킨 거리 최솟값
// 전체 지도(0 + 1 + 2): N * N
// 집(1): 1 이상 2 * N 이하
// 치킨집(2): M 이상 13 이하