class Solution {
public:

    int m, n;

    // 4 directions: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<vector<int>> fireTime;

    // Check karta hai ki 'wait' minutes wait karne ke baad
    // person safehouse tak safely pahunch sakta hai ya nahi
    bool canEscape(int wait, vector<vector<int>>& grid) {

        queue<pair<int,int>> q;  
        // Person ke coordinates ke liye BFS queue

        vector<vector<int>> personTime(m, vector<int>(n, -1));
        // Person kis cell par kis time pahucha
        // -1 = abhi visit nahi hua

        q.push({0, 0});
        // Person starting point

        personTime[0][0] = wait;
        // Wait karne ke baad person start karega

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();
            // Current cell nikala

            for(int k = 0; k < 4; k++) {
                // 4 directions check

                int nx = x + dx[k];
                int ny = y + dy[k];
                // Next cell

                // Boundary check
                // Wall check
                // Already visited check
                if(nx >= 0 && nx < m &&
                   ny >= 0 && ny < n &&
                   grid[nx][ny] != 2 &&
                   personTime[nx][ny] == -1) {

                    int nextTime = personTime[x][y] + 1;
                    // Next cell par person 1 minute baad pahuchega

                    // Check if next cell is safehouse
                    if(nx == m-1 && ny == n-1) {

                        // Safehouse par person aur fire
                        // same time aa sakte hain
                        if(fireTime[nx][ny] == -1 ||
                           nextTime <= fireTime[nx][ny]) {

                            return true;
                            // Safehouse safely reach kar liya
                        }

                    }
                    else {

                        // Normal cell mein person ko
                        // fire se strictly pehle pahunchna hai
                        if(fireTime[nx][ny] == -1 ||
                           nextTime < fireTime[nx][ny]) {

                            personTime[nx][ny] = nextTime;
                            // Arrival time store

                            q.push({nx, ny});
                            // Next BFS exploration
                        }
                    }
                }
            }
        }

        return false;
        // Safehouse tak nahi pahunch paye
    }


    int maximumMinutes(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        fireTime = vector<vector<int>>(m, vector<int>(n, -1));
        // Har cell par fire kitne minute mein aayegi
        // -1 = fire kabhi nahi aayegi

        queue<pair<int,int>> q;

        // ---------------- FIRE BFS ----------------

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    q.push({i, j});
                    // Saare fire cells starting points

                    fireTime[i][j] = 0;
                    // Starting fire ka time = 0
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                // Valid cell + wall nahi + fire already nahi pahuchi
                if(nx >= 0 && nx < m &&
                   ny >= 0 && ny < n &&
                   grid[nx][ny] != 2 &&
                   fireTime[nx][ny] == -1) {

                    fireTime[nx][ny] = fireTime[x][y] + 1;
                    // Fire current cell se 1 minute baad next cell par

                    q.push({nx, ny});
                    // Next fire expansion
                }
            }
        }


        // ---------------- BINARY SEARCH ----------------

        int low = 0;
        int high = 1e9;
        int ans = -1;

        // Maximum waiting time find karna hai
        while(low <= high) {

            int mid = low + (high - low) / 2;
            // Current waiting time try kar rahe hain

            if(canEscape(mid, grid)) {
                // Agar itna wait karke escape possible hai

                ans = mid;
                // Answer ko update karo

                low = mid + 1;
                // Aur zyada wait try karo
            }
            else {

                high = mid - 1;
                // Itna wait possible nahi
                // Kam waiting time try karo
            }
        }

        return ans;
    }
};