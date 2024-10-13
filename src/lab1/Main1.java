package lab1;

import java.util.Arrays;

public class Main1 {
    public static void main(String[] args) {
        /*
        //Aufgabe 1
        int[] note = {29, 37, 38, 41, 84, 67, 68};
        Note noteCalc = new Note(note);

        System.out.println("Nicht ausreichender Note: " + noteCalc.nichtAusreichenderNote());

        System.out.println("Durchschnittswert: "+ noteCalc.durchschnittsWert());

        System.out.println("Abgerundete Note: " + noteCalc.abgerundeteNote());

        System.out.println("Maximal Abgerundete Note: " + noteCalc.maxAbgerundeteNote());*/

        /*
        //Aufgabe 2
        int[] numbers = {4, 8, 3, 10, 17};
        Zahlen nums = new Zahlen(numbers);

        System.out.println("Maximale Zahl: " + nums.maximale());
        System.out.println("Minimale Zahl: " + nums.minimale());
        System.out.println("Maximale summe von n-1 Zahlen: " + nums.maximalSum());
        System.out.println("Minimale summe von n-1 Zahlen: " + nums.minimalSum()); */

        //Aufgabe 3

        int[] num1 = {1,3,0,0,0,0,0,0,1};
        int[] num2 = {8,7,0,0,0,0,0,0,0};
        GrosseZahlen number = new GrosseZahlen(num1, num2);

        System.out.println("Summe: " + Arrays.toString(number.addGrosseZahlen(num1, num2)));

        System.out.println("Differenz: " + Arrays.toString(number.diffGrosseZahlen(num1, num2)));

        System.out.println("Multiplikation: " + Arrays.toString(number.mulGrosseZahl(num1, 100)));

        System.out.println("Division: " + Arrays.toString(number.divGrosseZahl(num2, 10)));

    }
}