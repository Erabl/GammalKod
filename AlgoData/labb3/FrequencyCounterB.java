//README
//From Algorithms 4e by Sedgewick and Wayne
public class FrequencyCounterB {

	// Do not instantiate.
	private FrequencyCounterB() {
	}

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
		BinarySearchST<String, Integer> st = new BinarySearchST<String, Integer>();

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







// /******************************************************************************
//  *  Compilation:  javac ST.java
//  *  Execution:    java ST < input.txt
//  *  Dependencies: StdIn.java StdOut.java
//  *  Data files:   https://algs4.cs.princeton.edu/35applications/tinyST.txt
//  *
//  *  Sorted symbol table implementation using a java.util.TreeMap.
//  *  Does not allow duplicates.
//  *
//  ******************************************************************************/
//
// import java.util.Iterator;
// import java.util.NoSuchElementException;
// import java.util.TreeMap;
//
// /**
//  *  The {@code ST} class represents an ordered symbol table of generic
//  *  key-value pairs.
//
//  *  @author Robert Sedgewick
//  *  @author Kevin Wayne
//  *
//  *  @param <Key> the generic type of keys in this symbol table
//  *  @param <Value> the generic type of values in this symbol table
//  */
// public class ST<Key extends Comparable<Key>, Value> implements Iterable<Key> {
//
//     private TreeMap<Key, Value> st;
//
//     /**
//      * Initializes an empty symbol table.
//      */
//     public ST() {
//         st = new TreeMap<Key, Value>();
//     }
//     public Value get(Key key) {
//         if (key == null) throw new IllegalArgumentException("calls get() with null key");
//         return st.get(key);
//     }
//     public void put(Key key, Value val) {
//         if (key == null) throw new IllegalArgumentException("calls put() with null key");
//         if (val == null) st.remove(key);
//         else             st.put(key, val);
//     }
//     public void delete(Key key) {
//         if (key == null) throw new IllegalArgumentException("calls delete() with null key");
//         st.remove(key);
//     }
//     public boolean contains(Key key) {
//         if (key == null) throw new IllegalArgumentException("calls contains() with null key");
//         return st.containsKey(key);
//     }
//     public int size() {
//         return st.size();
//     }
//     public boolean isEmpty() {
//         return size() == 0;
//     }
//     public Iterable<Key> keys() {
//         return st.keySet();
//     }
//     public Iterator<Key> iterator() {
//         return st.keySet().iterator();
//     }

//     public Key min() {
//         if (isEmpty()) throw new NoSuchElementException("calls min() with empty symbol table");
//         return st.firstKey();
//     }
//     public Key max() {
//         if (isEmpty()) throw new NoSuchElementException("calls max() with empty symbol table");
//         return st.lastKey();
//     }
//     public Key ceiling(Key key) {
//         if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
//         Key k = st.ceilingKey(key);
//         if (k == null) throw new NoSuchElementException("all keys are less than " + key);
//         return k;
//     }
//     public Key floor(Key key) {
//         if (key == null) throw new IllegalArgumentException("argument to floor() is null");
//         Key k = st.floorKey(key);
//         if (k == null) throw new NoSuchElementException("all keys are greater than " + key);
//         return k;
//     }
//     public static void main(String[] args) {
//         ST<String, Integer> st = new ST<String, Integer>();
//         for (int i = 0; !StdIn.isEmpty(); i++) {
//             String key = StdIn.readString();
//             st.put(key, i);
//         }
//         for (String s : st.keys())
//             StdOut.println(s + " " + st.get(s));
//     }
//
// }
