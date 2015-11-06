
import java.awt.Color;
import java.util.ArrayList;

/**
 * class representation the obstacle in the simulation
 * @author Shakir
 *
 */
public class Obstacle extends Cell {

	/**
	 * call Cell with passd params and white color
	 * @param x x position
	 * @param y y position
	 * @param size radius of the cell
	 */
	public Obstacle(int x, int y, int size) {
		super(x, y, size, Color.white);
	}
	
	/**
	 * for move override the superclass move and dont acutally move
	 * but set the direction of the cells hitting the obstacle to 
	 * move away and move them away
	 */
	public void move(ArrayList<Cell> cells, ArrayList<Cell> deleteCells, ArrayList<Cell> addCells) {
		for (Cell cell:cells){
        	if (!(cell instanceof Obstacle) && this.distance(cell) <= this.getSize() + cell.getSize()+1){
        		cell.setDirection(cell.getDirection() + Math.PI/(Math.random()/10+1));
        		cell.setX(cell.getX() + Math.sin(cell.getDirection()) * cell.getSpeed());
        		cell.setY(cell.getY() + Math.cos(cell.getDirection()) * cell.getSpeed());
        	}
        }
	}
	

}
