import java.util.*;
public class binomialcoefficient{
    public static int fact(int n){
        int k = 1;
        for(int i =1;i<=n;i++){
            k = k * i;
        }
        return k;
    }
    

    public static void main(String args[]){
        System.out.println("Binomial expression : ");
        System.out.println();
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int x=fact(r);
        System.out.println("Factorial r is : " + x);
        int n = sc.nextInt();
        int y= fact(n);
        System.out.println("Factorial n is : " + y);
        int xy= fact(n-r);

        System.out.println("Factorial n-r is : " + xy);
        int a=y/(x*xy);
        System.out.println("Binomial expression is : " + a);

    }
}