/* 
	Code written by gihanjayatilaka[at]eng.pdn.ac.lk during Code Jam 2018
	This solution passed all test cases
*/
import java.util.*;
import java.io.*;

class InputReader {
    BufferedReader bReader;
    StringTokenizer tokenizer;

    InputReader(InputStream inputStream){
        InputStreamReader inStreamReader=new InputStreamReader(inputStream);
        bReader=new BufferedReader(inStreamReader);
        tokenizer=new StringTokenizer("");

    }

    public String nextLine(){
        try{
            String inLine= bReader.readLine();
            tokenizer= new StringTokenizer(inLine);
            return inLine;

        }
        catch(Exception e){
            return null;
        }
    }

    public String nextWord(){
        while(tokenizer== null || !tokenizer.hasMoreTokens()){
            nextLine();
            //tokenizer=new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public boolean hasNext(){
        try{
            return bReader.ready();
        }
        catch(Exception e){
            return false;
        }
    }



}

class IO2 {
    static InputReader sc=new InputReader(System.in);

    public static String readLine(){
        return sc.nextLine();
    }
    public static String readWord(){
        return sc.nextWord();
    }

    public static int readInt(){
        return Integer.parseInt(readWord());
    }

    public static long readLong(){
        return Long.parseLong(readWord());
    }

    public static double readDouble(){
        return Double.parseDouble(readWord());
    }

    public static float readFloat(){
        return Float.parseFloat(readWord());
    }

    public static char readChar(){
        return (char) readInt();
    }

    public static int readIntLine(){
        return Integer.parseInt(readLine().trim());
    }

    public static long readLongLine(){
        return Long.parseLong(readLine().trim());
    }

    public static double readDoubleLine(){
        return Double.parseDouble(readLine().trim());
    }

    public static float readFloatLine(){
        return Float.parseFloat(readLine().trim());
    }

    public static char readCharLine(){
        return (char)readIntLine();
    }

    public static int[] readIntArray(int noOfElements){
        int[] ans=new int[noOfElements];
        for(int x=0;x<noOfElements;x++)ans[x]=readInt();
		/*if(sc.hasNext())*///readLine();
        return ans;
    }
    public static double[] readDoubleArray(int noOfElements){
        double[] ans=new double[noOfElements];
        for(int x=0;x<noOfElements;x++)ans[x]=readDouble();
		/*if(sc.hasNext())*///readLine();
        return ans;
    }

    public static double[][] readDoubleArray(int rows,int columns){
        double[][] ans=new double[rows][columns];
        for(int x=0;x<rows;x++)ans[x]=readDoubleArray(columns);
        return ans;
    }

    public static float[] readFloatArray(int noOfElements){
        float[] ans=new float[noOfElements];
        for(int x=0;x<noOfElements;x++)ans[x]=readFloat();
		/*if(sc.hasNext())*///readLine();
        return ans;
    }

    public static float[][] readFloatArray(int rows,int columns){
        float[][] ans=new float[rows][columns];
        for(int x=0;x<rows;x++)ans[x]=readFloatArray(columns);
        return ans;
    }

    public static String[] readStringArray(int n){
        String[] ans=new String[n];
        for(int x=0;x<n;x++) ans[x]=readLine();
        return ans;
    }
    public static int[][] readIntArray(int rows,int columns){
        int[][] ans=new int[rows][columns];
        for(int x=0;x<rows;x++){
            ans[x]=readIntArray(columns);
        }
        return ans;
    }

    public static long[] readLongArray(int noOfElements){
        long[] ans=new long[noOfElements];
        for(int x=0;x<noOfElements;x++) ans[x]=readLong();
		/*if(sc.hasNext())*/readLine();
        return ans;
    }

    public static long[][] readLongArray(int rows,int columns){
        long[][] ans=new long[rows][columns];
        for(int x=0;x<rows;x++) ans[x]=readLongArray(columns);
        return ans;
    }
    public static char[][] readNonSpaced2DCharArray(int noOfLines){
        char[] lineOne=readNonSpacedCharArray();
        char[][] ans=new char[noOfLines][lineOne.length];
        ans[0]=lineOne;
        for(int x=1;x<noOfLines;x++) ans[x]=readNonSpacedCharArray();
        return ans;
    }
    public static char[] readNonSpacedCharArray(){
        return readLine().toCharArray();
    }
    //PRINT FUNCTIONS
    public static void print(String s){
        System.out.println(s);
    }

