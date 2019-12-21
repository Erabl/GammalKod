package labb;

public class Labb2_4_esque {


	public static void main(String[] args) {
		// TODO Auto-generated method stub
System.out.println ("Area rektangel");

    java.util.Scanner in = new java.util.Scanner(System.in);
    in.useLocale(java.util.Locale.US);
    
    System.out.println ("Langd");
    double Langd = in.nextDouble ();
    
    System.out.print ("Bradd");
    
    double Bradd = in.nextDouble ();
    
    double Area = Langd * Bradd;
    
    System.out.println("Total Area" + Area);

	}

}



//program som beskriver arean på en rektangel