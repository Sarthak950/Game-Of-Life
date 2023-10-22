#include <cstdio>
#include <iostream>
#include <raylib.h>
#include <bits/stdc++.h>

//  Header File contains all the Structures and Functions
#include "Structures.h"


// Function to initialize the grid
void InitializeGrid(int** grid, int creature) {

    // clear grid 
    ClearGrid(grid);


    switch ( creature ) {

        case 1:
            SetRandom(grid, 0, 0);
            break;
        case 2:
            SetGlider(grid, 10, 10);
            break;
        case 3:
            SetPulsar(grid, 50, 100);
            break;
        case 4:
            SetGosperGliderGun(grid, 10, 10);
            break;
        case 5:
            SetReplicator(grid, 100, 100);
            break;
        case 6:
            SetExplorer(grid, 10, 10);
            break;
        case 7:
            SetBeacon(grid, 20 , 20);
            break;
        case 8:
            SetAcorn(grid, 120, 120);
            break;
    }

}

// Function to update the grid based on Conway's rules
void UpdateGrid(int** grid) {
    int** newGrid = (int**)malloc(gridSize * sizeof(int*));

    for (int i = 0; i < gridSize; i++) {
        newGrid[i] = (int*)malloc(gridSize * sizeof(int));

        for (int j = 0; j < gridSize; j++) {
            int neighbors = 0;

            // Count live neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int ni = (i + x + gridSize) % gridSize;
                    int nj = (j + y + gridSize) % gridSize;
                    neighbors += grid[ni][nj];
                }
            }

            // Apply Conway's rules
            if (grid[i][j]) {
                neighbors--; // Subtract the cell itself
                newGrid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                newGrid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    // Copy the new grid back to the original grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }

    // Free memory for the new grid
    for (int i = 0; i < gridSize; i++) {
        free(newGrid[i]);
    }
    free(newGrid);
}

int main() {

    
    int creature = 0;
    // clear the screen 
    system("clear");
    std::cout << "\033[31mred Enter what u Creature U want to Place\n" << std::endl;

    std::cout << "\033[0m1. Random" << std::endl;
    std::cout << "2. Glider" << std::endl;
    std::cout << "3. Pulsar" << std::endl;
    std::cout << "4. Gosper Glider Gun" << std::endl;
    std::cout << "5. Replicator" << std::endl;
    std::cout << "6. Explorer" << std::endl;
    std::cout << "7. Beacon" << std::endl;
    std::cout << "8. Acorn \n\nHere   ->   : ";

    std::cin >> creature;

    while ( creature < 1 || creature > 8 ) {
        std::cout << "Enter a valid Value\n :" << std::endl;
        std::cin >> creature;
    }


    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    // Initialize the grid and allocate memory
    int** grid = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        grid[i] = (int*)malloc(gridSize * sizeof(int));
    }

    InitializeGrid(grid, creature);

    SetTargetFPS(10);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Update the grid
        UpdateGrid(grid);

        // Render the grid
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (grid[i][j]) {
                    DrawRectangle(i * cellSize, j * cellSize, cellSize, cellSize, BLACK);
                }
            }
        }

        EndDrawing();
    }

    // Free memory for the grid
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);

    CloseWindow();

    return 0;
}

