package lab6;



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
    private int size = 10; //radius for cells      
    private int whiteCellsSize = 5; //number of white cells in program
    private int bacterialCellsSize = 50; //number of bacterial cells in the program
    /** Application manages one displaySystem */
    private DisplaySystem displaySystem;
    
    /** We keep track of all the cells in my simulation */
    private ArrayList<WhiteCell> whiteCells = new ArrayList<WhiteCell>();
    private ArrayList<BacterialCell> bacterialCells = new ArrayList<BacterialCell>();
    
    public Application() {
        // The DisplaySystem constructor requires a resolution
        displaySystem = new DisplaySystem(Application.WIDTH, Application.HEIGHT); 
        
        // Create all the cells in the simulation, scatter them randomly
        for (int i=0; i<whiteCellsSize; i++) 
        	whiteCells.add(new WhiteCell((int)(Math.random()*(WIDTH-size*2))+size, (int)(Math.random()*(HEIGHT-size*2))+size, size, Color.WHITE));
        for (int i=0; i<bacterialCellsSize; i++)
        	bacterialCells.add(new BacterialCell((int)(Math.random()*(WIDTH-size*2))+size, (int)(Math.random()*(HEIGHT-size*2))+size, size, Color.RED));
    }
    /**
     * start the application
     */
    private void start() {
        
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
            // Move all the white cells around
            for (int i = 0 ; i < whiteCells.size() ; i++){
            	WhiteCell wc = null;
            	wc = whiteCells.get(i);
            	wc.move(); //move white cell
            	
            	double distance = WIDTH+HEIGHT; //start to largest possible distance
            	int closest = 0; //index of closest bacteria cell
            	for ( int j = 0; j < bacterialCells.size(); j++ ){ //for every white cell check if bacteria needs to be pulled or killed
            		BacterialCell bc1 = bacterialCells.get(j);
            		for ( int k = 0; k < bacterialCells.size(); k++ ){ //for every bacterial cells bc1 check if it can reproduce
            			if ( j!=k ){ 
	            			BacterialCell bc2 = bacterialCells.get(k);
	            			double interCellDistance= Math.abs(bc1.getX() - bc2.getX()) + 
	                    			Math.abs(bc1.getY() - bc2.getY());
	            			if (interCellDistance<20){ //if close enough than reproduce 0.1% of times
	            				if(((int)(Math.random() * 1000)) == 500){ // 0.1 % probablity of reproducing i.e occurance of 500 index in 0-999 items 
		            				BacterialCell cell = new BacterialCell((int)bc1.getX(), (int)bc1.getY(), size, Color.RED);
		            				bacterialCells.add(cell); //add to arraylist
		            				displaySystem.addObject(cell); //add to display
	            				}
	            			}
            			}
            		}
            		if(i == 0)
            			bc1.move(); //move bacterial only once w.r.t white cells
            		double currentDistance= Math.abs(bc1.getX() - wc.getX()) + 
                			Math.abs(bc1.getY() - wc.getY());
            		
            		if (currentDistance < distance  && currentDistance > 20){ //finding the closest bacterial cellfor a white cell to follow
            			distance = currentDistance;
            			closest = j;
            		}
            		
            		// bacterial cell pulled to white
            		if(currentDistance < 100){
                    	double bcx = bc1.getX();
                    	double bcy = bc1.getY();
                    	double wcx = wc.getX();
                    	double wcy = wc.getY();
                    	double theta = Math.atan((wcy - bcy)
                    			/(wcx - bcx));
                    	if (bcy>wcy && bcx>wcx)
                    		bc1.setDirection(Math.PI/2-theta+Math.PI);
                    	else if (bcy>wcy && bcx<wcx)
                    		bc1.setDirection(Math.PI/2-theta);
                    	else if (bcy<wcy && bcx>wcx)
                    		bc1.setDirection(Math.PI/2-theta+Math.PI);
                    	else
                    		bc1.setDirection(Math.PI/2-theta);
                    	bc1.turnYellow();
                    	bc1.setSpeed(2);
                    }
                	
            		// bacterial cell being deleted
                    if(currentDistance < 20){
                    	bacterialCells.remove(j);
                    	displaySystem.removeObject(bc1);
                    }              		
            	}
            	
            	// white cell following closest bacterial cell
            	if(bacterialCells.size()>0){
	            	BacterialCell bc1 = bacterialCells.get(closest);
	               	double bcx = bc1.getX();
	                double bcy = bc1.getY();
	                double wcx = wc.getX();
	                double wcy = wc.getY();
	                double theta = Math.atan((wcy - bcy)
	                		/(wcx - bcx));
	                if (bcy>wcy && bcx>wcx)
	                	wc.setDirection(Math.PI/2-theta);
	                else if (bcy>wcy && bcx<wcx)
	                	wc.setDirection(Math.PI/2-theta+Math.PI);
	                else if (bcy<wcy && bcx>wcx)
	                	wc.setDirection(Math.PI/2-theta);
	                else
	                	wc.setDirection(Math.PI/2-theta+Math.PI);
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
