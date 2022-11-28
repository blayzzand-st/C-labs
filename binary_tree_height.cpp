#include <iostream>

int height(int (*arr)[3], int next) {
    int l = arr[next][1];
    int r = arr[next][2];

    if (l == -1 && r == -1)
        return 1;
    else if (l == -1)
        return 1 + height(arr, r);
    else if (r == -1)
        return 1 + height(arr, l);
    else
        return std::max(height(arr, l), height(arr, r)) + 1;
}

int main() {
    int n;
    std::cin >> n;
    int top[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> top[i][j];
        }
        top[i][1]--;
        top[i][2]--;
    }

    if (n == 0)
        std::cout << "0";
    else
        std::cout << height(top, 0);

    return 0;
}