package labb;


	// OperationerMedNaturligaHeltalGivnaSomTeckenstrangar.java
	// dinstr�ng.charAt(offset) kan j�mf�ras med dinstr�ng2.charAt(offset)
	// stringB.append d�r stringB �r objektet av typen StringBuilder
	 
	 
	 
	import java.util.*; // Scanner
	import static java.lang.System.out;
	 
	public class Ou4fastcopypastads�denblirr�tt { {
	 
	        public static void main (String[] args) {
	 
	                out.println ("OPERATIONER MED NATURLIGA HELTAL GIVNA SOM TECKENSTRANGAR\n");
	 
	                // mata in tv� naturliga heltal
	                Scanner indata = new Scanner (System.in);
	 
	                out.println ("Mata in tv� naturliga heltal, d�r tal1 m�ste vara st�rre �n tal2: ");
	 
	                String tal1 = indata.next ();
	                String tal2 = indata.next ();
	 
	                out.println ();
	 
	                // F�r lika l�ng teckenstr�ng
	                while (tal1.length () > tal2.length ())
	                        tal2 = 0 + tal2;
	 
	 
	                // Anropar metoden summa med inparametrar tal1 och tal2 och returnerar resultatet till summa.
	                String summa = addera (tal1, tal2);
	                // Anropar metoden visa med inparametrar tal1, tal2, summa och operatorn som skriver ut resultatet.
	                visa (tal1, tal2, summa, '+');
	 
	 
	                // Anropar metoden subtrahera med inparameterar tal1 och tal2 och returnerar resultatet till diff.
	                String diff = subtrahera (tal1, tal2);
	                // Anropar metoden visa med inparametrar tal1, tal2, diff och operatorn som skriver ut resultatet.
	                visa (tal1, tal2, diff, '-');
	 
	        }
	 
	 
	        // addera tar emot tv� naturliga heltal givna som teckenstr�ngar, och returnerar deras
	        // summa som en teckenstr�ng.
	        public static String addera (String tal1, String tal2) {
	 
	                StringBuilder sbSum = new StringBuilder ();
	 
	                int minne = 0;
	                int summa = 0;
	 
	                for (int i = tal1.length() - 1; i >= 0; i--) {
	                        if (((tal1.charAt (i) - 48) + (tal2.charAt (i) - 48) + minne) >= 10) {
	                                summa = (((tal1.charAt (i) - 48) + (tal2.charAt (i) - 48) + minne) % 10);
	                                minne = 1;
	                        }
	                        else {
	                                summa = ((tal1.charAt (i) - 48) + (tal2.charAt (i) - 48) + minne);
	                                minne = 0;
	 
	                        }
	 
	                        sbSum.insert (0,summa); //insert l�gger till summa l�ngst fram i str�ngen(str�ngbufferten)
	                        summa = 0;
	                }
	 
	                // Om minne == 1
	                if (minne == 1)
	                        sbSum.insert (0, minne);
	 
	 
	                return sbSum.toString ();
	        }
	 
	 
	        // subtrahera tar emot tv� naturliga heltal givna som teckenstr�ngar, och returnerar
	        // deras differens som en teckenstr�ng.
	        // Det f�rsta heltalet �r inte mindre �n det andra heltalet.
	        public static String subtrahera (String tal1, String tal2) {
	 
	                StringBuilder sbDiff = new StringBuilder ();
	 
	                int minne = 0;
	                int diff = 0;
	 
	 
	                for (int i = tal1.length () - 1; i >= 0; i--) {
	                        if (((tal1.charAt (i) - 48) - (tal2.charAt (i) - 48) + minne) < 0) {
	                                diff = ((tal1.charAt (i) - 48) - (tal2.charAt (i) - 48) + minne + 10);
	                                minne = -1;
	                        }
	                        else {
	                                diff = ((tal1.charAt (i) - 48) - (tal2.charAt (i) - 48) + minne);
	                                minne = 0;
	                        }
	 
	                        sbDiff.insert (0, diff);
	                        diff = 0;
	                }
	 
	                return sbDiff.toString ();
	        }
	 
	 
	        // visa visar tv� givna naturliga heltal, och resultatet av en aritmetisk operation
	        // utf�rd i samband med hetalen
	        public static void visa (String tal1, String tal2, String resultat, char operator) {
	                // s�tt en l�mplig l�ngd p� heltalen och resultatet
	                int len1 = tal1.length ();
	                int len2 = tal2.length ();
	                int len = resultat.length ();
	                int maxLen = Math.max (Math.max (len1, len2), len);
	                tal1 = sattLen (tal1, maxLen - len1);
	                tal2 = sattLen (tal2, maxLen - len2);
	                resultat = sattLen (resultat, maxLen - len);
	 
	                // visa heltalen och resultatet
	                out.println (" " + tal1);
	                out.println ("" + operator + " " + tal2);
	 
	                for (int i = 0; i < maxLen + 2; i++)
	                        out.print ("-");
	 
	                out.println ();
	                out.println (" " + resultat + "\n");
	        }
	 
	 
	        // sattLen l�gger till ett angivet antal mellanslag i b�rjan av en given str�ng
	        public static String sattLen (String s, int antal) {
	                StringBuilder sb = new StringBuilder (s);
	                for (int i = 0; i < antal; i++)
	                        sb.insert (0, " ");
	 
	                return sb.toString ();
	        }
	 
	}
}
