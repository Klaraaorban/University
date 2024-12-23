package lab1;

public class Note {

    public int[] nichtAusreichenderNote(int[] note){
        int count = 0;
        for(int n : note){
            if(n < 40){
                count++;
            }
        }
        int[] nichtAusreichender = new int[count];
        int i = 0;
        for(int n: note){
            if(n<40){
                nichtAusreichender[i] = n;
                i++;
            }
        }
        return nichtAusreichender;
    }

    public double durchschnittsWert(int[] note){
        int count = 0;
        for(int n : note){
            count += n;
        }
        return (double) count / note.length;
    }

    public int[] abgerundeteNote(int[] note){
        int[] abgerundet = new int[note.length];
        for(int i = 0; i<=note.length - 1; i++){
            if(note[i] < 38){
                abgerundet[i] = note[i];
            }
            else{
                int vielfachen5 = (note[i]+4) / 5 * 5;
                if(vielfachen5 - note[i] < 3){
                    abgerundet[i] = vielfachen5;
                }
                else{
                    abgerundet[i] = note[i];
                }
            }
        }
        return abgerundet;
    }

    public int maxAbgerundeteNote(int[] note){
        int[] abgerundet = abgerundeteNote(note);
        int maxNote = abgerundet[0];
        for(int n : abgerundet){
            if(n > maxNote){
                maxNote = n;
            }
        }
        return maxNote;
    }
}
