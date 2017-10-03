/*
Copyright @gihanchanaka
*/
import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;


class HackersClub_NumberPyramid {
	public static void main(String[] args){
		Scanner inp=new Scanner(System.in);
		int N=inp.nextInt();
		int [][] ar=new int[N][N];
		int [][] branchSum=new int[N][N];
		for(int x=0;x<N;x++){
			int [] temp =new int[x+1];
			for(int y=0;y<x+1;y++) temp[y]=inp.nextInt();
			ar[x]=temp;
		}
		branchSum[N-1]=ar[N-1];
		for(int level=N-2;level>=0;level--){
			for(int x=0;x<level+1;x++){
				branchSum[level][x]=ar[level][x]+Math.max(branchSum[level+1][x], branchSum[level+1][x+1]);
				
			}
		}
		System.out.println(branchSum[0][0]);
	}
	

}




