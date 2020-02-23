/*
    This code was written by UOP_IntElligence during ACES Precoders v8 2020
    hisnionline@gmail.com   muhammadh.aslamm@gmail.com  irfanmm96@gmail.com

*/
import java.io.*;
import java.util.*;

public class Solution {
    
    static int max(int x, int y){ 
        return (x > y) ? x : y;  
    }

    static int min(int x, int y){ 
        return (x > y) ? y : x;  
    }
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        
        String[] Str = sc.nextLine().split(" ");

        int n = Integer.parseInt(Str[0]);
        int m = Integer.parseInt(Str[1]);
        int k = Integer.parseInt(Str[2]);
        
        int[] matrix = new int[n];
        HashMap<Integer,Integer>[] path = new HashMap[n];
        int[][] dist = new int[n][1<<k];
        
        int itr = 0;

        while(itr<n) {
            int f = 0, j = sc.nextInt();
            while(j-->0){
                f |= 1 << (sc.nextInt() - 1);
            }
            matrix[itr] = f;
            path[itr] = new HashMap<Integer, Integer>();
            Arrays.fill(dist[itr], Integer.MAX_VALUE);
            itr++;
        }
        
        itr = 0;
        while(itr<m){
            int x = sc.nextInt()-1;
            int y = sc.nextInt()-1;
            int w = sc.nextInt();
            path[x].put(y, w);
            path[y].put(x, w);
            itr++;
        }
        
        PriorityQueue<Edge> que = new PriorityQueue<Solution.Edge>();
        que.add(new Edge(0, matrix[0], 0));
        while(!que.isEmpty()) {
            int i = que.peek().e;
            int f = que.peek().f;
            int w = que.poll().w;
            if(dist[i][f] < w) {
                continue;
            }
            
            for(int j : path[i].keySet()) {
                int planet = f|matrix[j];
                int time = w+path[i].get(j);
                if(dist[j][planet] > time) {
                    dist[j][planet] = time;
                    que.add(new Edge(j,planet,time));
                }
            }
            
        }
        
        int result = 100000000;
        for(int i = 0; i < 1<<k; i++) {
            for(int j = 0; j < 1<<k; j++) {
                if((i|j) == (1<<k)-1) {
                    result = min(result, max(dist[n-1][i], dist[n-1][j]));
                }
            }
        }
        System.out.println(result);
    }
    
    public static class Edge implements Comparable<Edge>{
        int e, f, w;

        public Edge(int e, int f, int w) {
            super();
            this.e = e;
            this.f = f;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            return this.w-o.w;
        }
    }
}