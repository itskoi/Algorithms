using System;
using System.Collections.Generic;

namespace DFS {
    class Graph {
        // Variables
        private List<int>[] adj = new List<int>[101010];
        private bool[] free = new bool[101010];
        private int result = 0;
        // Functions:
        
        public Graph() {
            for (int i = 0; i <= 100000; i++) {
                adj[i] = new List<int>();
                free[i] = true;
            }
        }
        public void addEdge(int u, int v) {
            adj[u].Add(v);
            adj[v].Add(u);
        }
        public void DFS(int u, int des) {
            free[u] = false;
            if (u != des) result++;
            foreach(var v in adj[u]) {
                if (free[v]) {
                    DFS(v, des);
                }
            }
        }
        public int getResult {
            get { return this.result; }
        }
    }
    class Program {
        static void Main(string[] args) {
            Graph graph = new Graph();
            string str = Console.ReadLine();
            int N = Int32.Parse(str.Split(' ')[0]);
            int M = Int32.Parse(str.Split(' ')[1]);
            for (int i = 0; i < M; i++) {
                str = Console.ReadLine();
                int u = Int32.Parse(str.Split(' ')[0]);
                int v = Int32.Parse(str.Split(' ')[1]);
                graph.addEdge(u, v);
            }
            int x = Int32.Parse(Console.ReadLine());
            graph.DFS(x, x);
            Console.WriteLine(N - graph.getResult - 1);
        }
    }
}
