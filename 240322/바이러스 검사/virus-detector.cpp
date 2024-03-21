#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, leader, worker;
    cin >> n;

    vector<int> customers;

    while(n--) {
        int temp;
        cin >> temp;
        customers.push_back(temp);
    }

    long long total = 0;

    cin >> leader >> worker;
    
    for(int i = 0; i < customers.size(); i++) {
        total++;
        customers[i] -= leader;
        int needs = customers[i]/worker;

        if(needs * worker < customers[i]) total++;
    }

    cout << total;

    return 0;
}