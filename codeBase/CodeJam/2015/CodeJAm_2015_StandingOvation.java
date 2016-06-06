
public class CodeJAm_2015_StandingOvation {
	
	public static void main(String[] args){
		int cases=IO.readIntLine();
		for(int x=0;x<cases;x++) runOnce(x+1);
	}
	
	public static void runOnce(int n){
		String inLine=IO.readLine();
		
		int sMax=Integer.parseInt(inLine.substring(0, inLine.indexOf(" ")));
		int[] s=new int[sMax+1];
		
		for(int x=inLine.indexOf(" ")+1;x<inLine.length();x++) s[x-(inLine.indexOf(" ")+1)]=Integer.parseInt(inLine.substring(x,x+1));
		
		int currentShyness=0;
		int currentStanding=0;
		int currentOutsiders=0;
		
		while(currentShyness<=sMax){
			if(currentShyness+1<=currentStanding+s[currentShyness]){
				currentStanding+=s[currentShyness];
			}
			else{
				currentStanding++;
				currentOutsiders++;
			}
			currentShyness++;
		}
		IO.print("Case #"+n+": "+currentOutsiders);
	}	
}
