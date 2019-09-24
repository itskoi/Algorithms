using System;

// Range query sum of A[start] + ... + A[end]
namespace SegmentTree
{
    // Segment Tree with array
    class ArraySegmentTree {
        // Private:
        private int[] tree;

        // Public:
        public ArraySegmentTree(int n) {
            tree = new int[n * 2 + 2];
            for (int i = 0; i <= n * 2 + 1; i++) {
                tree[i] = 0;
            }
        }
        public void updateIdx(int root, int left, int right, int idx, int val) {
            if (left == right) {
                tree[root] = val;
                return;
            }
            int mid = left + right >> 1;
            if (left <= idx && idx <= mid) {
                updateIdx(root * 2, left, mid, idx, val);
            }
            if (mid + 1 <= idx && idx <= right) {
                updateIdx(root * 2 + 1, mid + 1, right, idx, val);
            }
            tree[root] = tree[root * 2] + tree[root * 2 + 1];
        }
        public void updateRange(int root, int start, int end, int left, int right, int val) {
            if (left == right) {
                tree[root] += val;
                return;
            }
            if (left > end || right < start || left > right) return;
            int mid = left + right >> 1;
            updateRange(root * 2, start, end, left, mid, val);
            updateRange(root * 2 + 1, start, end, mid + 1, right, val);
            tree[root] = tree[root * 2] + tree[root * 2 + 1];
        }
        public int query(int root, int start, int end, int left, int right) {
            if (left > end || right < start || left > right) return 0;
            if (start <= left && right <= end) return tree[root];
            int mid = left + right >> 1;
            int l = query(root * 2, start, end, left, mid);
            int r = query(root * 2 + 1, start, end, mid + 1, right);
            return l + r;
        }
    }
    // Segment Tree with Node
    class Node {
        public int data;
        public int lazy;
        public Node left;
        public Node right;
        public Node() {
            left = right = null;
            data = lazy = 0;
        }
    }
    class NodeSegmentTree{
        // Private:
        private void updateLazy(Node root, int left, int right) {
            if (root.lazy == 0) return;
            root.data += (right - left + 1) * root.lazy;
            if (left != right) {
                root.left.lazy += root.lazy;
                root.right.lazy += root.lazy;
            }
            root.lazy = 0;
        }
        // Public:
        public void updateIdx(Node root, int left, int right, int idx, int val) {
            if (left == right) {
                root.data = val;
                return;
            }
            int mid = left + right >> 1;

            if (root.left == null) root.left = new Node();
            if (root.right == null) root.right = new Node();
            if (left <= idx && idx <= mid) {
                updateIdx(root.left, left, mid, idx, val);
            }
            if (mid + 1 <= idx && idx <= right) {
                updateIdx(root.right, mid + 1, right, idx, val);
            }
            root.data = root.left.data + root.right.data;
        }
        public void updateRange(Node root, int start, int end, int left, int right, int val) { 
            updateLazy(root, left, right);
            if (left > right || left > end || right < start) return;
            if (start <= left && right <= end) {
                root.data += (right - left + 1) * val;
                if (left != right) {
                    root.left.lazy += val;
                    root.right.lazy += val;
                }
                return;
            }
            int mid = left + right >> 1;
            updateRange(root.left, start, end, left, mid, val);
            updateRange(root.right, start, end, mid + 1, right, val);
            root.data = root.left.data + root.right.data;
        }
        public int query(Node root, int start, int end, int left, int right) {
            updateLazy(root, left, right);
            if (left > right || left > end || right < start) return 0;
            if (start <= left && right <= end) return root.data;
            int mid = left + right >> 1;
            int l = query(root.left, start, end, left, mid);
            int r = query(root.right, start, end, mid + 1, right);
            return l + r;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            try {
                NodeSegmentTree smt = new NodeSegmentTree();
                Node root = new Node();
                smt.updateIdx(root, 1, 5, 1, 1);
                smt.updateIdx(root, 1, 5, 2, 2);
                smt.updateIdx(root, 1, 5, 3, 3);
                smt.updateIdx(root, 1, 5, 4, 4);
                smt.updateIdx(root, 1, 5, 5, 5);
                smt.updateRange(root, 1, 3, 1, 5, 3);
                Console.WriteLine(smt.query(root, 1, 5, 1, 5));
            } catch(Exception e) {
                Console.WriteLine(e.GetType().FullName);
            }
        }
    }
}
