#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[1001], b[1001];
    int acount[123], bcount[123], i, j;

    while (scanf("%[^\n]", &a) != EOF) {
        getchar();
        memset(acount, 0, sizeof(acount));
        memset(bcount, 0, sizeof(bcount));

        for (i = 0; i < strlen(a); i++) {
            acount[(int)a[i]]++;
        }
        scanf("%[^\n]", &b);
        getchar();
        for (i = 0; i < strlen(b); i++) {
            bcount[(int)b[i]]++;
        }

        for (i = 'a'; i <= 'z'; i++) {
            j = 0;
            while (j < acount[i] && j < bcount[i]) {
                printf("%c", i);
                j++;
            }
        }
        printf("\n");
    }

    return 0;
}
