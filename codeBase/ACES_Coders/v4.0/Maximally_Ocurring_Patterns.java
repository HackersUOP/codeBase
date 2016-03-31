import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner inp=new Scanner(System.in);
        int n=inp.nextInt();
        String[] store=new String[n];
        for(int i=0;i<n;i++) store[i]=inp.next();
        int[] cnt=new int[n];
        Arrays.fill(cnt,0);
        String str=inp.next();
        for(int j=0;j<n;j++){
            int l1=store[j].length();
                for(int k=0;k<=(str.length()-l1);k++){
                    if(str.substring(k,k+l1).equals(store[j])){
                       cnt[j]=cnt[j]+1; 
                    }
                }
        }
        int y=0;
        for(int m=0;m<n;m++){
            y=Math.max(y,cnt[m]);
        }
        System.out.println(y);
        for(int h=0;h<n;h++){
            if(cnt[h]==y) System.out.println(store[h]);
        }
    }
}