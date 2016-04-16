/*

Copyright Hackers' Club, University Of Peradeniya
Author : Gihan Chanaka Jayatilaka (E/4/158)
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

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
