# include <iostream>
# include <vector>
# include <myutils.h>
# include <myListNode.h>

#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        int r = 0, v = 0;
        for (int i = n + 1; i <= m; i++) {
            int s = i;
            while (s % 2 == 0) {
                s = s / 2;
                r++;
            };
            print(i);
            print(r);
            print();
        }

        for (int j = 1; j <= m - n; j++) {
            int b = j;
            while (b % 2 == 0) {
                b = b / 2;
                v++;
            }
            print(j);
            print(v);
            print();
        }
        printf("%d\n", r - v);
    }
    return 0;
}