/*
Copyright @gihanchanaka
*/

import java.util.Scanner;
import java.util.ArrayList;

class HackersClub_HairCut_Dansala {
	static int N;
	static int K;
	static int[] M;
	
	public static void main(String[] args){
        Scanner inp=new Scanner(System.in);
		K=inp.nextInt();
		N=inp.nextInt();
		M=new int[K];
		for(int i=0;i<K;i++) M[i]=inp.nextInt();     
		int left=0; int right=Integer.MAX_VALUE/10;
		int mid=0;
		while(left<right){
			mid=(left+right)/2;
			if(howManyCutsByNow(mid)<N){
				left=mid+1;
			}
			else{
				right=mid;
			}
            
		}
		System.out.println(left);
		
	}
	
	public static long howManyCutsByNow(int t){
		long ans=0;
		for(int x=0;x<K;x++){
			ans+=(long)t/(long)M[x];
            ans++;
		}
		return ans;
	}
	
}
