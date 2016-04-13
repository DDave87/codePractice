import java.util.*;
import java.lang.*;
import java.io.*;

class LeanStartupBar {

    private static Queue<Object> data = new LinkedList<Object>();
	
	static ArrayList menuItem = new ArrayList();
	static ArrayList prepTime = new ArrayList();
	static ArrayList orderTime = new ArrayList();
	
	public static void addMenu(String mi,int pt){
	 menuItem.add(mi);
	 prepTime.add(pt);
	  //System.out.println(mi+"-"+pt+"Added");
	}
	
    public static void main(String[] args) {
        addMenu("Sandwich",3);
        addMenu("Coffee",2);
        addMenu("Caramel",3);
        addMenu("Pizza",6);
        
        new Waiter().start();
        new Chef().start();
        
    }
 
    public static class Chef extends Thread {
        int temp;
        int pt;
        Chef() {
            super("Chef");
        }
        public void run() {
            for (;;) {
                try {
                    Thread.sleep(10000);
                } catch (Exception e) {
                    e.printStackTrace();
                }
 
                synchronized(data){
                Iterator it = data.iterator();
                while (it.hasNext()){
					temp = (int)it.next();
					pt = ((int)prepTime.get(temp-1))*1000;
					 try{Thread.sleep(pt);} catch (Exception e) { e.printStackTrace();}
					 Date date = new Date();
					  String str = String.format("%s%tr", "", date );
                    System.out.println(menuItem.get(temp-1)+"-"+str);
                }//while
                data.clear();
            }//synchro
        }//for
    }//run
}//class
 
    public static class Waiter extends Thread {
        Waiter() {
            super("Waiter");
        }
		Scanner sc = new Scanner(System.in);
		int ord_id;
		int number=sc.nextInt();
        public void run() {
            while (number>0) {
            	ord_id = sc.nextInt();
                try {
                    Thread.sleep(1000);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                data.add(ord_id);
                Date date = new Date();
				String str = String.format("%s%tr", "", date );
				orderTime.add(str);
                System.out.println("OrdID "+ord_id +" "+ menuItem.get(ord_id-1) +" Has received at "+str);
                number = number - 1;
            }//while
        }//run
    }//Thread
    
    
}//LeanStartupBar Class