#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 1, -1};
int dy[4] = {1, 1, -1, -1};

int dx1[4] = {1, -1, -1, 1};
int dy1[4] = {1, 1, -1, -1};


void tiltedRectangleRotation(int n, vector<vector<int>>& matrix, int r, int c, int m1, int m2, int m3, int m4, int dir) {

    int row = r - 1;
    int col = c - 1;

    int topX = col + m1 - m2, topY = row - m1 - m2;
    int bottomX = col, bottomY = row;
    int leftX = col - m4, leftY = row - m4;
    int rightX = col + m1, rightY = row - m1;

    int tempBottomX = bottomX, tempBottomY = bottomY;

    if (dir == 0) {
        

        int temp = matrix[row][col];

        for (int leftRight = bottomX; leftRight > leftX; leftRight--) {
            int ny = dy[3] + bottomY;
            int nx = dx[3] + bottomX;

            matrix[bottomY][bottomX] = matrix[ny][nx];
            bottomY = ny;
            bottomX = nx;
        }

        for (int upLeft = leftX; upLeft < topX; upLeft++) {
            int ny = dy[2] + leftY;
            int nx = dx[2] + leftX;

            matrix[leftY][leftX] = matrix[ny][nx];
            leftY = ny;
            leftX = nx;
        }

        for (int rightUp = topX; rightUp < rightX; rightUp++) {
            int ny = dy[1] + topY;
            int nx = dx[1] + topX;

            matrix[topY][topX] = matrix[ny][nx];
            topY = ny;
            topX = nx;
        }

        for (int bottomRight = rightX; bottomRight > tempBottomX; bottomRight--) {

            int ny = dy[0] + rightY;
            int nx = dx[0] + rightX;

            matrix[rightY][rightX] = matrix[ny][nx];

            rightY = ny;
            rightX = nx;
           
        }

        matrix[row - 1][col + 1] = temp;
    }

    else {

        int temp = matrix[row][col];

        for (int rightBottom = bottomX; rightBottom < rightX; rightBottom++) {
            int ny = dy1[3] + bottomY;
            int nx = dx1[3] + bottomX;

            matrix[bottomY][bottomX] = matrix[ny][nx];
            bottomY = ny;
            bottomX = nx;
        }

        for (int topRight = rightX; topRight > topX; topRight--) {
            int ny = dy1[2] + rightY;
            int nx = dx1[2] + rightX;

            matrix[rightY][rightX] = matrix[ny][nx];
            rightY = ny;
            rightX = nx;
        }

        for (int leftTop = topX; leftTop > leftX; leftTop--) {
            int ny = dy1[1] + topY;
            int nx = dx1[1] + topX;

            matrix[topY][topX] = matrix[ny][nx];
            topY = ny;
            topX = nx;
        }

        for (int bottomLeft = leftX; bottomLeft < tempBottomX; bottomLeft++) {
            int ny = dy1[0] + leftY;
            int nx = dx1[0] + leftX;

            matrix[leftY][leftX] = matrix[ny][nx];
            leftY = ny;
            leftX = nx;
        }

        matrix[row - 1][col - 1] = temp;
    }
}

int main() {
    int n, r, c, m1, m2, m3, m4, dir;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    tiltedRectangleRotation(n, matrix, r, c, m1, m2, m3, m4, dir);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}