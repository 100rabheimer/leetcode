class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long  wt=mass;
        sort(asteroids.begin(), asteroids.end());
        for(int asteroid:asteroids){
if(asteroid>wt){
    return false;
}
    wt+=asteroid;
        }
    return true;
    }
};