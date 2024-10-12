package lab1;
import java.util.ArrayList;

public class Note {
    public int[] note;

    public Note(int[] noten) {
        this.note = noten;
    }

    public ArrayList<Integer> nichtAusreichenderNote(){
        ArrayList<Integer> nichtAusreichender = new ArrayList<>();
        for(int n : note){
            if(n < 40){
                nichtAusreichender.add(n);
            }
        }
        return nichtAusreichender;
    }

    public double durchschnittsWert(){
        int count = 0;
        for(int n : note){
            count += n;
        }
        return (double) count / note.length;
    }

    public ArrayList<Integer> abgerundeteNote(){
        ArrayList<Integer> abgerundet = new ArrayList<>();
        for(int n: note){
            if(n < 40){
                abgerundet.add(n);
            }
            else{
                int vielfachen5 = (n+4) / 5 * 5;
                if(vielfachen5 - n < 3){
                    abgerundet.add(vielfachen5);
                }
                else{
                    abgerundet.add(n);
                }
            }
        }
        return abgerundet;
    }

    public int maxAbgerundeteNote(){
        ArrayList<Integer> abgerundet = abgerundeteNote();
        int maxNote = abgerundet.get(0);
        for(int n : abgerundet){
            if(n > maxNote){
                maxNote = n;
            }
        }
        return maxNote;
    }
}
