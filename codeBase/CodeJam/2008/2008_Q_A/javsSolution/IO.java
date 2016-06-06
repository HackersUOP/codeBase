import java.util.Scanner;
public class IO {
	static Scanner sc=new Scanner(System.in);
	
	public static String readLine(){
		return sc.nextLine();
	}
	
	public static char[] readNonSpacedCharArray(){
		return readLine().toCharArray();
	}
	
	public static String[] readStringArray(int n){
		String[] ans=new String[n];
		for(int x=0;x<n;x++) ans[x]=readLine();
		return ans;
	}
	
	public static int[] readNonSpacedIntArray(){
		char[] input= readLine().toCharArray();
		int[] ans=new int[input.length];
		for(int x=0;x<ans.length;x++){
			ans[x]=input[x]-'0';
		}
		return ans;
	}
	
	public static void print(boolean a){
		if(a) System.out.println("true");
		else System.out.println("false");
	}
	
	
	public static int readIntLine(){
		return Integer.parseInt(readLine());
	}
	
	public static int readInt(){
		return sc.nextInt();
	}
	
	public static void printCodeJamStyle(int caseNo,String s){
		System.out.println("Case #"+caseNo+": "+s);
	}
	
	public static void printCodeJamStyle(int caseNo,int n){
		printCodeJamStyle(caseNo,""+n);
	}
	
	public static int[] readIntArray(int noOfElements){
		int[] ans=new int[noOfElements];
		for(int x=0;x<noOfElements;x++)ans[x]=sc.nextInt();
		sc.nextLine();
		return ans;
	}
	
	public static int[][] readInt2DArray(int rows,int columns){
		int[][] ans=new int[rows][columns];
		for(int x=0;x<rows;x++) ans[x]=readIntArray(columns);
		return ans;
	}
	
	
	public static void print(String s){
		System.out.println(s);
	}
	
	public static void print(int n){
		print(""+n);
	}
	
	public static void printHold(String s){
		System.out.print(s);
	}
	
	
	public static void nextLine(){
		System.out.println("");
	}
	
	public static void print(String[] ar){
		String s="";
		for(int x=0;x<ar.length;x++)s=s+" "+ar[x];
		print(s.trim());
	}
	
	public static void print(String[][] ar){
		for(int x=0;x<ar.length;x++) print(ar[x]);
	}
	
	public static void print(char[][] ar){
		for(int x=0;x<ar.length;x++) print(ar[x]);
	}
	
	public static void print(int[][] ar){
		for(int x=0;x<ar.length;x++) print(ar[x]);
	}
	
	public static void print(int[] ar){
		String s="";
		for(int x=0;x<ar.length;x++)s=s+" "+ar[x];
		print(s.trim());
	}
	public static void print(char[] ar){
		String s="";
		for(int x=0;x<ar.length;x++)s=s+" "+ar[x];
		print(s.trim());
	}
}
