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
      
    private static int minCost(int cost[][], int m, int n){ 
        int i, j; 
        int tc[][]=new int[m+1][n+1]; 
  
        tc[0][0] = cost[0][0]; 
  
        for (i = 1; i <= m; i++) 
            tc[i][0] = tc[i-1][0] + cost[i][0]; 
  
        for (j = 1; j <= n; j++) 
            tc[0][j] = tc[0][j-1] + cost[0][j]; 
  
        for (i = 1; i <= m; i++) 
            for (j = 1; j <= n; j++) 
                tc[i][j] = max(tc[i-1][j], tc[i][j-1]) + cost[i][j]; 
  
        return tc[m][n]; 
    } 

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int ROW = scanner.nextInt();
        int [][] arr = new int[ROW][ROW];
        
        for(int i=0;i<ROW;i++){
            for(int j=0;j<ROW;j++){
                arr[i][j] = scanner.nextInt();      
            }
        }    
        
        System.out.print( minCost(arr, ROW-1, ROW-1));
    }
}