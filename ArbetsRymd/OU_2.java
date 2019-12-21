package labb;

import java.util.Locale;
import java.util.Scanner;

public class OU_2 {

	public static void main(String[] args) {
		System.out.println("Triangel info");
		// inmatningsverktyg=Scanner
		Scanner in = new Scanner(System.in);
		in.useLocale(Locale.US);

		// triangelns sidor
		System.out.println("Sidor: ");
		int Sidor = in.nextInt();
		// skapa array/vektor
		double[] t = new double[Sidor + 1];
		// ange sidornas värden
		for (int Sida = 1; Sida <= Sidor; Sida++) {
			System.out.println("Ange sidor" + Sida + ":");
			t[Sida] = in.nextDouble();

		}
	//	System.out.println();
		//display.sidor
	//	System.out.println("Sidorna");
	//	for(int Sida =1; Sida<= Sidor; Sida++)
	//		System.out.println(t[sidor]+ "");
		
		
		//hitta triangelns:
		//Area
		//Bisektriser för ab bc ca
		//radier i cirklarna utan och innan triangeln som anges av formlerna nedan
		//
		

	}

	public static double bisektris(double b, double c, double alfa) {

		{
			double p = 2 * b * c * Math.cos(alfa / 2);
			double bis = p / (b + c);
			return bis;
		}

	}

}
