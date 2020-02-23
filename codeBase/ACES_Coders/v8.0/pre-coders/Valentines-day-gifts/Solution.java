/*
    gihanjayatilaka[at]eng[dot]pdn[dot]ac[dot]lk
 */
import javax.sound.midi.SysexMessage;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

class Gift implements Comparable<Gift>{
    String name;
    float radius;

    Gift(String name,float radius){
        this.name=name;
        this.radius=radius;
    }

    public int compareTo(Gift p){
        return Float.compare(this.radius,p.radius);
    }

}


public class Solution {
    static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        int N=Integer.parseInt(sc.nextLine());

        Gift[] gifts=new Gift[N];
//        String[] names=new String[N];
//        float[] radius=new float[N];

        for(int i=0;i<N;i++){

            String[] temp=sc.nextLine().trim().split(" ");
            gifts[i]=new Gift(temp[0].trim(),Float.parseFloat(temp[1].trim()));
        }


        Arrays.sort(gifts);


//        for(int i=0;i<gifts.length;i++){
//            System.out.println(gifts[i].name+" "+gifts[i].radius);
//        }


        HashSet<String> names=new HashSet<>();

        for(int i=0;i<gifts.length;i++){
            names.add(gifts[i].name);

        }

        int totalNames=names.size();

        int ans=1;
        names=new HashSet<>();

        for(int i=0;i<gifts.length;i++){
            names.add(gifts[i].name);
            if(names.size()==totalNames){
                ans+=1;
                names=new HashSet<>();
            }
        }

        System.out.println(ans);



    }
}
