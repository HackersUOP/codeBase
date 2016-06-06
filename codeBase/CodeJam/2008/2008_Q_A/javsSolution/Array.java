
public class Array {
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
	
	public static int max(int[] ar){
		int max=Integer.MIN_VALUE;
		for(int x=0;x<ar.length;x++) max=Math.max(max, ar[x]);
		return max;
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
}
