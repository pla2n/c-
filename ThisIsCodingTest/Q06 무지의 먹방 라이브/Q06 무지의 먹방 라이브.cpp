#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0, t;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < food_times.size(); i++)
        pq.push((food_times[i], i+1));
    t = pq[0][0]
    return answer;
}

int main()
{
    vector<int> food_times = { 3, 1, 2 };
    solution(food_times, 5);
}