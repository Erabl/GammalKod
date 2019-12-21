package labb;

import java.util.Scanner;

public class TestförOU2_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("ange triangelns sidor");

		Scanner in = new Scanner(System.in);

		double x = in.nextInt();
		double y = in.nextInt();
		double z = in.nextInt();

		System.out.println("Innre Rade" + Obligatoriskuppgift2.IRadie(x, y, z));

		System.out.println("Yttre Radie" + Obligatoriskuppgift2.YRadie(x, y, z));

		System.out.println("Area" + Obligatoriskuppgift2.Area(x, y, z));

		System.out.println("Omkrets" + Obligatoriskuppgift2.Omkrets(x, y, z));

	}

}