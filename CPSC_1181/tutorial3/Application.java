package tutorial3;
/**
 * The application skeleton.  This is the controller
 * to manage DisplaySystem and all the objects that
 * it displays.
 * 
 * @author jmadar
 */
public class Application {
    
    /** Application manages one displaySystem */
    private DisplaySystem displaySystem;
    
    
    public Application() {
        // The DisplaySystem constructor requires a resolution
        displaySystem = new DisplaySystem(800, 600);
    }
    
    public void start() {        
        // We do our drawing here
        displaySystem.addObject(new TestShape());
    }
    
    /**
     * Main entry point, simply start the application
     */
    public static void main(String[] args) {
        Application app = new Application();
        app.start();
    }
    
}
