import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.HashMap.*;


/* Name of the class has to be "Main" only if the class is public. */
class brands{
	String brandName;
	protected Map<String, Integer> keywordRank = new HashMap<String, Integer>();
	
	public brands(String bn){
		this.brandName = bn;
	}
	public void printBrandName(){
		System.out.println("Brand Name"+brandName);
	}//printBrandName
	
	public void setKeywordRank(Vector V, Integer numOfViews){
		for(Iterator it = V.iterator();it.hasNext();){
			String kw= (String)it.next();
			keywordRank.put(kw,numOfViews);
		}
	}
	
	public void printBrandMap(){
		Iterator it = keywordRank.keySet().iterator();
		while(it.hasNext()){
		 String keyword   = (String)it.next();
		 Integer rank = keywordRank.get(keyword);
		 System.out.println("KeyWord"+keyword+"= Rank"+rank);
		}//while
	}//printBrandMap
	
	//sort Keyword-Views Map based upon its views in decending vay.
	public static <K extends Comparable,V extends Comparable> Map<K,V> sortMapByValues(Map<K,V> map){
        List<Map.Entry<K,V>> entries = new LinkedList<Map.Entry<K,V>>(map.entrySet());
        Collections.sort(entries, new Comparator<Map.Entry<K,V>>() {
           //Override
           public int compare(Map.Entry<K, V> o1, Map.Entry<K, V> o2) {
               return o2.getValue().compareTo(o1.getValue());
               //return in reverse order larger first.
           }
        });
       Map result = new LinkedHashMap();
       for (Iterator it = entries.iterator(); it.hasNext();) {
       Map.Entry entry = (Map.Entry)it.next();
       result.put(entry.getKey(), entry.getValue());
		}//for 
    return result;
    
    }//sortMapByValues
	
	//keep Get and Set methods
}
class video extends brands{
	
	String videoName;
	Integer numOfViews;
	//keep brandname here and map it with its object in brandObjectMap.
	String bname; 
	//brand Name - Brand Object Map
	Map<String, brands >brandObjectMap = new HashMap<String, brands >();
	//store all keywords of video in Vector called keywords
	Vector<String> keywords = new Vector<String>();
	
	//keep Get and Set methods
	public void setVideoNm(String vn){
		videoName=vn;
	}
	
	public video(String bn){
		super(bn);
	}
	public void setBrandNm(String bn){
		
		if (brandObjectMap.containsKey(bn)){
			brands b = brandObjectMap.get(bn);
		
			for(Iterator i = keywords.iterator();i.hasNext();){
				String kw = (String)i.next();
			    if(keywordRank.containsKey(kw)){
			    	Integer oldview = keywordRank.get(kw);
			    	oldview += numOfViews;
			    	keywordRank.put(kw,oldview);
			    }//if
			    else{
			    	keywordRank.put(kw,numOfViews);
			    }//else
				
			}//for
		}
		//if not
		//create object of brand.
		else{
			brands b = new brands(bn);
			b.setKeywordRank(keywords,numOfViews);
			brandObjectMap.put(bn,b);//update curretn brandObjectMAp
			}
			
		//create map of bn-object.
		//set all keywords of this video to this brand's keywords with viewNumber
	}
	
	public void printBrandKeywordswithRank(String bn){
		if(brandObjectMap.containsKey(bn)){
			brands b = brandObjectMap.get(bn);
			b.printBrandMap();
		}
		else{
			System.out.println("This brand Doesnot exist");
		}
	}
	public static void main(String[] args){
		
	}
}
