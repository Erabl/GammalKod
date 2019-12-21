package labb;

public class labb2_4 {

	public static void main(String[] args) {

		System.out.println("KOSTNAD");
		System.out.println();
		
		// inmatningsverktyg
		java.util.Scanner in = new java.util.Scanner(System.in);
		in.useLocale(java.util.Locale.US);
		
		// mata in uppgifter om antalet böcker och deras pris
		System.out.print("Antalet bocker: ");
		int antal = in.nextInt();
		
		System.out.print("Pris pa bockerna: ");
		double pris = in.nextDouble();
		
		// beräkna den totala kostnaden
		double kostnad = antal * pris;
		
		// visa resultatet
		System.out.println("Den totala kostnaden: " + kostnad);

	}

	/*----------------------------------------------------------------------
	 * Programmets input och output vid en exekveringKOSTNADAntalet bocker: 25Pris pa bockerna: 50Den totala kostnaden: 1250.0Programmets input och output vid en annan exekvering
	 */
//KOSTNADAntalet bocker: 47Pris pa bockerna: 230Den totala kostnaden: 10810.0

//----------------------------------------------------------------------*/

}