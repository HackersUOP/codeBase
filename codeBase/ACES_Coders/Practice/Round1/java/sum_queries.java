/*
Copyright @sanjaya
 */

import java.util.Scanner;
public class sumquery {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int N= in.nextInt();
        int Q= in.nextInt();
        long[] sum= new long[N];
        
        long s=0;
        for (int i = 0; i < N; i++) {
            
            s=s+in.nextInt();
            sum[i]=s;
        }
        
        int p,q;
        for (int i = 0; i < Q; i++) {
            p=in.nextInt();
            q=in.nextInt();
            
            if(p==0)
                System.out.println(sum[q]);
            else
                System.out.println(sum[q]-sum[p-1]);
            
        }
    }
}
