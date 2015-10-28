
import java.awt.Graphics2D;
import java.awt.geom.Rectangle2D;

public class Shape3 extends Shape2 {
	
	private double x2,y2,r2;

	public Shape3(double x2, double y2, double r2) {
		super(x2, y2, r2);
		this.x2 = x2;
		this.y2 = y2;
		this.r2 = r2;
	}
	public void draw(Graphics2D g2){
    	g2.setColor(col);
    	g2.fill(new Rectangle2D.Double((int)(x2-1.5*r2), (int)(y2-1.5*r2), (int)(3*r2), (int)(3*r2)));
    	super.draw(g2);	    
	}
}
