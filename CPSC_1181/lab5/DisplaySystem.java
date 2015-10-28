

import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import javax.swing.JFrame;

/**
 * A Swing based simple OO graphics and animation system
 * 
 * The goal is to create something extremely simple to use,
 * and introduce users to the java.awt.Graphics2D class
 * 
 * <pre>
 * Example usage:
 *  
 *  // Create a GameFrame window with size 800 x 600 pixels
 *  DisplaySystem displaySystem = new displaySystem(800,600);
 * 
 *  // Add an object to display
 *  displaySystem.addObject(new SomeObject());
 * </pre>
 * 
 * SomeObject can be any object, the only requirement is that
 * it contains a method named draw(Graphics2D graphics).  
 * 
 * This draw method will be called automatically by GameFrame,
 * and the object can draw whatever it needs to the current graphics 
 * window.
 * 
 * @see DisplaySystem#addObject addObject 
 * @author jmadar
 */
public class DisplaySystem extends JFrame {
    
    private Canvas canvas;
    private ArrayList<DrawableObject> drawableObjects = new ArrayList<DrawableObject>();
    private boolean running = false;
        
    /**
     * Create a graphics window of a specific width and height
     * @param width
     * @param height 
     */
    public DisplaySystem(int width, int height) {
        canvas = new Canvas() {
            @Override
            public void paint(Graphics g) {
                synchronized(DisplaySystem.this) {
                    for (DrawableObject drawable: drawableObjects) {                                             
                        try {
                            Method m = drawable.m;
                            m.invoke(drawable.obj, canvas.getGraphics());
                        } catch (IllegalAccessException ex) {
                            ex.printStackTrace();
                        } catch (IllegalArgumentException ex) {
                            ex.printStackTrace();
                        } catch (InvocationTargetException ex) {
                            ex.printStackTrace();
                        }                        
                    }
                }
            }            
        };        
        canvas.setPreferredSize(new Dimension(width, height));
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.add(canvas);
        this.pack();
        this.setVisible(true);
    }
    
    public Canvas getCanvas() {
        return canvas;
    }
    
    /**
     * Add an object to the game canvas.  The object must have
     * a draw(Graphics2D graphics) method.
     * 
     * During runtime, the GameFrame's graphics object will be passed
     * to the draw method, so the objects can draw freely to the graphics
     * windows
     * 
     * @param obj the object to add to the display
     */
    public void addObject(Object obj) throws DisplaySystemException {        
        synchronized(this) {
            try {
                Method m = obj.getClass().getMethod("draw", Graphics2D.class);
                drawableObjects.add(new DrawableObject(obj, m));
                refresh(0);
            } catch (NoSuchMethodException ex) {
                throw new DisplaySystemException("Object must have a draw method", ex);
            } catch (SecurityException ex) {
                throw new DisplaySystemException("draw method must be public", ex);
            } catch (IllegalArgumentException ex) {
                throw new DisplaySystemException("draw method must have a Graphics2D parameter", ex);
            }
        }
    }
    
    /**
     * Starts the drawing loop -- each object's draw method will be called
     * at around 60 times per second.  This can be used for animation.
     */
    public void start() {
        running = true;
        // calls repaint on the canvas
        Thread t = new Thread() {

            @Override
            public void run() {
                try {
                    while (running) {
                        canvas.repaint();
                        // Approx 60 times per second
                        sleep(16);
                    }
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }
            
        };
        t.start();
    }
    
    public void refresh() {
        refresh(16);
    }
    
    public void refresh(int delay) {
        try {
            canvas.repaint();
            Thread.sleep(delay);
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }
    }
    
    /**
     * Pause the loop
     */
    public void pause() {
        running = false;
    }
    
    public boolean isRunning() {
        return running;
    }

    /** 
     * A class to group together the method and the target object
     */
    private class DrawableObject {
        public Object obj;
        public Method m;
        
        public DrawableObject(Object obj, Method m) {
            this.obj = obj;
            this.m = m;
        }
    }
    
    /**
     *
     * @author jmadar
     */
    public static class DisplaySystemException extends RuntimeException {

        public DisplaySystemException(String message, Throwable e) {
            super(message, e);
        }
    }
        
}
