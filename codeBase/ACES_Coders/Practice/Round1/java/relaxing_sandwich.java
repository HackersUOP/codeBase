/*
Copyright @lakshitha
*/
import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner s1=new Scanner(System.in);
        int p =s1.nextInt();
        int a =s1.nextInt();
        int b =s1.nextInt();
        
        if( b > p )
             System.out.println("-1");  
        else if(p < (a+b) )
            System.out.println(a+b);  
        else
            System.out.println(p); 
        
    }
}