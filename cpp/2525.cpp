#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int hour, minute;
    cin >> hour >> minute;

    int cost;
    cin >> cost;

    minute += cost;

    hour = (hour + minute / 60) % 24;
    minute = minute % 60;

    cout << hour << ' ' << minute << endl;
    
    return EXIT_SUCCESS;
}

