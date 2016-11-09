package sparkappartifact;

import static spark.Spark.*;

import java.nio.channels.FileChannel.MapMode;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;
import java.util.Vector;
import java.util.function.BiConsumer;
import java.util.function.Consumer;

public class Main {
	
	static void display(int X) {
		System.out.println(X);
	}
	
	static void vecmaptest(Map<String, Integer> map){
		Vector<Map<String,Integer> > vecmapstrint = 
    			new Vector<Map<String, Integer>>();
    	
    	for(int a=0; a<100;a++){
    		vecmapstrint.add(map);
    	};
	}
	
    public static void main(String[] args) {
    	Vector<Integer> vec = new Vector<>();

    	vec.addAll(Arrays.asList(1,2,3,4,5,6,7,8,9,10));
    	vec.add(5,105);
    	vec.add(11);
    	
    	Consumer<Integer> func = x->display(x);
    	
    	vec.forEach(func);
        
    	Map<String, Integer> map = new TreeMap<>();    	
    	
    	map.put("One", 1);
    	map.put("Two", 2);
    	map.put("Three",3);
    	
    	map.put("Four",7);
    	
    	map.replace("Four", 4);
    	
    	BiConsumer<String,Integer> funmap = (x,y)->{
    		System.out.println(x+"->"+y);
    		};
    	
    	map.forEach(funmap);
    	
    	for(int a=0; a<100000;a++){
    		vecmaptest(map);
    	};
    	
    	
    	int a[][] = {{1,2,3,4},{1,2,3},{},{9,9}};
    	
    	System.out.println("a.size:" + a.length);
    	
    	for (int[] is : a) {
			for (int i : is) {
				System.out.print(i + " ");
			}
			System.out.println( "; sz=" + is.length);		
    	}
    	
    	
    	get("/hello", (req, res) -> "Hello World");
    }
}