package labb;

public class Obligatoriskuppgift2 {

	public static double Bisektris(double x, double y, double alfa) {

		{
			double p = 2 * x * y * Math.cos(alfa / 2);
			double bis = p / (x + y);
			return bis;
		}

	}
	

	public static double Area(double x, double y, double z) {

		double Area = Math.sqrt((So(x, y, z) * (So(x, y, z) - x) * ((So(x, y, z) - y) * ((So(x, y, z) - z)))));
		return Area;

	}

	public static double Omkrets(double x, double y, double z) {
		double Omkrets = (x + y + z);
		return Omkrets;
	}

	public static double So(double x, double y, double z) {
		double So = (x + y + z) / 2;
		return So;

	}

	public static double IRadie(double x, double y, double z) {
		double InnreRadie = (2 * (Area(x, y, z)) / Omkrets(x, y, z));
		return InnreRadie;

	}

	public static double YRadie(double x, double y, double z) {
		double YttreRadie = (x*y*z) / (Math.sqrt((x+y+z)*(y+z-x)*(x+z-y)*(x+y-z)));
		return YttreRadie;

	}
}
