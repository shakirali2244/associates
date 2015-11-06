

import java.awt.Color;
import java.util.ArrayList;

/**
 * Class representing the White cell in the simulation
 * @author jmadar
 */
public class WhiteCell extends Cell {
	
	/** the distance of influence of the tractor beam */
    private int tractor = 100;
    
    /**
     * call Cell constructor with blue color and
     * @param x x position
     * @param y y position
     * @param size radius of the cell
     */
    public WhiteCell(int x, int y, int size) {
        super(x, y, size, Color.blue);
    }

    /**
     * move method to take care of movement and characteristics od white cells
     */
    @Override
    public void move(ArrayList<Cell> cells, ArrayList<Cell> deleteCells, ArrayList<Cell> addCells) {
        super.move(cells, deleteCells, addCells); //actually move the cell
        double distance = Application.WIDTH+Application.HEIGHT; //start to largest possible distance
        int closest = 0; //index of closest bacteria cell
        boolean found = false; //if closest bacterial cell is ever found so that simulation dosent break when all of them die
        for (int i = 0; i < cells.size(); i++) { 
        	Cell cell = cells.get(i);
            if (cell instanceof BacterialCell) {// for every White cell do the following for every other bacterial cell
            	double currentDistance=this.distance(cell); 
            	
            	//cell needs to get pulled to this White cell
            	if(currentDistance < tractor){
                	double bcx = cell.getX();
                	double bcy = cell.getY();
                	double wcx = this.getX();
                	double wcy = this.getY();
                	double theta = Math.atan((wcy - bcy)
                			/(wcx - bcx));
                	if (bcy>wcy && bcx>wcx)
                		cell.setDirection(Math.PI/2-theta+Math.PI);
                	else if (bcy>wcy && bcx<wcx)
                		cell.setDirection(Math.PI/2-theta);
                	else if (bcy<wcy && bcx>wcx)
                		cell.setDirection(Math.PI/2-theta+Math.PI);
                	else
                		cell.setDirection(Math.PI/2-theta);
                	cell.setColor(Color.YELLOW);
                	cell.setSpeed(2);
                }
            	
                // cell needs to disappear
            	if(currentDistance < this.getSize()+cell.getSize())
            		deleteCells.add(cell);
            	
            	// if a closer bacterial cell is found from the last
            	if(currentDistance < distance){
            		found = true;
            		distance = currentDistance;
        			closest = i;
            	}
            }
        }
        
        // make this White cell go towards the closest bacterial cell from the list
        if (found){
        	Cell bc1 = cells.get(closest);
            double bcx = bc1.getX();
            double bcy = bc1.getY();
            double wcx = this.getX();
            double wcy = this.getY();
            double theta = Math.atan((wcy - bcy)
            		/(wcx - bcx));
            if (bcy>wcy && bcx>wcx)
                this.setDirection(Math.PI/2-theta);
            else if (bcy>wcy && bcx<wcx)
                this.setDirection(Math.PI/2-theta+Math.PI);
            else if (bcy<wcy && bcx>wcx)
                this.setDirection(Math.PI/2-theta);
            else
                this.setDirection(Math.PI/2-theta+Math.PI);
        }
        
    	  
    }   
}
