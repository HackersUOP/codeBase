import java.util.Arrays;

//Greedy technique
public class CodeJam_2008_SavingTheUniverse {
	
	public static void main(String[] args){
		int C=IO.readIntLine();
		for(int c=1;c<=C;c++) runOnce(c);
	}
	
	public static void runOnce(int caseNo){
		int noOfSearchEngines=IO.readIntLine();
		String[] searchEngine=IO.readStringArray(noOfSearchEngines);
		int Q=IO.readIntLine();
		String[] query=IO.readStringArray(Q);
		
		//IO.print(searchEngine);
		//IO.print(query);
		
		
		int maxQueries=0;
		int searchEngineChanges=0;
		while(query.length!=0){
			query=Array.crop(query, maxQueries);
			int[] times=whenScomesinQ(searchEngine,query);
			for(int x=0;x<times.length;x++) if(times[x]==-1) times[x]=Integer.MAX_VALUE;
			if(Array.max(times)>=query.length) break;
			maxQueries=Array.max(times);
			searchEngineChanges++;
		
		}
				
		IO.printCodeJamStyle(caseNo, searchEngineChanges);
	}
	
	
	public static int[] whenScomesinQ(String[] s,String[] q){
		int[] ans=Array.array(s.length, Integer.MAX_VALUE);
		for(int x=0;x<s.length;x++){
			ans[x]=Array.indexOf(q, s[x]);
		}
		return ans;
	}
	
	
	
	
}
