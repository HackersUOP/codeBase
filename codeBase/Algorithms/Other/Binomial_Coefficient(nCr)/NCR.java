/*
    gihanjayatilaka[at]end[dot]pdn[dot]ac[dot]lk
    2020-04-04

    DP (Dynamic progamming) nCr (number of k-combinations)
*/
import java.util.Scanner;
class NCR{
    static Scanner sc=new Scanner(System.in);

    public static void main(String[] args){
        int N=sc.nextInt();
        int R=sc.nextInt();
        System.out.println(N+"c"+R+" = "+nCr(N,R));
    }

    public static long nCr(int n,int r){
		long[][] c=new long[n+1][r+1];
		int i,j;
		for(i=0;i<n+1;i++){
			for(j=0;j<Math.min(i+1,r+1);j++){
				if(j==0||j==i)c[i][j]=1;
				else{
					c[i][j]=c[i-1][j-1]+c[i-1][j];
				}
			}
		}
		return c[n][r];
	}
}
