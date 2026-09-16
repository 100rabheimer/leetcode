class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int cols=image[0].size();
        int original=image[sr][sc];

        if(original==color){
            return image;

        }
        queue<pair<int,int>>q;
        image[sr][sc]=color;
        q.push({sr,sc});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            int r=curr.first;
            int c=curr.second;
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                if(nx>=0 && ny>=0 && nx<row && ny<cols){
                    if(image[nx][ny]==original){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                    }
                }
            }
        }
        return image;
    }
};