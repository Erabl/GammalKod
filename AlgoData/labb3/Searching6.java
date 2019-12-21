import java.util.*;
//README
//AUTHOR Erik Blondell
//Given a word, this program will find at which idex in "the text" said word is located and then print its index aswell as all other occurances of the word
public class Searching6 {

//function to run through the text and add to a counter each time the

	public static void main(String[] args) {
		String sökord = args[0];
		int IndexCount= 0;
	  StdOut.println(sökord + " "+ "finns på platserna");
		while(!StdIn.isEmpty()){
		//	 StdOut.println("bajs i while loopen");
			if(sökord.equals(StdIn.readString())){
				StdOut.println(IndexCount);
				IndexCount++;
			}
			else{IndexCount++;}
		}
	}

}
