import java.util.ArrayList;
public class College {
	
	private ArrayList<Student> students = new ArrayList<Student>();
	
	/**
	 * Empty constructor
	 */
	public College(){
		
	}
	
	/**
	 * add student to college
	 * @param student
	 * @return success or failure
	 */
	public boolean addStudent(Student student){
		if (student != null)
			return students.add(student);
		else
			return false;
	}
	
	/**
	 * find student in college based on provided id
	 * @param id
	 * @return
	 */
	public Student findStudent(int id){		
		for (Student currentStudent : students){
			if (currentStudent.getStudentID() == id)
				return currentStudent;
			}
		return null;
	}
	
	/**
	 * adds quiz score to student with that id
	 * @param id
	 * @param quizScore
	 * @return
	 */
	public boolean addQuizScore(int id,double quizScore){
		Student student = findStudent(id);
		if (student == null)
			return false;
		student.addNewQuizScore(quizScore);
		return true;		
	}
	
	/**
	 * finds highest average of quizscore of the college and find ref of the student in collge
	 * @return reference of student in the arraylist
	 */
	public Student findHighest(){
		double score = 0;
		int student = 0;
		Student studentret = null;
		for (int i=0; i<students.size(); i++){
			Student currentStudent = students.get(i);
			if (currentStudent.getAverageQuizScore() > score){
				score = currentStudent.getAverageQuizScore();
				student = i;
			}
		}
		if (students.size() != 0){
			studentret = students.get(student);
		}	
		
		return studentret;
	}
	
	/**
	 * deletes student from college based on the id provided
	 * @param id
	 * @return
	 */
	public boolean deleteStudent(int id){
		for (Student currentStudent : students){
			if (currentStudent.getStudentID() == id){
				return true;
			}
		}
		return false;
	}
	
}
