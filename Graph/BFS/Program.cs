using System;
using System.Collections.Generic;

namespace BFS {
    class Pair<T, P> {
        public Pair(T first, P second) {
            this.first = first;
            this.second = second;
        }
        public T first {
            get; set;
        }

        public P second {
            get; set;
        }

    }
    class Graph {
        // Variables:
        private Queue<int> queue = new Queue<int>();
        private List<Pair<int, int>>[] adj = new List<Pair<int, int>>[101010];
        private int[] level = new int[101010];
        // Functions
        public Graph() {
            for (int i = 0; i < 101010; i++) {
                level[i] = 0;
                adj[i] = new List<Pair<int, int>>();
            }
        }
        public void addEdge(int u, int v, int d = 0) {
            adj[u].Add(new Pair<int, int>(v, d));
            adj[v].Add(new Pair<int, int>(u, d));
        }

        public void BFS(int x) {
            int result = 0;
            queue.Enqueue(1);
            level[1] = 1;
            while (queue.Count > 0) {
                int u = queue.Dequeue();
                foreach (var it in adj[u]) {
                    int v = it.first;
                    if (level[v] == 0) {
                        queue.Enqueue(v);
                        level[v] = level[u] + 1;
                        if (level[v] == x) {
                            result++;
                        }
                    }
                }
            }
            Console.WriteLine(result);
        }
    }
    class Program {
        static void Main(string[] args) {
            Graph graph = new Graph();
            int N = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < N - 1; i++) {
                string str = Console.ReadLine();
                int u = Int32.Parse(str.Split(' ')[0]);
                int v = Int32.Parse(str.Split(' ')[1]);
                graph.addEdge(u, v);
            }
            int x = Int32.Parse(Console.ReadLine());
            graph.BFS(x);
        }
    }
}
