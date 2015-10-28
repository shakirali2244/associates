

import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

public class Shape2 extends Shape1{
	private double x1,y1,r1;
	
	public Shape2(double x1, double y1, double r1) {
		super(x1,y1,r1);
		this.x1 = x1;
		this.y1 = y1;
		this.r1 = r1;
	}

	public void draw(Graphics2D g){
    	// create and draw a vertical ellipse and then ask super class to draw the horizontal one.
		g.setColor(col);
	  	g.fill(new Ellipse2D.Double(x1-r1, y1-2*r1,
	            2*r1,
	            4*r1));
		super.draw(g);	  	
	}
}
