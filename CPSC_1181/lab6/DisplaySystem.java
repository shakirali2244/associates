package lab6;


import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JPanel;

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
    
    private JPanel canvas;
    private ArrayList<DrawableObject> drawableObjects = new ArrayList<DrawableObject>();
    private HashMap<Object, DrawableObject> drawableMap = new HashMap<Object, DrawableObject>();
    private ArrayList<Object> removeQueue = new ArrayList<Object>();
    private boolean running = false;
    private int width, height;    
    
    /**
     * Create a graphics window of a specific width and height
     * @param width
     * @param height 
     */
    public DisplaySystem(final int width, final int height) {
        this.width = width;
        this.height = height;
        canvas = new JPanel() {
            BufferedImage bm = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
            Graphics2D buffer = bm.createGraphics();
        	
            @Override
            public void paintComponent(Graphics g) {
            	buffer.clearRect(0, 0, width, height);
                synchronized(DisplaySystem.this) {                	
                    for (DrawableObject drawable: drawableObjects) {                                             
                        try {
                            Method m = drawable.m;
                            m.invoke(drawable.obj, buffer);
                        } catch (IllegalAccessException ex) {
                            ex.printStackTrace();
                        } catch (IllegalArgumentException ex) {
                            ex.printStackTrace();
                        } catch (InvocationTargetException ex) {
                            ex.printStackTrace();
                        }                        
                    }
                    g.drawImage(bm, 0, 0, width, height, null);                    
                }                
            }            
        };        
        canvas.setPreferredSize(new Dimension(width, height));
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.add(canvas);
        this.pack();
        this.setVisible(true);
    }
    
    public JPanel getCanvas() {
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
                DrawableObject drawable = new DrawableObject(obj, m);
                drawableObjects.add(drawable);
                drawableMap.put(obj, drawable); 
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
     * Remove an object from the displaySystem, so it won't render
     * @param obj the object to remove
     * @return true if the object is successfully removed
     */
    public boolean removeObject(Object obj) {
        if (drawableMap.containsKey(obj)) {            
            removeQueue.add(obj);
            return true;
        } else {
            return false;
        }
    }
    
    private void processRemoveQueue() {
        synchronized (this) {
            for (Object obj : removeQueue) {
                DrawableObject drawable = drawableMap.remove(obj);
                if (drawable != null) {
                    drawableObjects.remove(drawable);
                }        
            }
        }
    }
        
    
    public Collection getObjects() {
        return drawableMap.keySet();
    }
    
    public <T> Collection<T> getObjects(Class<T> clazz) {
        ArrayList<T> list = new ArrayList<T>();
        for (Object o : drawableMap.keySet()) {
            if (o.getClass() == clazz) {
                list.add((T)o);
            }
        }
        return list;
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
                        processRemoveQueue();
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
            canvas.repaint(100);
            processRemoveQueue();
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

    public int getHeight() {
        return height;
    }
    
    public int getWidth() {
        return width;
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
