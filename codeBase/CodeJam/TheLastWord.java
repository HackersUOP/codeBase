package codeJam;
import java.util.Scanner;
public class TheLastWord {
	static Scanner sc=new Scanner(System.in);
	static String inputLine,outputLine;
	static char firstLetter,next; 
	static int testCases;
	public static void runOnce(int caseNo){
		inputLine=sc.nextLine();
		firstLetter=inputLine.charAt(0);
		outputLine=""+firstLetter;
		for(int x=1;x<inputLine.length();x++){
			next=inputLine.charAt(x);
			if(next<firstLetter) outputLine=outputLine+next;
			else{
				outputLine=next+outputLine;
				firstLetter=next;
			}
			//last=next;
		}
		System.out.println("Case #"+caseNo+": "+outputLine);
	}
	public static void main(String[] args){
		testCases=Integer.parseInt(sc.nextLine());
		for(int caseNo=0;caseNo<testCases;caseNo++) runOnce(caseNo+1);
	}
}
