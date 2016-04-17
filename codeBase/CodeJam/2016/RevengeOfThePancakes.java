/*

Copyright Hackers' Club, University Of Peradeniya
Author : Gihan Chanaka Jayatilaka (E/14/158)
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
public class RevengeOfThePancakes {
	static Scanner sc=new Scanner(System.in);

	public static boolean[] readArray(String s){
		boolean[] ans=new boolean[s.length()];
		for(int x=0;x<s.length();x++) if(s.charAt(x)=='+') ans[x]=true;
		//System.out.println("readingFinished");
		return ans;
	}
	
	public static void runOnce(int caseNo){
		String inputLine=sc.nextLine();
		System.out.println("Case #"+(caseNo+1)+": "+noOfTurns(readArray(inputLine)));
	}
	
	public static void main(String[] args){
		int cases=Integer.parseInt(sc.nextLine());
		for(int caseNo=0;caseNo<cases;caseNo++) runOnce(caseNo);
	}
	
	public static int noOFSegments(boolean[] ar){
		boolean current=ar[ar.length-1];
		int blocks=1;
		for(int x=ar.length-1;x>-1;x--){
			if(current!=ar[x]){
				blocks++;
				current=!current;
			}
		}
		return blocks;
	}
	
	public static int noOfTurns(boolean[] ar){
		int ans=noOFSegments(ar);
		if(ans==1&&ar[0]) ans--;
		else if(ar[ar.length-1]) ans--;
		return ans;
	}
}
