using System;

class FloodFill {
    static bool result;
    static bool DFS(int x, int y, int n, int m, bool[,] adj, bool[,] visited) {
        if (x == m && y == n) return true;
        if (visited[x, y] == true) return false;
        visited[x, y] = true;
        result = false;
        //
        if (x + 1 <= m && adj[x + 1, y] == true) {
            result = DFS(x + 1, y, n, m, adj, visited);
            if (result == true) return result;
        }
        if (x - 1 >= 1 && adj[x - 1, y] == true) {
            result = DFS(x - 1, y, n, m, adj, visited);
            if (result == true) return result;
        }
        if (y - 1 >= 1 && adj[x, y - 1] == true) {
            result = DFS(x, y - 1, n, m, adj, visited);
            if (result == true) return result;
        }
        if (y + 1 <= n && adj[x, y + 1] == true) {
            result = DFS(x, y + 1, n, m, adj, visited);
        }
        return result;
    }
    static void Main(string[] agrs) {
        // Initialize
        bool[,] adj = new bool[101, 101];
        bool[, ] visited = new bool[101, 101];
        int n, m;
        string str;

        // Read n, m
        str = Console.ReadLine();
        n = Convert.ToInt32(str.Split(' ')[0]);
        m = Convert.ToInt32(str.Split(' ')[1]);

        // Read grid
        for (int i = 1; i <= m; i++) {
            str = Console.ReadLine();
            for (int j = 1; j <= n; j++) {
                visited[i, j] = false;
                string x = str.Split(' ')[j - 1];
                if (x == "1") {
                    adj[i, j] = true;
                } else {
                    adj[i, j] = false;
                }
            }
        }

        // 
        if (DFS(1, 1, n, m, adj, visited) == true) {
            Console.WriteLine("Yes");
        } else {
            Console.WriteLine("No");
        }
    }
}