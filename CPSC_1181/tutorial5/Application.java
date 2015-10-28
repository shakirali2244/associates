

import java.awt.Color;
import java.util.ArrayList;

/**
 * The application skeleton.  This is the controller
 * to manage DisplaySystem and all the objects that
 * it displays.
 * 
 * @author jmadar
 */
public class Application {
    
    // Static final variables are constants that can be accessed
    // using Application.WIDTH and Application.HEIGHT from anywhere
    // within your code
    public static final int WIDTH = 800;
    public static final int HEIGHT = 600;
    
    /** Application manages one displaySystem */
    public DisplaySystem displaySystem;
    
    /** We keep track of all the cells in my simulation */
    public ArrayList<WhiteCell> whiteCells = new ArrayList<WhiteCell>();
    public ArrayList<BacterialCell> bacterialCells = new ArrayList<BacterialCell>();
    
    public Application() {
        // The DisplaySystem constructor requires a resolution
        displaySystem = new DisplaySystem(Application.WIDTH, Application.HEIGHT); 
        
        // Create all the cells in the simulation, scatter them randomly
        int size = 10;        
        for (int i=0; i<100; i++) {
        	whiteCells.add(new WhiteCell((int)(Math.random()*(WIDTH-size*2))+size, (int)(Math.random()*(HEIGHT-size*2))+size, size, Color.WHITE));
        	bacterialCells.add(new BacterialCell((int)(Math.random()*(WIDTH-size*2))+size, (int)(Math.random()*(HEIGHT-size*2))+size, size, Color.RED));
        }        
    }
    
    public void start() {
        
        // Need to add all the cells into the displaySystem so
        // they will be rendered on screen
        for (Cell cell : whiteCells) {
            displaySystem.addObject(cell);
        }
        for (Cell cell : bacterialCells) {
            displaySystem.addObject(cell);
        }
                
        // The main loop
        while (true) {
            // Move all the cells around
            for (int i = 0 ; i < whiteCells.size() ; i++){
            	WhiteCell wc = whiteCells.get(i);
            	if (bacterialCells.size() > i){
            		BacterialCell bc = bacterialCells.get(i);
            		bc.move();
            	}            	
            	wc.move();
            	
            	for ( int j = 0; j < bacterialCells.size(); j++ ){
            		BacterialCell bc1 = bacterialCells.get(j);
            		double distance = Math.abs(bc1.getX() - wc.getX()) + 
                			Math.abs(bc1.getY() - wc.getY());
                	
                    if(distance < 20){
                    	bc1.dissappear();
                    	bacterialCells.remove(j);
                    	System.out.println("KILLING");
                    	System.out.println(distance);
                    } 
            		
            	}
            }
            
            // Show it on screen, refresh() will update the screen
            // at most 60 frames per second
            displaySystem.refresh();
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
