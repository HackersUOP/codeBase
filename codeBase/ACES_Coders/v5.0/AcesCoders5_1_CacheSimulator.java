//https://www.hackerrank.com/contests/aces-coders-v5-1/challenges/cache-simulator
//Solution passed all test cases
import java.util.Scanner;
import java.util.ArrayList;
public class AcesCoders5_1_CacheSimulator {
    static Scanner sc=new Scanner(System.in);
    static ArrayList<String> variableName=new ArrayList();
    static ArrayList<Integer> variableLocation=new ArrayList();
    static int[][] ram;
    static String[] ramVariableName;
    static int[] cache;
    static int ramSize,cacheSize,cacheBlockSize,noOfCacheBlocks;
    static int cacheHit,cacheMiss,cacheCall;
    
    static ArrayList<String> callCommandList=new ArrayList();
    static ArrayList<String> declareCommandList=new ArrayList();

    
   public static void inputBasic(){
       String input=sc.nextLine();
       String[] inputSplit=input.split(" ");
       ramSize=Integer.parseInt(inputSplit[0]);
       cacheSize=Integer.parseInt(inputSplit[1]);
       cacheBlockSize=Integer.parseInt(inputSplit[2]);
       ram=new int[ramSize][3];
       ramVariableName=new String[ramSize];
       noOfCacheBlocks=cacheSize/cacheBlockSize;
       cache=new int[noOfCacheBlocks];
       
       for(int x=0;x<noOfCacheBlocks;x++) cache[x]=Integer.MAX_VALUE;
       
       cacheHit=0;
       cacheMiss=0;
       cacheCall=0;
   }
   
   public static void loadToCache(int location){
	   location=(location/cacheBlockSize)*cacheBlockSize;
       int x=(location/cacheBlockSize)%noOfCacheBlocks;
       cache[x]=location;
   }
   
   
   public static boolean checkCache(int location){
       
       boolean ans=false;
       for(int x=0;x<noOfCacheBlocks;x++){
           if(location>=cache[x]&&(location-cache[x])<cacheBlockSize){
               //System.out.println(location+"****"+x);
               ans=true;
               break;
           }
       }
       //System.out.println(ans);
       return ans;
   }
   
   public static void variableCall(String name){
       int location=variableLocation.get(variableName.indexOf(name));
       cacheCall++;
       if(checkCache(location)){
           cacheHit++;
           
//           System.out.println("hit "+name+cacheHit);
       }
       else{
           cacheMiss++;
           loadToCache(location);
//           System.out.println("miss "+name+cacheMiss);
       }
   }
   
   public static void variableDeclaration(int type,String name,int location){
       variableName.add(name);
       variableLocation.add(location);
       
       ram[location][0]=type;
       ramVariableName[location]=name;
       
       
   }
    
   public static void declarationCommand(String command){
       String[] commandSplit=command.split(" ");
       int type = 0;
       
       if(commandSplit[1].equals("int")) type=1;
       else if(commandSplit[1].equals("char")) type=2;
       else if(commandSplit[1].equals("float")) type=3;
       else if(commandSplit[1].equals("double")) type=4;
       
       variableDeclaration(type,commandSplit[0],Integer.parseInt(commandSplit[2]));
   }
   
   public static void declarationCommandMain(String command){
       if(command.trim().split(" ").length==3){
           declarationCommand(command);
       }
       else{
           int type=0;
           String typeTextInput="";
           String typeText=command.split(" ")[1].substring(0,1);
           int varSize=0;
           if(typeText.equals("i")){
               type=1;
               typeTextInput="int";
               varSize=4;
           }
           else if(typeText.equals("c")){
               type=2;
               typeTextInput="char";
               varSize=1;
           }
           else if(typeText.equals("f")){
               type=3;
               typeTextInput="float";
               varSize=4;
           }
           else if(typeText.equals("d")){
               type=4;
               typeTextInput="double";
               varSize=8;
           }
           
           String[] commandSplit=command.trim().split(" ");
           int size=Integer.parseInt(commandSplit[3]);
           int location=Integer.parseInt(commandSplit[2]);
           String arrayName=commandSplit[0];
           
           for(int x=0;x<size;x++){
               declarationCommand(arrayName+"["+x+"] "+typeTextInput+" "+(location+varSize*x));
           }
           
       }
   }
   
    public static void main(String[] args) {
        inputBasic();
        sc.nextLine();
        
        while(true){
            String inputLine=sc.nextLine().trim();
            if (inputLine.equals("")){
                break;
            }
            else{
                callCommandList.add(inputLine);
                
            }
        }

        while(sc.hasNext()){
            String inputLine=sc.nextLine().trim();
            declareCommandList.add(inputLine);
            
        }
        
        for(int x=0;x<declareCommandList.size();x++) declarationCommandMain(declareCommandList.get(x));
        
        for(int x=0;x<callCommandList.size();x++){
            variableCall(callCommandList.get(x));
        }
        
        System.out.print(cacheCall+" "+cacheHit+" "+cacheMiss);
    }
    
}
