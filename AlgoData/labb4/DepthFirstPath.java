//readme
//"author" Erik blondell
//generated sometime i cant remember
//the code DepthFirstPath.java from algorithms by sedgewick and wayne changes made to accomodate the function not using chars
//using symbol table and its key[]s function and st.get and further this instance is to find a single path and not all paths
//by using an if statement


public class DepthFirstPath {
    private boolean[] marked;
    private int[] edgeTo;
    private final int s;

    public DepthFirstPath(Graph G, int s) {
        this.s = s;
        edgeTo = new int[G.V()];
        marked = new boolean[G.V()];
        validateVertex(s);
        dfs(G, s);
    }

    private void dfs(Graph G, int v) {
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
        SymbolGraph SG = new SymbolGraph(args[0]," ");
        Graph G = SG.graph();
        //int s = Integer.parseInt(args[1]);
        String s = args[1];
        DepthFirstPath dfs = new DepthFirstPath(SG.graph, SG.st.get(s));

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
