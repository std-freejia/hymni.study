#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string dir[3][3] = {{"NW", "W", "SW"}, {"N", "", "S"}, {"NE", "E", "SE"}};
int step[3][3][2] = {{{-1, -1}, {-1, 0}, {-1, 1}}, {{0, -1}, {0, 0}, {0, 1}}, {{1, -1}, {1, 0}, {1, 1}}};

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int dx = 0;
    int dy = 0;

    // game loop
    while (1)
    {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        
        cin >> remainingTurns; cin.ignore();

        dx = (lightX > initialTX) - (lightX < initialTX);
        dy = (lightY > initialTY) - (lightY < initialTY);

        if (dx == 0 && dy == 0)
        {
            break;
        }

        initialTX += step[dx + 1][dy + 1][0];
        initialTY += step[dx + 1][dy + 1][1];

        cout << dir[dx + 1][dy + 1] <<endl;
    }
}
