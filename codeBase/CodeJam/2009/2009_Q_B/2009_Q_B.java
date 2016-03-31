import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {

    public static void main(String[] args) {
        Scanner inp=new Scanner(System.in);
        int t=inp.nextInt();
        for(int i=0;i<t;i++){
        	int n=inp.nextInt();
        	ArrayList<BigInteger> list=new ArrayList<BigInteger>(n);
        	BigInteger one=new BigInteger("1");
        	for(int j=0;j<n;j++){
        		String s=inp.next();
        		BigInteger bi=new BigInteger(s);
        		list.add(bi);  
        	}
        	BigInteger w=new BigInteger("0");
        	for(int j=1;j<n;j++){
        		for(int k=0;k<j;k++){
        			BigInteger tmp=list.get(j).subtract(list.get(k)).abs();
        			if(j==1&&k==0) w=tmp;
        			w=w.gcd(tmp);
        		}
        	}

        	BigInteger[] ra=list.get(0).divideAndRemainder(w);
            BigInteger r=new BigInteger("0");
            BigInteger zero=new BigInteger("0");
            if(ra[1].compareTo(zero)==0) r=ra[0];
            else r=ra[0].add(one);
        	BigInteger ans=r.multiply(w).subtract(list.get(0));
        	System.out.println("Case #"+(i+1)+": "+ans);
        }
    }

    
}