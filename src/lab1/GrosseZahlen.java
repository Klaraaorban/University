package lab1;

import java.util.Arrays;

public class GrosseZahlen {
    public int[] num1;
    public int[] num2;

    public GrosseZahlen(int[] num1, int[] num2) {
        this.num1 = num1;
        this.num2 = num2;
    }

    public int[] addGrosseZahlen(int[] num1, int[] num2){
        //EXTRA-->this test if the two numbers have the same length
        if(num1.length < num2.length){
            num1 = fillZero(num1, num2.length);
        }
        else if (num2.length < num1.length){
            num2 = fillZero(num2, num1.length);
        }
        int n = num1.length;
        int[] suma = new int[n+1];
        int flag = 0;

        for(int i = n - 1; i>=0; i--){
            int count = num1[i] + num2[i] + flag;
            suma[i+1] = count%10;
            flag = count / 10;
        }
        suma[0] = flag;
        if(suma[0] == 0){
            return Arrays.copyOfRange(suma, 1, suma.length);
        }
        return suma;
    }

    public int[] diffGrosseZahlen(int[] num1, int[] num2){
        int n = num1.length;
        int[] solution = new int[n];
        int flag = 0;

        for(int i = n - 1; i>=0; i--){
            int diff = num1[i] - num2[i] - flag;

            if(diff < 0){
                diff += 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            solution[i] = diff;
        }
        int removeZero = 0;
        while(removeZero < solution.length && solution[removeZero] == 0){
            removeZero++;
        }
        if(removeZero == solution.length){
            return new int[]{0};
        }
        return Arrays.copyOfRange(solution, removeZero, solution.length);
    }

    public int[] mulGrosseZahl(int[] num1, int nr){
        int n = num1.length;
        int[] solution = new int[n+1];
        int flag = 0;

        for(int i = n-1; i>= 0; i--){
            int mul = num1[i] * nr + flag;
            solution[i+1] = mul%10;
            flag = mul/10;
        }
        solution[0] = flag;
        if(solution[0] == 0){
            return Arrays.copyOfRange(solution, 1, solution.length);
        }
        return solution;
    }

    public  int[] divGrosseZahl(int[] num2, int nr){
        int n = num2.length;
        int[] solution = new int[n];
        int flag = 0;

        for(int i = n-1; i>=0; i--){
            int div = num2[i] + flag*10;
            solution[i] = div/nr;
            flag = div%nr;
        }
        int removeZero = 0;
        while(removeZero < solution.length && solution[removeZero] == 0){
            removeZero++;
        }
        if(removeZero == solution.length){
            return new int[]{0};
        }
        return Arrays.copyOfRange(solution, removeZero, solution.length);
    }

    public int[] fillZero(int[] array, int len){
        //this function fills the smaller array with zeros
        //this way both arrays have the same length
        int[] filling = new int[len];
        int fillingLen = len - array.length;

        System.arraycopy(array, 0, filling, fillingLen, array.length);
        return filling;
    }
}
