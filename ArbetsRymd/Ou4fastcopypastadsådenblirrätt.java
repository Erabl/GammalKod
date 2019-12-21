package labb;


	// OperationerMedNaturligaHeltalGivnaSomTeckenstrangar.java
	// dinsträng.charAt(offset) kan jämföras med dinsträng2.charAt(offset)
	// stringB.append där stringB är objektet av typen StringBuilder
	 
	 
	 
	import java.util.*; // Scanner
	import static java.lang.System.out;
	 
	public class Ou4fastcopypastadsådenblirrätt { {
	 
	        public static void main (String[] args) {
	 
	                out.println ("OPERATIONER MED NATURLIGA HELTAL GIVNA SOM TECKENSTRANGAR\n");
	 
	                // mata in två naturliga heltal
	                Scanner indata = new Scanner (System.in);
	 
	                out.println ("Mata in två naturliga heltal, där tal1 måste vara större än tal2: ");
	 
	                String tal1 = indata.next ();
	                String tal2 = indata.next ();
	 
	                out.println ();
	 
	                // För lika lång teckensträng
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
	 
	 
	        // addera tar emot två naturliga heltal givna som teckensträngar, och returnerar deras
	        // summa som en teckensträng.
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
	 
	                        sbSum.insert (0,summa); //insert lägger till summa längst fram i strängen(strängbufferten)
	                        summa = 0;
	                }
	 
	                // Om minne == 1
	                if (minne == 1)
	                        sbSum.insert (0, minne);
	 
	 
	                return sbSum.toString ();
	        }
	 
	 
	        // subtrahera tar emot två naturliga heltal givna som teckensträngar, och returnerar
	        // deras differens som en teckensträng.
	        // Det första heltalet är inte mindre än det andra heltalet.
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
	 
	 
	        // visa visar två givna naturliga heltal, och resultatet av en aritmetisk operation
	        // utförd i samband med hetalen
	        public static void visa (String tal1, String tal2, String resultat, char operator) {
	                // sätt en lämplig längd på heltalen och resultatet
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
	 
	 
	        // sattLen lägger till ett angivet antal mellanslag i början av en given sträng
	        public static String sattLen (String s, int antal) {
	                StringBuilder sb = new StringBuilder (s);
	                for (int i = 0; i < antal; i++)
	                        sb.insert (0, " ");
	 
	                return sb.toString ();
	        }
	 
	}
}
