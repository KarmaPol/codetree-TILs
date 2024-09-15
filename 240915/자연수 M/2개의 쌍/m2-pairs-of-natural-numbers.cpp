#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> numbers(n); // 갯수, 숫자

    for(int i = 0; i < n; i++) {
        cin >> numbers[i].second >> numbers[i].first;
    }

    sort(numbers.begin(), numbers.end(), cmp);

    int leftIdx = 0, rightIdx = n - 1;
    int answer = -2e9;

    while(leftIdx <= rightIdx) {
        int leftNumber = numbers[leftIdx].first, leftCount = numbers[leftIdx].second;
        int rightNumber = numbers[rightIdx].first, rightCount = numbers[rightIdx].second;

        answer = max(answer, leftNumber + rightNumber);

        if(leftCount > rightCount) {
            numbers[leftIdx].second -= rightCount;
            numbers[rightIdx].second -=  rightCount;
            rightIdx--;
        }

        else if(leftCount < rightCount) {
            numbers[leftIdx].second -= leftCount;
            numbers[rightIdx].second -=  leftCount;
            leftIdx++;
        }

        else {
            numbers[leftIdx].second -= leftCount;
            numbers[rightIdx].second -=  leftCount;
            leftIdx++; rightIdx--;
        }
    }

    cout << answer;

    return 0;
}