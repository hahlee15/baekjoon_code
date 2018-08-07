#include <iostream>
using namespace std;
 
char word[51], MinWord[51], tmp[51];
int len=0;
 
bool chkMin() {
    for (int i = 0; i < len; i++) {
        if ((int)tmp[i] == (int)MinWord[i])
            continue;
        if ((int)tmp[i] < (int)MinWord[i])
            return true;
        else
            return false;
    }
}
 
int main() {
    cin >> word;
    while (word[len++] != '\0'){}
    len -= 1;
    for (int i = 0; i < len; i++)
        MinWord[i] = word[i];
    for (int a = 1; a < len - 1; a++) {
        for (int b = a + 1; b < len; b++) {
            int idx = 0;

            for (int i = a - 1; i >= 0; i--)
                tmp[idx++] = word[i];

            for (int i = b - 1; i >= a; i--)
                tmp[idx++] = word[i];

            for (int i = len - 1; i >= b; i--)
                tmp[idx++] = word[i];
 
            if (chkMin())
                for (int i = 0; i < len; i++)
                    MinWord[i] = tmp[i];
        }
    }
 
    for (int a = 0; a < len; a++)
        cout << MinWord[a];
    return 0;
}