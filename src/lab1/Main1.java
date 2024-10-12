package lab1;

public class Main1 {
    public static void main(String[] args) {
        /*int[] note = {29, 37, 38, 41, 84, 67, 68};
        Note noteCalc = new Note(note);

        System.out.println("Nicht ausreichender Note: " + noteCalc.nichtAusreichenderNote());

        System.out.println("Durchschnittswert: "+ noteCalc.durchschnittsWert());

        System.out.println("Abgerundete Note: " + noteCalc.abgerundeteNote());

        System.out.println("Maximal Abgerundete Note: " + noteCalc.maxAbgerundeteNote());*/

        int[] numbers = {4, 8, 3, 10, 17};
        Zahlen nums = new Zahlen(numbers);

        System.out.println("Maximale Zahl: " + nums.maximale());
        System.out.println("Minimale Zahl: " + nums.minimale());
        System.out.println("Maximale summe von n-1 Zahlen: " + nums.maximalSum());
        System.out.println("Minimale summe von n-1 Zahlen: " + nums.minimalSum());
    }
}