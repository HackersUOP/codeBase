/*
Copyright @gihanchanaka
*/

import java.util.Scanner;
import java.util.ArrayList;

import java.util.*;



class HackersClub_boredom {
	static int N;
	static int[] primesBelowN;
	static int[] answers;
	public static void main(String[] args){
		Scanner inp=new Scanner(System.in);
		N=inp.nextInt();
		answers=Array.array(N+1, -1);
		primesBelowN=Maths.allPrimesBelow(N);
		System.out.println(howManySteps(N,0));	
	}
	
	
	public static int howManySteps(int n,int steps){
		if(answers[n]!=-1) return answers[n];
		else{
			if(n<2) return 999999999;
		
			else if(Maths.isPrime(n)) return steps;
			else{
				int ans=Integer.MAX_VALUE;
				for(int x=primesBelowN.length-1;x>-1;x--) if(primesBelowN[x]<n){
					ans=Math.min(ans, howManySteps(n-primesBelowN[x],steps+1));
				}
				answers[n]=ans;
				return ans;
			}
		}
	}
}


class Array {
	public static String[] getColumn(String[][] ar,int column){
		String[] ans=new String[ar.length];
		for(int x=0;x<ar.length;x++) ans[x]=ar[column][x];
		return ans;
	}
	
	public static int indexOf(String[] ar,String s){
		int index=-1;
		for(int x=0;x<ar.length;x++) if(s.equals(ar[x])){
			index=x;
			break;
		}
		return index;
	}
	
	public static int indexOfMax(int[] ar){
		int index=-1;
		int max=Integer.MIN_VALUE;
		for(int x=0;x<ar.length;x++){
			if(max<ar[x]){
				max=ar[x];
				index=x;
			}
		}
		return index;
	}
	public static int indexOfMin(int[] ar){
		int index=-1;
		int min=Integer.MAX_VALUE;
		for(int x=0;x<ar.length;x++){
			if(min>ar[x]){
				min=ar[x];
				index=x;
			}
		}
		return index;
	}
	public static int max(int[] ar){
		int max=Integer.MIN_VALUE;
		for(int x=0;x<ar.length;x++) max=Math.max(max, ar[x]);
		return max;
	}
	
	public static int min(int[] ar){
		int min=Integer.MAX_VALUE;
		for(int x=0;x<ar.length;x++) min=Math.min(min, ar[x]);
		return min;
	}
	
	
	
	public static String[] crop(String[] ar,int startInclusive,int endExclusive){
		String[] ans=new String[endExclusive-startInclusive];
		for(int x=0;x<ans.length;x++) ans[x]=ar[x+startInclusive];
		return ans;
	}
	
	
	public static String[] crop(String[] ar,int startInclusive){
		String[] ans=new String[ar.length-startInclusive];
		for(int x=0;x<ans.length;x++) ans[x]=ar[x+startInclusive];
		return ans;
	}
	
	public static int[] array(int size,int n){
		int[] ans=new int[size];
		for(int x=0;x<size;x++) ans[x]=n;
		return ans;
	}
	
	public static String[] array(int size,String s){
		String[] ans=new String[size];
		for(int x=0;x<size;x++) ans[x]=s;
		return ans;
	}
	
	public static boolean[] array(int size,boolean b){
		boolean[] ans=new boolean[size];
		for(int x=0;x<size;x++) ans[x]=b;
		return ans;
	}
	public static char[] array(int size,char c){
		char[] ans=new char[size];
		for(int x=0;x<size;x++) ans[x]=c;
		return ans;
	}
	public static int[] getColumn(int[][] ar,int column){
		int[] ans=new int[ar.length];
		for(int x=0;x<ar.length;x++) ans[x]=ar[column][x];
		return ans;
	}
	
	public static char[] getColumn(char[][] ar,int column){
		char[] ans=new char[ar.length];
		for(int x=0;x<ar.length;x++) ans[x]=ar[x][column];
		return ans;
	}
	
	public static boolean isZeros(int[] ar){
		return max(ar)==0 && min(ar)==0;
	}
	
	public static boolean isZeros(int[][] ar){
		boolean ans=true;
		for(int x=0;x<ar.length;x++) ans=ans&&isZeros(ar[x]);
		return ans;
	}
	
	public static int sum(int[] ar){
		int ans=0;
		for(int x=0;x<ar.length;x++) ans+=ar[x];
		return ans;
	}
	
	public static int[] reverse(int ar[]){
		int[] ans=new int[ar.length];
		for(int x=0;x<ar.length;x++) ans[ans.length-1-x]=ar[x];
		return ans;
	}
	
}




class Maths {
	public static int[] allPrimesBelow(int n){
		ArrayList<Integer> ans=new ArrayList<Integer>();
		int x=n-1;
		while(x>1){
			if(isPrime(x)) ans.add(x);
			x--;
		}
		Object[] getObjects=ans.toArray();
		int[] finalAns=new int[getObjects.length];
		for(int y=0;y<getObjects.length;y++) finalAns[y]=(int)getObjects[y];
		return finalAns;
	}
	
	public static boolean isPrime(int n){
		if(n<=1) return false;
		else{
			boolean ans=true;
			for(int x=2;x<1+(int)Math.sqrt(n);x++){
				if(n%x==0){
					ans=false;
					break;
				}
			}
			return ans;
		}
	}
	
	
	public static int max(int a,int b,int c){
		return Math.max(a, Math.max(c, b));
	}
}

