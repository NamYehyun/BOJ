#include <iostream>
#include <map>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, string> site_to_passwd;

    while (n--) {
        string site, passwd;
        cin >> site >> passwd;
        site_to_passwd[site] = passwd;
    }

    while (m--) {
        string site;
        cin >> site;
        cout << site_to_passwd[site] << '\n';
    }

    return EXIT_SUCCESS;
}

