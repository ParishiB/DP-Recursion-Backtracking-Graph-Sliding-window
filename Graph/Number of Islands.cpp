  void solve(vector<vector<char>>& grid, int i , int j , int n , int m){
        if(i < 0 || j < 0 || j >= m || i >= n || grid[i][j] != 1){
            return;
        }
        solve(grid,i+1,j,n,m);
        solve(grid,i,j+1,n,m);
        solve(grid,i+1,j+1,n,m);
        solve(grid,i+1,j-1,n,m);
        solve(grid,i-1,j-1,n,m);
        solve(grid,i-1,j,n,m);
        solve(grid,i,j-1,n,m);
        solve(grid,i-1,j+1,n,m);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if( n == 0)return 0;
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == '1'){
                    solve(grid,i,j,n,m);
                    ans++;
                }
            }
        }
        
        return ans;
    }
