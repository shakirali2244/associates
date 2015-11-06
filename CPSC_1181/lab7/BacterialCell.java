

import java.awt.Color;
import java.util.ArrayList;


/**
 * Class representing the bactarial cell in the simulation
 * @author jmadar
 */
public class BacterialCell extends Cell {
    
	private int iteration=0; //count the iteration w.r.t. move called for bacteria
	/**
	 * call Cell constructor with red color and
	 * @param x x position
	 * @param y y position
	 * @param size radius of the cell
	 */
    public BacterialCell(int x, int y, int size) {
        super(x, y, size, Color.red);
    }

    /**
     * overriding move method with reproduction logic after the move and filling addCells
     */
    @Override
    public void move(ArrayList<Cell> cells, ArrayList<Cell> deleteCells, ArrayList<Cell> addCells) {
        super.move(cells, deleteCells, addCells);
        iteration++; // increasing the counter
        if (iteration%100 == 0){ //every 100th iteration for the cell do the following
        	int rand = (int) ((Math.random()*10) + 1); 
        	if (rand == 5){  //5 appears 10% in a random number generated from 1 to 10
        		
        		 // create a new cell and add to addCells list
        		addCells.add(new BacterialCell((int)this.getX(), (int)this.getY(), (int)this.getSize()));
        		
        		
        	}
        }
    }

}
