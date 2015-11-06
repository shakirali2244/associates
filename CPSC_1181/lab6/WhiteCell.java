import java.awt.Color;
import java.awt.Graphics2D;

/**
 * WhiteCell is extention of Cell with white color and a draw method
 * @author Shakir
 *
 */
public class WhiteCell extends Cell {
	
	private Color col; //override col from superclass
	
	/**
	 * 
	 * @param x x-coord
	 * @param y y-coord
	 * @param size - radius of cell
	 * @param color 
	 */
	public WhiteCell(int x, int y, int size, Color color) {
		super(x, y, size, color);//init a Cell with passed color and x,y
		this.col = color; //save color locally too for draw
	}
	
	/**
	 *  draw method with overridden col 
	 * @param graphics - graphics obj 
	 */
	public void draw(Graphics2D graphics) {        
        graphics.setColor(col);
        graphics.fillOval((int) (getX() - getSize()), (int) (getY() - getSize()), (int) (getSize() * 2), (int) (getSize() * 2));        
    }

	
	

}
