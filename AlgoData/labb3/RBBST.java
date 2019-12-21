
//README
//the code from Frequencycounter.java from algorthms by sedgewick and Wayne modified to handle red black trees
public class RBBST {

	// // Do not instantiate.
	// private FrequencyCounter() {
	// }

	/**
	 * Reads in a command-line integer and sequence of words from standard input and
	 * prints out a word (whose length exceeds the threshold) that occurs most
	 * frequently to standard output. It also prints out the number of words whose
	 * length exceeds the threshold and the number of distinct such words.
	 *
	 * @param args the command-line arguments
	 */
	public static void main(String[] args) {
		int distinct = 0, words = 0;
		int minlen = Integer.parseInt(args[0]);
		RedBlackLiteBST<String, Integer> st = new RedBlackLiteBST<String, Integer>();

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
				        // StdOut.println("distinct = " + distinct);
				        // StdOut.println("words    = " + words);

 }
   // for(int j = 0; j<k; j++){
   //   max = "";
   //   st.put(max, 0);
   //   for (String word : st.keys()) {
   //     if (st.get(word) > st.get(max))
   //       max = word;
   //
   //       StdOut.println(max + " " + st.get(max));
   //       StdOut.println("distinct = " + distinct);
   //       StdOut.println("words    = " + words);
   //     }
   //   }
 }
