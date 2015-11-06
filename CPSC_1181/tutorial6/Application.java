


import java.awt.Color;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * The application skeleton.  This is the controller
 * to manage DisplaySystem and all the objects that
 * it displays.
 * 
 * @author jmadar
 */
public class Application {
    
    // Static final variables are constants that can be accessed
    // using Application.WIDTH and Application.HEIGHT
    public static final int WIDTH = 800;
    public static final int HEIGHT = 600;
    
    /** Application manages one displaySystem */
    public DisplaySystem displaySystem;
    public ArrayList<Cell> cells = new ArrayList<Cell>();
    
    public Application() {
        // The DisplaySystem constructor requires a resolution
        displaySystem = new DisplaySystem(Application.WIDTH, Application.HEIGHT); 
        
        int size = 10;
        
        
        for (int i=0; i<100; i++) {
            cells.add(new BacterialCell((int)(Math.random()*(800-size*2))+size, (int)(Math.random()*(600-size*2))+size, size));
        }
        
        for (int i=0; i<10; i++) {
            cells.add(new WhiteCell((int)(Math.random()*(800-size*2))+size, (int)(Math.random()*(600-size*2))+size, size));
        }
    }
    
    public void start() {
        
        for (Cell cell : cells) {
            displaySystem.addObject(cell);
        }
        
        // Create a list of deleteCells that will be used over and over again
        ArrayList<Cell> deleteCells = new ArrayList<Cell>();
        
        while (true) {
            
            
                        
            // Need to keep track of deleted cells in a list, and remove
            // after the loop -- this is to get around the issue of 
            // ConcurrentModificionException when trying to delete an item
            // inside a list during a for loop.
            //
            // We can also get around this issue by using Iterator
            
            for (Cell cell : cells) {
            	cell.move(cells, deleteCells);
                
            }
            
            for (Cell cell: deleteCells) {
                cells.remove(cell);
                displaySystem.removeObject(cell);
            }
            
            // Clear the list so it can be reuse in the next iteration
            deleteCells.clear();
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
