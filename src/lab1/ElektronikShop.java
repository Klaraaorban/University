package lab1;

public class ElektronikShop {
    int[] tastatur_preis;
    int[] USB_laufwerk;

    public ElektronikShop(int[] tastatur, int[] usb) {
        this.tastatur_preis = tastatur;
        this.USB_laufwerk = usb;
    }

    public int billigsteTastatur(int[] tastatur_preis){
        int minimal = tastatur_preis[0];
        for(int i = 0; i<=tastatur_preis.length - 1; i++){
            if(minimal > tastatur_preis[i]){
                minimal = tastatur_preis[i];
            }
        }
        return minimal;
    }

    public int maximalFunc(int[] array){
        int maximal = array[0];
        for(int i = 0; i<=array.length - 1; i++){
            if(maximal < array[i]){
                maximal = array[i];
            }
        }
        return maximal;
    }

    public int teuresteGegenstand(int[] tastatur_preis, int[] USB_laufwerk){
        int maxTast = maximalFunc(tastatur_preis);
        int maxUSB = maximalFunc(USB_laufwerk);
        return Math.max(maxTast, maxUSB);
    }

    public int budgetUSB(int[] USB_laufwerk, int budget){
        int maximal = USB_laufwerk[0];
        for(int i = 0; i<= USB_laufwerk.length - 1; i++){
            if(USB_laufwerk[i] < budget && USB_laufwerk[i] > maximal){
                maximal = USB_laufwerk[i];
            }
            else i++;
        }
        return maximal;
    }

    public int maximalGeldbetrag(int[] tastatur_preis, int[] USB_laufwerk, int budget){
        int maxBudget = -1;

        for(int tastatur : tastatur_preis){
            for(int usb : USB_laufwerk){
                int count = tastatur + usb;
                if(count <= budget && count > maxBudget){
                    maxBudget = count;
                }
            }
        }
        return maxBudget;
    }
}
