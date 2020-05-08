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
        int above = 0, below = 0;
        for (int i = n + 1; i <= m; i++) {
            int num = i;
            while (num % 2 == 0) {
                num = num / 2;
                above++;
            };
        }

        for (int j = 1; j <= m - n; j++) {
            int num = j;
            while (num % 2 == 0) {
                num = num / 2;
                below++;
            };
        }
        printf("%d\n", above - below);
    }
    return 0;
}