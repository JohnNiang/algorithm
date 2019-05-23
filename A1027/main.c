#include <stdio.h>
#include <stdlib.h>

// A1027: Colors in Mars
// <https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768>

char digitMap[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void convertColor(int color, char result[2]) {
    int k = 0;
    while(color >= 13) {
        result[k++] = digitMap[color % 13];
        color /= 13;
    }

    result[k] = digitMap[color];

    for(int i = k + 1; i < 2; i++) {
        result[i] = '0';
    }
}

void printColor(char convertedColor[2]) {
    for(int i = 1; i >= 0; i--) {
        printf("%c", convertedColor[i]);
    }
}

int main() {
    // Input three decimal digits
    int red = 0;
    int green = 0;
    int blue = 0;

    scanf("%d %d %d", &red, &green, &blue);
//    printf("Red: %d, Green: %d, Blue: %d\n", red, green, blue);

    char convertedRed[2];
    char convertedGreen[2];
    char convertedBlue[2];

    convertColor(red, convertedRed);
    convertColor(green, convertedGreen);
    convertColor(blue, convertedBlue);

    printf("#");
    printColor(convertedRed);
    printColor(convertedGreen);
    printColor(convertedBlue);

    return 0;
}
