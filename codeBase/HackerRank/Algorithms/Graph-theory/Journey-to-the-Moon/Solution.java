/*
    gihanjayatilaka[at]eng[dot]pdn[dot]ac[dot]lk
    2017
    https://www.hackerrank.com/challenges/journey-to-the-moon/problem
    This submission passed all test cases
*/
import java.util.*;
class GraphNode{
	ArrayList<Integer> connectedTo;

	GraphNode(){
		connectedTo=new ArrayList<Integer>();
	}


	public void connectTo(int x){
		connectedTo.add(x);
	}

}



class Solution{
	static Scanner sc=new Scanner(System.in);
	static boolean[] covered;
	static GraphNode[] ar;
	static ArrayList<Integer> road;
	static ArrayList<Integer> sets=new ArrayList<Integer>();
	public static void main(String[] args){
		int N=sc.nextInt();
		int M=sc.nextInt();

		covered=new boolean[N];
		ar=new GraphNode[N];

		for(int z=0;z<N;z++)ar[z]=new GraphNode();

		for(int m=0;m<M;m++){
			int a=sc.nextInt();
			int b=sc.nextInt();

			ar[a].connectTo(b);
			ar[b].connectTo(a);
		}


		for(int x=0;x<N;x++){
			if(!covered[x]){
                //System.out.println(x+"*");
				road=new ArrayList<Integer>();
				dfs(x,road);
				sets.add(road.size());
                //System.out.println(x+" "+road.size());
			}
		}

		long ans=0;

		for(int x=0;x<sets.size();x++){
			ans+=sets.get(x);
		}
		ans*=ans;
		for(int x=0;x<sets.size();x++){
			ans-=Math.pow(sets.get(x),2);
		}
		System.out.println(ans/2);






	}





	public static void dfs(int x,ArrayList<Integer> road){
		covered[x]=true;
		road.add(x);
		for(int y=0;y<ar[x].connectedTo.size();y++){
			if(!covered[ar[x].connectedTo.get(y)]){
				dfs(ar[x].connectedTo.get(y),road);

			}
		}
	}



}



