import java.util.Random;
import java.util.ArrayList;

public class Student{
	
	private int id;
	private String name;
	private Address address;
	private double averageScore;
	private int ID_START = 10000000; 
	ArrayList<Double> scores = new ArrayList<Double>();
	
	/**
	 * Constructor sets id for any instance
	 */
	public Student(){
		setId();
	}
	
	/**
	 * id generator for any Student class object
	 */
	private void setId(){
		Random rand = new Random();
		this.id = rand.nextInt( ID_START + 20000000 ) + ID_START;
	}
	
	/**
	 * return name of the Student
	 */
	public String getName(){
		return name;
	}
	
	/**
	 * return id of the Student
	 */
	public int getStudentID(){
		return id;
	}
	
	/**
	 * return Address of the student
	 */
	public Address getAddress(){
		return address;		
	}
	
	/**
	 * returns the average of the Student's quizes
	 */
	public double getAverageQuizScore(){
		double total = 0;
		for (Double score : scores){
			total+=score;
		}
		this.averageScore = total/scores.size();
		return averageScore;
	}
	
	/**
	 * sets the Name of the Student
	 */
	public void setName(String name){
		this.name = name;
	}
	
	/**
	 * updates the address of the student
	 */
	public void changeAddress(Address address){
		this.address = address;
	}
	
	/**
	 * adds new score to the student profile
	 */
	void addNewQuizScore(double quizScore){
		scores.add(quizScore);
	}
	
}