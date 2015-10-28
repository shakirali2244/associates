

import java.util.ArrayList;

/**
 * The application skeleton.  This is the controller
 * to manage DisplaySystem and all the objects that
 * it displays.
 * 
 * @author jmadar
 */
public class Application {
    
    /** Application manages one displaySystem */
    private DisplaySystem displaySystem;
    
    
    public Application() {
        // The DisplaySystem constructor requires a resolution
        displaySystem = new DisplaySystem(1000 , 700);
    }
    
    public void start() {        
        // We do our drawing here
    	ArrayList<Shape3Animated> arr = new ArrayList<Shape3Animated>();
    	for (int i = 0 ; i < 20 ; i++){
    		Shape3Animated temp = new Shape3Animated((int) (Math.random()*1000),
    				(int) (Math.random()*700),
    				(int) (Math.random()*20)+10);
    		arr.add(temp);
    	}
    	// The animation loop
    	while (true) {
    		
    		for(int i = 0 ; i < arr.size(); i++){
    			Shape3Animated temp = arr.get(i);
    			displaySystem.addObject(temp);
	    		// update the location of the animatedShape
    			temp.move((int) (Math.random()*360),
    					(Math.random()*10));
    			
	    		// refresh will update the window at 60 fps
	    		displaySystem.refresh();
	    		arr.set(i,temp);
    		}    		
    	}        
    }
    
    /**
     * Main entry point, simply start the application
     */
    public static void main(String[] args) {
        Application app = new Application();
        app.start();
    }
    
}
