#pragma once

const int screenWidth = 1000;
const int screenHeight = 1000;
const int gridSize = 250;
const int cellSize = 4;

void SetGlider(int** grid, int x, int y) {
    int glider[3][3] = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[x + i][y + j] = glider[i][j];
        }
    }
}

void SetExplorer (int** grid, int x, int y) {
    std::vector<std::pair<int, int>> explorer = {
        {1, 3},
        {2, 2}, {2, 4},
        {3, 1}, {3, 5},
        {4, 2}, {4, 4},
        {5, 3}
    };
    for (auto& p : explorer) {
        grid[x + p.first][y + p.second] = 1;
    }
}

void SetAcorn (int** grid, int x, int y) {
    std::vector<std::pair<int, int>> acorn = {
        {1, 2},
        {2, 4},
        {3, 1}, {3, 2}, {3, 5}, {3, 6}, {3, 7}
    };
    for (auto& p : acorn) {
        grid[x + p.first][y + p.second] = 1;
    }
}
void  SetBeacon (int** grid, int x, int y) {
    std::vector<std::pair<int, int>> beacon = {
        {1, 1}, {1, 2},
        {2, 1},
        {3, 4},
        {4, 3}, {4, 4}
    };
    for (auto& p : beacon) {
        grid[x + p.first][y + p.second] = 1;
    }
}


void SetReplicator(int** grid, int x, int y) {
    std::vector<std::pair<int, int>> replicator = {
        {3, 1}, {3, 2}, {3, 4}, {3, 5}, {3, 6}, {3, 8}, {3, 9}, {3, 11},
        {4, 1}, {4, 6}, {4, 11},
        {5, 1}, {5, 3}, {5, 4}, {5, 6}, {5, 8}, {5, 9}, {5, 11},
        {7, 1}, {7, 3}, {7, 4}, {7, 6}, {7, 8}, {7, 9}, {7, 11},
        {8, 1}, {8, 6}, {8, 11},
        {9, 1}, {9, 2}, {9, 4}, {9, 5}, {9, 6}, {9, 8}, {9, 9}, {9, 11}
    };
    for (auto& p : replicator) {
        grid[x + p.first][y + p.second] = 1;
    }
}

void SetPulsar(int** grid, int x, int y) {
    int pulsar[13][13] = {
        {0,0,0,0,1,0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0,0,1,0,0,0},
        {0,0,0,0,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,0,0},
        {1,1,1,1,0,1,1,0,1,0,1,1,1},
        {0,0,1,0,0,0,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0}
    };

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            grid[x + i][y + j] = pulsar[i][j];
        }
    }
}

void SetRandom(int** grid, int x, int y) {
    // For ramdomized grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = GetRandomValue(0, 1); // Initialize cells randomly
        }
    }
}

void SetGosperGliderGun(int** grid, int x, int y) {

    std::vector<std::pair<int, int>> gosperGliderGun = {
        {1, 5}, {1, 6}, {2, 5}, {2, 6},
        {11, 5}, {11, 6}, {11, 7}, {12, 4}, {12, 8}, {13, 3}, {13, 9},
        {14, 3}, {14, 9}, {15, 6}, {16, 4}, {16, 8}, {17, 5}, {17, 6}, {17, 7},
        {18, 6},
        {21, 3}, {21, 4}, {21, 5}, {22, 3}, {22, 4}, {22, 5},
        {23, 2}, {23, 6},
        {25, 1}, {25, 2}, {25, 6}, {25, 7},
        {35, 3}, {35, 4}, {36, 3}, {36, 4}
    };

    for (auto& p : gosperGliderGun) {
        grid[x + p.first][y + p.second] = 1;
    }
}


void ClearGrid(int** grid) {
    // Clear grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = 0;
        }
    }
}

