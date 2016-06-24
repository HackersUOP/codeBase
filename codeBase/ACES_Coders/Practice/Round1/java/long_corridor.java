/*
Copyright @gihanchanaka
*/

import java.util.Scanner;
import java.util.ArrayList;


class HackersClub_LongCorridor {

	public static void main(String[] args){
        Scanner inp=new Scanner(System.in);
		int N=inp.nextInt();
		int[] x=new int[N];
		int[] v=new int[N];
		double[] t=new double[N];
		double currentMax=-1.0;
		int count=0;
		for(int i=0;i<N;i++){
			x[i]=inp.nextInt();
			v[i]=inp.nextInt();
			t[i]=(double)x[i]/(double)v[i];
			if(t[i]-currentMax>0.000000000000001){
				count++;
				currentMax=t[i];
			}
		}
		System.out.println(count);
	}
	
}
