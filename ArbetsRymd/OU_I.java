package labb;

import java.util.*;

class OU_I {
	public static void main(String[] args) {

		System.out.println("TEMPERATURER\n");

		// inmatningsverktygScanner
		Scanner in = new Scanner(System.in);
		in.useLocale(Locale.US);

		// antalet veckor och antaletmätningar
		System.out.print("antalet veckor: ");
		int antalVeckor = in.nextInt();

		System.out.print("antalet mätningar per vecka: ");
		int antalMatningarPerVecka = in.nextInt();

		// plats att lagra temperaturer
		double[][] t = new double[antalVeckor + 1][antalMatningarPerVecka + 1];

		// mata in temperaturerna
		for (int vecka = 1; vecka <= antalVeckor; vecka++) {
			System.out.println("temperaturer -vecka " + vecka + ":");

			for (int matning = 1; matning <= antalMatningarPerVecka; matning++) {
				t[vecka][matning] = in.nextDouble();
			}
		}
		System.out.println();
		// visa temperaturerna
		System.out.println("temperaturerna:");
		for (int vecka = 1; vecka <= antalVeckor; vecka++) {

			for (int matning = 1; matning <= antalMatningarPerVecka; matning++)
				System.out.print(t[vecka][matning] + " ");
			System.out.println();
		}

		// den minsta,den största och medeltemperaturen–veckovis
		double[] minT = new double[antalVeckor + 1];
		double[] maxT = new double[antalVeckor + 1];

		double sumT = 0;
		double[] medelT = new double[antalVeckor + 1];
		double[] summorT = new double[antalVeckor];

		// koden ska skrivas här
		// visa den minsta, den största och medeltemperaturen för varje vecka
		// koden ska skrivas här
		// den minsta, den största och medeltemperaturen -helamätperioden//

		for (int i = 1; i < t.length; i++) {

			maxT[i] = t[i][1];
			sumT = 0;
			minT[i] = t[i][1];

			for (int j = 1; j < t[i].length; j++) {
				if (t[i][j] > maxT[i]) {
					maxT[i] = t[i][j];
				}

				sumT += t[i][j];
			}
			medelT[i] = sumT / (t[i].length - 1);

			for (int j = 1; j < t[i].length; j++) {
				if (t[i][j] < minT[i])
					minT[i] = t[i][j];

			}
			System.out.println("Vecka " + i);
			System.out.println("Största temperaturen: " + maxT[i]);
			System.out.println("Medel temperaturen: " + medelT[i]);
			System.out.println("Minsta temperaturen: " + minT[i]);
			System.out.println("Sammanlagda temperaturen: " + sumT);
			System.out.println();

			summorT[i - 1] = sumT;

		}
		double totsum = 0;
		double totmin = minT[1];
		double totmax = maxT[1];

		for (int i = 0; i < summorT.length; i++) {

			totsum += summorT[i];

		}
		for (int i = 1; i < t.length; i++) {
			if (maxT[i] > totmax) {
				totmax = maxT[i];
			}
			if (minT[i] < totmin) {
				totmin = minT[i];
			}

		}
		System.out.println("Medelvärde för hela mätperioden " + (totsum / (antalMatningarPerVecka * antalVeckor)));
		System.out.println("Största värdet för hela mätperioden " + totmax);
		System.out.println("Minsta värdet för hela mätperioden " + totmin);

	}

	// double minTemp = minT[1];
	// double maxTemp = maxT[1];
	// double sumTemp = 0;
	// double medelTemp = 0;

	// koden ska skrivas här
	// visa den minsta, den största och medeltemperaturen i hela mätperioden
	// koden ska skrivas här
}
