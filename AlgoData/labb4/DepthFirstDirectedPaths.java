//readme
//DepthFirstDirectedPaths.java form algorithms by sedgewick and wayneby sedgewick and wayne like depthfirstpath but in a directed path
public class DepthFirstDirectedPaths {
    private boolean[] marked;  // marked[v] = true iff v is reachable from s
    private int[] edgeTo;      // edgeTo[v] = last edge on path from s to v
    private final int s;       // source vertex

    public DepthFirstDirectedPaths(Digraph G, int s) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        validateVertex(s);
        dfs(G, s);
    }

    private void dfs(Digraph G, int v) {
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, w);
            }
        }
    }
    public boolean hasPathTo(int v) {
        validateVertex(v);
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v) {
        validateVertex(v);
        if (!hasPathTo(v)) return null;
        Stack<Integer> path = new Stack<Integer>();
        for (int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }
    private void validateVertex(int v) {
        int V = marked.length;
        if (v < 0 || v >= V)
            throw new IllegalArgumentException("vertex " + v + " is not between 0 and " + (V-1));
    }

    public static void main(String[] args) {
        In in = new In(args[0]);
        SymbolDigraph SG = new SymbolDigraph(args[0]," ");

        Digraph G = SG.digraph();
        //int s = Integer.parseInt(args[1]);
        String s = args[1];
        DepthFirstDirectedPaths dfs = new DepthFirstDirectedPaths(G, SG.st.get(s));

        String reachNode = args[2];

        for (int v = 0; v < G.V(); v++) {
          if(SG.keys[v].equals(reachNode)){
            if (dfs.hasPathTo(v)) {
                StdOut.printf("%s to %s:  ", s, SG.keys[v]);
                for (int x : dfs.pathTo(v)) {

                    if (SG.nameOf(x) == s) StdOut.print(SG.keys[x]);
                    else StdOut.print("-" + SG.keys[x]);

              }
                StdOut.println();
           }
            else {
                StdOut.printf("%s to %d:  not connected\n", s, v    );
            }

        }
    }
  }
}
