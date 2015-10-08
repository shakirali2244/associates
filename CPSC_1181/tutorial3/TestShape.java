package tutorial3;

import java.awt.Graphics2D;
import java.awt.image.BufferedImage;

public class TestShape {
	
	public TestShape(){
		BufferedImage image = new BufferedImage(800, 600, BufferedImage.TYPE_INT_RGB);
		Graphics2D graphics2D = image.createGraphics();
		draw(graphics2D);
	}
	public void draw(Graphics2D graphics){
		System.out.println("DRAWING");
		graphics.drawString("hello World", 800, 600);
	}
}
