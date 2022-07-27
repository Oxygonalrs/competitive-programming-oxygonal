import java.util.Scanner;
import java.math.BigInteger;

public class BigIntegerInJava{
    static void playWithBigInt(){
        Scanner sc = new Scanner(System.in);
        BigInteger b1 = new BigInteger("1");
        BigInteger b2 = new BigInteger("1222222222222222222222");
        String s1 = sc.next();
        BigInteger b3 = new BigInteger(s1);
        b1 = b1.add(b2);
        System.out.println(b1);
        System.out.println(b1.multiply(b3));

        // Bits Counts - Total Set Bits
        System.out.println(b1.bitCount());

        //Total No of Bits
        System.out.println(b1.bitLength());
    
        // Integer into Big Integer
        int a = sc.nextInt();
        int b = sc.nextInt();

        System.out.println(a+b);
        BigInteger b4 = BigInteger.valueOf(a);
        BigInteger b5 = BigInteger.valueOf(b);
        
        // GCD
        System.out.println(b4.gcd(b5));
    
        // Base Conversion
        //Inpret the no in given base
        BigInteger b6 = new BigInteger("1001", 2);
        System.out.println(b6);

        //Power of Number
        System.out.println(b4.pow(20));



    }
    static BigInteger fact(int N)
    {
        BigInteger b = new BigInteger("1");
        for(int i=2; i<=N; i++)
        {
            b = b.multiply(BigInteger.valueOf(i));
        }
        return b;
    }
    public static void main(String args[])
    {
        // playWithBigInt();
        int n = 100;
        System.out.println(fact(n));
    }
}