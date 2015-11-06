

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
    /** Arraylist to manage all types of cells */
    public ArrayList<Cell> cells = new ArrayList<Cell>(); 
    
    /**
     * Constructor to fill the cells list
     */
    public Application() {
        // The DisplaySystem constructor requires a resolution
        displaySystem = new DisplaySystem(Application.WIDTH, Application.HEIGHT); 
        
        int size = 10; // size of cells
        
        //fill bacterial cells in top part
        for (int i=0; i<100; i++) {
            cells.add(new BacterialCell((int)(Math.random()*(800-size*2))+size, (int)(Math.random()*400), size));
        }
        
        //fill white cells in the bottom part
        for (int i=0; i<10; i++) {
            cells.add(new WhiteCell((int)(Math.random()*(800-size*2))+size,(int)(Math.random()*80)+ 500 , size));
        }
        
        //fill obstacles in the middle
        for (int i=0; i<50; i++) {
            cells.add(new Obstacle((int)(Math.random()*(800-size*2))+size,(int)(Math.random()*50) + 400  , size));
        }
    }
    
    public void start() {
        
    	//fill the display
        for (Cell cell : cells) {
            displaySystem.addObject(cell);
        }
        
        // Create a list of deleteCells that will be used over and over again
        ArrayList<Cell> deleteCells = new ArrayList<Cell>();
        
        // Create a list of addCells that will be used to add to cells
        ArrayList<Cell> addCells = new ArrayList<Cell>();
        
        while (true) {
            //call move methods for all cells
            for (Cell cell : cells) {
                cell.move(cells, deleteCells, addCells);
            }
            
            //remove marked cells
            for (Cell cell: deleteCells) {
                cells.remove(cell);
                displaySystem.removeObject(cell);
            }
            
            //add reproduced cells
            for (Cell cell: addCells) {
                cells.add(cell);
                displaySystem.addObject(cell);
            }
            
            // Clear the lists so they can be reuse in the next iteration
            deleteCells.clear();
            addCells.clear();
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
