import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JLabel;

import java.awt.GridLayout;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class Bmi {
	
	
	/*
	* takes weight and height and returns BMI from the inputs
	*/ 
	static double computeBMI(double weight, double height){
		System.out.println("weight : "+ weight);
		System.out.println("height : "+ height);
		double bmi = (weight*703)/(height*height);
		System.out.println("bmi: "+bmi);
		return (Math.round(bmi*10.0))/10.0;
	}
	/*
	 * gives category of a person's health based on BMI input
	 */
	static String getCategory(double bmi){
		if (bmi < 18.5) return "UNDERWEIGHT";
		else if( 18.5 <= bmi && bmi < 25 ) return "HEALTHY WEIGHT";
		else if( 25 <= bmi && bmi < 30 ) return "OVERWEIGHT";
		else return "OBESE";
	}
	
	/**
	 * converts feet'inches to inches
	 */
	static double getHeight(String input){
		double height = 0.0;
        try{
        	height = Double.parseDouble(input);
        }catch(Exception e){
        	String[] parsed = input.split("'");
        	height = (Double.parseDouble(parsed[0])*12) 
        			+(Double.parseDouble(parsed[1])); 
        }
        return height;
	}
	

	public static void main(String[] args){
		//input form
        String inputs = JOptionPane.showInputDialog("<html>Enter your weight in pounds<br> "
        											+ "followed by a comma <br>"
        											+ "followed by your height in inches");
        List<String> items = Arrays.asList(inputs.split("\\s*,\\s*"));
        
        //if input does not match height,weitht then return invalid input
        if( items.size()!= 2 ) {
        	JOptionPane.showMessageDialog(null, "<html>INVALID INPUTS!! ");
        	return;
        }
        double weight = 0.0;
        
        
        //if input is of type <emptystring>,height
        try{
        	weight = Double.parseDouble(items.get(0));
        }catch(Exception e){
        	JOptionPane.showMessageDialog(null, "<html>INVALID WEIGHT!! ");
        	return;
        }
        
        //parse height
        double height = getHeight(items.get(1));
        
        //check if not zero or less than zero
        if (weight > 0 && height > 0){
        	double bmi = computeBMI(weight,height);
            System.out.println(weight+ " , " + height);
            Object[] options = { "OK" };
    		JOptionPane.showMessageDialog(null, "<html>With a weight of " +  weight + " lbs and height of " 
    											+ height + " inches <br> your BMI is " 
    											+  bmi + " which categorizes you as " + getCategory((weight*703)/(height*height))); 
        }else{
        	JOptionPane.showMessageDialog(null, "<html>INVALID INPUTS!! ");
        }
        
	}
	
	
}