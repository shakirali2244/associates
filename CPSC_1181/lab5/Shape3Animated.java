

import java.awt.Graphics2D;

public class Shape3Animated extends Shape3{
	private double x3,y3,r3;
	// indicates a random direction (one of up, down, left, or right)
	private int direction;   
	private double velocity;
	
	public Shape3Animated(double x3, double y3, double r3) {
		super(x3,y3,r3);
		this.x3 = x3;
		this.y3 = y3;
		this.r3 = r3;	
		
	}
 
	//moves the x or y coordinates of the shape based 
	//on direction and velocity
	//decide about arguments
	public void move(int direction, double velocity){
		this.direction = direction;
		this.velocity = velocity;
		if (direction/90 == 0)
			this.x3+=velocity;
		else if (direction/90 == 1)
			this.y3+=velocity;
		else if (direction/90 == 2)
			this.x3-=velocity;
		else if (direction/90 == 3)
			this.y3-=velocity;
	}
	
	public void draw(Graphics2D g2){
    	super.draw(g2);
	}
	
}
