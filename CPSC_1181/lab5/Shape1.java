



import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

public class Shape1 {
	private double x, y, r;
	protected Color col;
	
	public Shape1(){};
	
	public Shape1(double x, double y,double r){
		this.x = x;
		this.y = y;
		this.r = r;
		this.col = new Color((int) (Math.random()*255), 
				(int) (Math.random()*255), 
				(int) (Math.random()*255));
	}
     	 
	public void draw(Graphics2D g2){
	  	g2.setColor(col);
	  	g2.fill(new Ellipse2D.Double(x-2*r, y-r,
	            4*r,
	            2*r));	  	
	}  	 
 }