package lab1;

import java.util.Arrays;

public class Main1 {
    public static void main(String[] args) {

        //Aufgabe 1
        int[] note = {29, 37, 38, 41, 84, 67, 68};
        Note noteCalc = new Note();

        System.out.print("Nicht ausreichender Note: ");
        for (int i : noteCalc.nichtAusreichenderNote(note)) {
            System.out.print(i + ", ");
        }
        System.out.println();
        System.out.println("Durchschnittswert: " + noteCalc.durchschnittsWert(note));

        System.out.print("Abgerundete Note: ");
        for (int i : noteCalc.abgerundeteNote(note)) {
            System.out.print(i + ", ");
        }
        System.out.println();
        System.out.print("Maximal Abgerundete Note: " + noteCalc.maxAbgerundeteNote(note) + "\n");


        //Aufgabe 2
        int[] numbers = {4, 8, 3, 10, 17};
        Zahlen nums = new Zahlen(numbers);

        System.out.println("Maximale Zahl: " + nums.maximale());
        System.out.println("Minimale Zahl: " + nums.minimale());
        System.out.println("Maximale summe von n-1 Zahlen: " + nums.maximalSum());
        System.out.println("Minimale summe von n-1 Zahlen: " + nums.minimalSum() + "\n");


        //Aufgabe 3
        int[] num1 = {1, 3, 0, 0, 0, 0, 0, 0, 1};
        int[] num2 = {8, 6, 0, 0, 0, 0, 0, 0, 0};
        GrosseZahlen number = new GrosseZahlen(num1, num2);

        System.out.println("Summe: " + Arrays.toString(number.addGrosseZahlen(num1, num2)));

        System.out.println("Differenz: " + Arrays.toString(number.diffGrosseZahlen(num1, num2)));

        System.out.println("Multiplikation: " + Arrays.toString(number.mulGrosseZahl(num1, 2)));

        System.out.println("Division: " + Arrays.toString(number.divGrosseZahl(num2, 10)) + "\n");


        //Aufgabe 4
        int[] tastatur = {40, 35, 70, 15, 45};
        int[] usb = {20, 15, 40, 14};
        ElektronikShop elems = new ElektronikShop();

        System.out.println("Billigste Tastatur Preise: " + elems.billigsteTastatur(tastatur));

        System.out.println("Teuresten Gegenstand: " + elems.teuresteGegenstand(tastatur, usb));

        System.out.println("Teureste USB Laufwerk in Budget: " + elems.budgetUSB(usb, 30));

        int[] tast = {40, 60};
        int[] usb2 = {8, 12};

        System.out.println("Maximal Geldbetrag: " + elems.maximalGeldbetrag(tast, usb2, 60));
    }
}