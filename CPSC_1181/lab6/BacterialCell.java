package lab6;


import java.awt.Color;
import java.awt.Graphics2D;
/**
 * WhiteCell is extention of Cell with red and a draw method
 * @author Shakir
 *
 */
public class BacterialCell extends Cell {
	
	private Color col; //override col from superclass

	/**
	 * 
	 * @param x x-coord
	 * @param y y-coord
	 * @param size - radius of cell
	 * @param color 
	 */
	public BacterialCell(int x, int y, int size, Color color) {
		super(x, y, size, color);
		this.col = color;
	}
	/**
	 *  draw method with overridden col 
	 *  @param graphics - graphics obj 
	 */
	public void draw(Graphics2D graphics) {        
        graphics.setColor(col);
        graphics.fillOval((int) (getX() - getSize()), (int) (getY() - getSize()), (int) (getSize() * 2), (int) (getSize() * 2));        
    }
	
	/**
	 * turn yell when being pulled
	 */
	public void turnYellow(){
		col = Color.YELLOW;
	}
	

}
