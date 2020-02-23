/*
    This code was written by UOP_eyeCoders during ACES Precoders v8 2020
    thusharakart@gmail.com  nuwan.harshamatrix@gmail.com    thilankanayana@gmail.com

*/
import java.io.*;
import java.util.*;

public class Solution {
    public static void sortbyColumn(int arr[][], int col) 
    { 
        // Using built-in sort function Arrays.sort 
        Arrays.sort(arr, new Comparator<int[]>() { 
            
          @Override              
          // Compare values according to columns 
          public int compare(final int[] entry1,  
                             final int[] entry2) { 
  
            // To sort in descending order revert  
            // the '>' Operator 
            if (entry1[col] > entry2[col]) 
                return 1; 
            else
                return -1; 
          } 
        });  // End of function call sort(). 
    }
    static int timeConvert(String date){
        String[]arr=date.split(":");
        int a=100*Integer.parseInt(arr[0]);
        int b = Integer.parseInt(arr[1]);
        return a+b;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        in.nextLine();
        String[][]arr = new String[t][3];
        
        int size = 0,index = 0;
        for(int i=0;i<t;i++){
            String[] temp = in.nextLine().split(" ");
            arr[i][0] = temp[0];
            arr[i][1] = temp[1];
            arr[i][2] = temp[2];
            
            if(temp[0].compareTo("Y")==0){
                size++;
            }
        }
        int[][]brr = new int[size][2];
        for(int i=0;i<t;i++){
            if(arr[i][0].compareTo("Y")==0){
                brr[index][0] = timeConvert(arr[i][1]);
                brr[index][1] = timeConvert(arr[i][2]);
                index++;
            }
            
        }
        sortbyColumn(brr,1);
        // for(int h=0;h<brr.length;h++){
        //     // System.out.println(Arrays.toString(brr[h]));
        // }
        int last=brr[0][1];
        int temp=1;
        for(int k = 1;k<size;k++){
            if(brr[k][0]>=last){
                temp++;
                last =brr[k][1];
            }
            
 
        }
        System.out.println(temp);
        

    }
}