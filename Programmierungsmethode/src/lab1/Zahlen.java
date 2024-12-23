package lab1;

public class Zahlen {
    public int[] posZahlen;

    public Zahlen(int[] posZahlen) {
        this.posZahlen = posZahlen;
    }

    public int maximale(){
        int maxim = posZahlen[0];
        for(int i : posZahlen){
            if(maxim < i){
                maxim = i;
            }
        }
        return maxim;
    }

    public int minimale(){
        int minim = posZahlen[0];
        for(int i: posZahlen){
            if(minim > i){
                minim = i;
            }
        }
        return minim;
    }

    public int maximalSum(){
        int maxSum = 0;
        for(int i: posZahlen){
            maxSum += i;
        }
        int smallest = minimale();
        return maxSum - smallest;
    }

    public int minimalSum(){
        int minSum = 0;
        for(int i: posZahlen){
            minSum += i;
        }
        int biggest = maximale();
        return minSum - biggest;
    }

}
