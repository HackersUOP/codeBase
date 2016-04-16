package codeJam;
import java.util.Scanner;
public class CountingSheep {
	static Scanner sc=new Scanner(System.in);
	
	public static boolean checkWholeBinaryArray(boolean[] ar){
		boolean ans=true;
		for(int x=0;x<10;x++) ans=ans&&ar[x];
	return ans;
	}
	
	public static void main(String[] args){
		int testCases=Integer.parseInt(sc.nextLine());
		for(int caseNo=0;caseNo<testCases;caseNo++){
			int x=Integer.parseInt(sc.nextLine());
			runOnce(caseNo,x);
		}
	}

	public static void runOnce(int caseNo, int n){
		if(n==0) System.out.println("Case #"+(caseNo+1)+": "+"INSOMNIA");
		else{
			boolean[] check=new boolean[10];
			int i=1;
			while(!checkWholeBinaryArray(check)){
				if(i!=1) n=n*i/(i-1);
				else n=n*i;
				check=updateBooleanArray(check,n);
				i++;
			}
			System.out.println("Case #"+(caseNo+1)+": "+n);
		}
	}
	
	public static boolean[] updateBooleanArray(boolean[] ar,int x){
		String s=x+"";
		//System.out.print(s+" ");
		for(int y=0;y<s.length();y++) ar[Integer.parseInt(s.substring(y, y+1))]=true;
		return ar;
	}
	
	
	
}
