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
public class RankAndFile {

	static Scanner sc=new Scanner(System.in);
	public static void main(String[] runOnce){
		int testCases=Integer.parseInt(sc.nextLine());
		for(int caseNo=0;caseNo<testCases;caseNo++) runOnce(caseNo+1);
	}
	public static void runOnce(int caseNo){
		int N;
		boolean[] height=new boolean[2501];
		int[] remainingPeople,arrangedPeople;
		
		int currentRead,ram1,ram2,z;
		
		
		N=Integer.parseInt(sc.nextLine());
		for(int y=0;y<((2*N)-1);y++){
			for(int x=0;x<N;x++){
				currentRead=sc.nextInt();
				/*
				if(height[currentRead]) System.out.println("removing "+currentRead);
				else System.out.println("adding "+currentRead);*/
				height[currentRead]=!height[currentRead];	
			}
			sc.nextLine();
		}
		remainingPeople=new int[N];
		int y=0;
		for(int x=0;x<2501;x++){
			if(height[x]){
				remainingPeople[y]=x;
				y++;
			}
		}
		ram1=Integer.MAX_VALUE;
		
		for(int x=0;x<N;x++) if(remainingPeople[x]<ram1) ram1=remainingPeople[x];
		arrangedPeople=new int[N];
		arrangedPeople[0]=ram1;
		
		for(y=1;y<N;y++){
			ram2=Integer.MAX_VALUE;
			for(int x=0;x<N;x++){
				z=remainingPeople[x];
				if(z<ram2&&z>ram1){
					ram2=z;
				}
			}
			arrangedPeople[y]=ram1=ram2;
		}
		System.out.print("Case #"+caseNo+": ");
		for(y=0;y<N;y++){
			System.out.print(arrangedPeople[y]);
			if(y!=N-1) System.out.print(" ");
		}
		System.out.println("");
	}
}
