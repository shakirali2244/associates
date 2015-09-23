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
		return Math.round((weight*703*10)/(height*height))*(1/10.0);
	}
	
	static String getCategory(double bmi){
		if (bmi < 18.5) return "UNDERWEIGHT";
		else if( 18.5 <= bmi && bmi < 25 ) return "HEALTHY WEIGHT";
		else if( 25 <= bmi && bmi < 30 ) return "OVERWEIGHT";
		else return "OBESE";
	}

	

	public static void main(String[] args){


        String inputs = JOptionPane.showInputDialog("<html>Enter your weight in pounds<br> "
        											+ "followed by a comma <br>"
        											+ "followed by your height in inches");
        List<String> items = Arrays.asList(inputs.split("\\s*,\\s*"));
        
        double weight = Double.parseDouble(items.get(0));
        double height = Double.parseDouble(items.get(1));
        double bmi = computeBMI(weight,height);
        
        System.out.println(weight+ " , " + height);
        Object[] options = { "OK" };
		JOptionPane.showMessageDialog(null, "<html>With a weight of " +  (int) weight + " lbs and height of " 
											+ (int) height + " inches <br> your BMI is " 
											+  bmi + " which categorizes you as " + getCategory(bmi)); 

	}
	
	
}