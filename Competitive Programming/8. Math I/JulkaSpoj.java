// https://www.spoj.com/problems/JULKA/

import java.util.Scanner;
import java.math.BigInteger;

class JulkaSpoj{
    static void compute(BigInteger n, BigInteger k)
    {
        BigInteger x, y;
        x = n.subtract(k);
        x = x.divide(BigInteger.valueOf(2));
        y = x.add(k);
        System.out.println(y);
        System.out.println(x);
    }

    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        BigInteger n, k, ans;
        int tests = 1;
        while(tests > 0)
        {
            n = sc.nextBigInteger();
            k = sc.nextBigInteger();
            compute(n, k);
            tests -= 1;
        }
    }
}