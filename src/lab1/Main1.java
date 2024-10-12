package lab1;

public class Main1 {
    public static void main(String[] args) {
        int[] note = {29, 37, 38, 41, 84, 67, 68};
        Note noteCalc = new Note(note);

        System.out.println("Nicht ausreichender Note: " + noteCalc.nichtAusreichenderNote());

        System.out.println("Durchschnittswert: "+ noteCalc.durchschnittsWert());

        System.out.println("Abgerundete Note: " + noteCalc.abgerundeteNote());

        System.out.println("Maximal Abgerundete Note: " + noteCalc.maxAbgerundeteNote());
    }
}