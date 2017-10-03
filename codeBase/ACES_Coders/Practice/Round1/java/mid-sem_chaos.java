/*
Copyright @gihanchanaka
*/

import java.util.HashSet;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;



class HackersClub_MidSemChaos {
	public static void main(String[] args){
        Scanner inp=new Scanner(System.in);
		int N=inp.nextInt();
		int P=inp.nextInt();
		int ans=Integer.MAX_VALUE;
		HashSet<Integer>[] c=new HashSet[N];
		for(int x=0;x<c.length;x++)c[x]=new HashSet<Integer>();
		for(int chapter=0;chapter<N;chapter++){
			int K=inp.nextInt();
			for(int x=0;x<K;x++) c[chapter].add(inp.nextInt());
		}		
		for(int x=0;x<=Math.pow(2, N)-1;x++){
			String a=Integer.toBinaryString(x);
			HashSet<Integer> thisCombination=new HashSet<Integer>();
			int chaptersForThisCombination=0;
			for(int y=0;y<a.length();y++) if(a.charAt(a.length()-1-y)=='1'){
				thisCombination.addAll(c[y]);
				chaptersForThisCombination++;
			}
			if(thisCombination.size()>=P) ans=Math.min(chaptersForThisCombination, ans);
		}
		
		if(ans!=Integer.MAX_VALUE) System.out.println(ans);
        else System.out.println("-1");
	}
	
	
}
