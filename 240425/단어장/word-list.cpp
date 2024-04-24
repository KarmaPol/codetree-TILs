#include <iostream>
#include <map>

using namespace std;

int main() {

    int n;
    map<string, int> words;

    cin >> n;

    while(n--){
        string temp;
        cin >> temp;

        words[temp]++;
    }

    for(auto word : words) {
        cout << word.first << ' ' << word.second << '\n';
    }

    return 0;
}