    public static void print(int n){
        print(""+n);
    }

    public static void print(long n){
        print(""+n);
    }

    public static void printHold(String s){
        System.out.print(s);
    }

    public static void print(boolean a){
        if(a) System.out.println("true");
        else System.out.println("false");
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

    public static void print(Object[] ar,char seperator){
        for(int x=0;x<ar.length-1;x++){
            System.out.print(ar[x].toString());
            System.out.print(seperator);
        }
        System.out.print(ar[ar.length-1].toString());
    }

    public static void print(char[][] ar){
        for(int x=0;x<ar.length;x++) print(ar[x]);
    }

    public static void print(int[][] ar){
        for(int x=0;x<ar.length;x++) print(ar[x]);
    }
    public static void print(float[][] ar){
        for(int x=0;x<ar.length;x++) print(ar[x]);
    }

    public static void print(boolean[][] ar){
        for(int x=0;x<ar.length;x++) print(ar[x]);
    }

    public static void print(int[] ar){
        String s="";
        for(int x=0;x<ar.length;x++)s=s+" "+ar[x];
        print(s.trim());
    }

    public static void print(long[] ar){
        String s="";
        for(int x=0;x<ar.length;x++)s=s+" "+ar[x];
        print(s.trim());
    }

    public static void print(float[] ar){
        String s="";
        for(int x=0;x<ar.length;x++)s=s+" "+ar[x];
        print(s.trim());
    }

    public static void printFast(int[] ar){
        for(int x=0;x<ar.length-1;x++){
            System.out.print(ar[x]);
            System.out.print(" ");
        }
        System.out.print(ar[ar.length-1]);
        System.out.println("");
    }

    public static void printFast(long[] ar){
        for(int x=0;x<ar.length-1;x++)System.out.print(ar[x]+" ");
        if(ar.length>0)System.out.print(ar[ar.length-1]);
        System.out.println("");
    }
    public static void printFast(long[][] ar){
        for(int x=0;x<ar.length;x++) printFast(ar[x]);
    }
    public static void print(char[] ar){
        String s="";
        for(int x=0;x<ar.length;x++)s=s+" "+ar[x];
        print(s.trim());
    }
    public static void print(boolean[] ar){
        String s="";
        for(int x=0;x<ar.length;x++)if(ar[x]) s=s+"true ";
        else s=s+"false ";
        print(s.trim());
    }

    public static void printCodeJamStyle(int caseNo,String s){
        System.out.println("Case #"+caseNo+": "+s);
    }

    public static void printCodeJamStyle(int caseNo,int n){
        printCodeJamStyle(caseNo,""+n);
    }

    public static void printNonSpaced(char[] ar){
        for(int x=0;x<ar.length;x++) System.out.print(ar[x]);
        System.out.println("");
    }


}


public class Solution {
    static int[][] ar;
    public static void main(String[] args) {
        int T=IO2.readInt();
        for(int t=1;t<=T;t++){
            int N=IO2.readInt();
            ar=new int[2][(N+1)/2];


            for(int n=0;n<N;n++){
                ar[n%2][n/2]=IO2.readInt();
            }
            if(N%2==1)ar[1][ar[1].length-1]=Integer.MAX_VALUE;

            Arrays.sort(ar[0]);
            Arrays.sort(ar[1]);

            boolean ok=true;
            int wrongIndex=-1;
            for(int x=0;x<ar[0].length-1;x++){
                if(ar[0][x]>ar[1][x]){
                    ok=false;
                    wrongIndex=2*x;
                    break;
                }
                if(ar[1][x]>ar[0][x+1]){
                    ok=false;
                    wrongIndex=2*x+1;
                    break;
                }
            }

            if(ok)if(ar[0][ar[0].length-1]>ar[1][ar[0].length-1]){
                ok=false;
                wrongIndex=N-2;
            }

            //for(int x=0;x<ar[0].length;x++)System.out.print(ar[0][x]+" "+ar[1][x]+" ");
            //System.out.println();

            if(ok) IO2.print("Case #"+t+": "+"OK");
            else  IO2.print("Case #"+t+": "+wrongIndex);

        }
    }

}
