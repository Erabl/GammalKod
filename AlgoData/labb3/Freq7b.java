public class Freq7b {

	// Do not instantiate.
	private Freq7b() {
	}

  public static void main(String[] args) {
  int distinct = 0, words = 0;
  int minlen = Integer.parseInt(args[0]);
    LinearProbingHashST<String, Integer> st = new LinearProbingHashST<String, Integer>();

  // compute frequency counts
  while (!StdIn.isEmpty()) {
    String key = StdIn.readString();
    if (key.length() < minlen)
      continue;
    words++;
    if (st.contains(key)) {
      st.put(key, st.get(key) + 1);
    } else {
      st.put(key, 1);
      distinct++;
    }
  }
  long startTime = System.nanoTime();
  // find a key with the highest frequency count
  String max = "";
  // for(int i = 0;i < n;i++){
  //max = "";
  st.put(max, 0);
  for (String word : st.keys()) {
    if (st.get(word) > st.get(max))
      max = word;

 }
 long estimatedTime = System.nanoTime() - startTime;
       StdOut.println(max + " " + st.get(max));
       StdOut.println("time" +" "+ estimatedTime + "ns");
}
}
