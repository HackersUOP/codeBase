/*
    gihanjayatilaka[at]eng[dot]pdn[dot]ac[dot]lk
    2016
    https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem
    This submission passed all test cases
*/
import java.util.Scanner;
public class HackerRank_Floyd {
	static Scanner sc=new Scanner(System.in);
	
	public static void main(String[] args){
		runOnce();
	}
	
	public static void runOnce(){
		int N=sc.nextInt();
		int M=sc.nextInt();
		
		WeightedGraph graph=new WeightedGraph(N);
		
		for(int x=0;x<M;x++){
			int start=sc.nextInt()-1;
			int end=sc.nextInt()-1;
			int weight=sc.nextInt();
			sc.nextLine();
			graph.addDirectedEdgeNewEdgeReplacesOld(start, end, weight);
		}
		int[][] answers=new int[N][N];
		
		for(int x=0;x<N;x++) answers[x]=Dijkstra.minDistances(graph, x);
		
        
		int Q=Integer.parseInt(sc.nextLine());
		for(int x=0;x<Q;x++){
			int start=sc.nextInt()-1;
			int end=sc.nextInt()-1;
			if(sc.hasNext()) sc.nextLine();
			int ans=answers[start][end];
			if(ans==Integer.MAX_VALUE) System.out.println(-1);
			else System.out.println(ans);
            
            

		}
	}
}



class Dijkstra {
	
	
	public static int[] minDistances(WeightedGraph g, int startNode){
		int[] minDistances=new int[g.size()];
		for(int x=0;x<minDistances.length;x++) minDistances[x]=Integer.MAX_VALUE;
		int currentNode=startNode;
		minDistances[currentNode]=0;
		boolean[] visitedNodes=new boolean[g.size()];
		
		
		while(unvisitedNodesRemain(visitedNodes,minDistances)){
			currentNode=unvisitedMinDistance(minDistances,visitedNodes);
			//System.out.println(currentNode);
			visitedNodes[currentNode]=true;
			for(int x=0;x<g.size();x++){
				if(g.isConnected(currentNode, x)){
					minDistances[x]=Math.min(minDistances[x], minDistances[currentNode]+g.getWeight(currentNode, x));
				}
			}
		}
		return minDistances;
	}
	
	public static int unvisitedMinDistance(int[] minDistances,boolean visitedNodes[]){
		//returns the node number of the unvisited min distance
		//returns -1 when all nodes are visited
		int nodeNo=-1;
		int minDistance=Integer.MAX_VALUE;
		for(int x=0;x<minDistances.length;x++){
			if(!visitedNodes[x] && minDistance>=minDistances[x]){
				nodeNo=x;
				minDistance=minDistances[x];
			}
		}
		return nodeNo;
	}
	
	public static boolean unvisitedNodesRemain(boolean[] visitedNodes,int[] minDistances){
		boolean ans=false;
		for(int x=0;x<visitedNodes.length;x++){
			if(!visitedNodes[x]&minDistances[x]!=Integer.MAX_VALUE){
				ans=true;
				break;
			}
		}
		return ans;
	}
	
	
}


class WeightedGraph {
	int noOfVertices;
	boolean[][] edges;
	int[][] edgeWeights;
	
	WeightedGraph(int noOfVertices){
		this.noOfVertices=noOfVertices;
		edges=new boolean[noOfVertices][noOfVertices];
		edgeWeights=new int[noOfVertices][noOfVertices];
		for(int x=0;x<noOfVertices;x++)for(int y=0;y<noOfVertices;y++)if(x!=y) edgeWeights[x][y]=Integer.MAX_VALUE;
	}
	
	public void addEdgeDirected(int start,int end,int weight){
		edges[start][end]=true;
		edgeWeights[start][end]=Math.min(edgeWeights[start][end], weight);
	}
	
	public void addDirectedEdgeNewEdgeReplacesOld(int start,int end,int weight){
		edges[start][end]=true;
		edgeWeights[start][end]=weight;
	}
	
	public void addEdgeUndireectde(int start,int end, int weight){
		addEdgeDirected(start,end,weight);
		addEdgeDirected(end,start,weight);
	}
	
	public int getWeight(int start,int end){
		if(edges[start][end]) return edgeWeights[start][end];
		else return Integer.MAX_VALUE;
	}
	
	public boolean isConnected(int start,int end){
		return edges[start][end];
	}
	
	public int size(){
		return noOfVertices;
	}
}
