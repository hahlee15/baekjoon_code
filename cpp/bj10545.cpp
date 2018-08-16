#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int> keypad;
char message[100];

int originalKey(char c){
    switch(c){
        case 'a':
            return 21;
        case 'b':
            return 22;
        case 'c':
            return 23;
        case 'd':
            return 31;
        case 'e':
            return 32;
        case 'f':
            return 33;
        case 'g':
            return 41;
        case 'h':
            return 42;
        case 'i':
            return 43;
        case 'j':
            return 51;
        case 'k':
            return 52;
        case 'l':
            return 53;
        case 'm':
            return 61;
        case 'n':
            return 62;
        case 'o':
            return 63;
        case 'p':
            return 71;
        case 'q':
            return 72;
        case 'r':
            return 73;
        case 's':
            return 74;
        case 't':
            return 81;
        case 'u':
            return 82;
        case 'v':
            return 83;
        case 'w':
            return 91;
        case 'x':
            return 92;
        case 'y':
            return 93;
        case 'z':
            return 94;
    }
}
void key(){
    int idx = 0;
    int temp = 0;
    int pretemp = 0;
    int orgNum = 0;
    while(message[idx] != '\0'){
        pretemp = temp;
        temp = originalKey(message[idx++]);
        if(pretemp != 0 && temp != 0 &&(pretemp / 10 == temp / 10))
            printf("#");
        for(int i = 0; i < (temp % 10); i++)
            printf("%d", keypad[temp/10]);
    }
    return;
}
int main(void){
    keypad.assign(10, 0);
    int temp = 0;
    for(int i = 1; i <= 9; i++){
        scanf("%d", &temp);
        keypad[temp] = i;
    }

    std::cin>>message;

    key();
    
    return 0;
}