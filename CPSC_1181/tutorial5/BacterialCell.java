
import java.awt.Color;
import java.awt.Graphics2D;

public class BacterialCell extends Cell {
	
	private Color col;

	public BacterialCell(int x, int y, int size, Color color) {
		super(x, y, size, color);
		this.col = color;
		// TODO Auto-generated constructor stub
	}
	
	public void draw(Graphics2D graphics) {        
        graphics.setColor(col);
        graphics.fillOval((int) (getX() - getSize()), (int) (getY() - getSize()), (int) (getSize() * 2), (int) (getSize() * 2));        
    }
	
	public void dissappear(){
		col = new Color(0, 0, 0, 0);
	}
	

}
