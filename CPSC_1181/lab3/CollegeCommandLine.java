import java.util.*;

public class CollegeCommandLine {
	
	 public static void main (String[] args)  {
		    Scanner myInput = new Scanner(System.in);    
			String command;
			College college = new College();
			 do {
				System.out.print(">");
			 	System.out.println("Enter a command :"); 
				command = myInput.nextLine();
				command.trim();
				
				if (command.equals("add")){
					String subCommand;
					
					Student student = new Student();
					System.out.println("Enter Student’s name: ");
					subCommand = myInput.nextLine();
					student.setName(subCommand);
					
					System.out.println("Enter Student’s address: ");
					
					subCommand = myInput.nextLine();
					List<String> addressList = Arrays.asList(subCommand.split(","));
					Address address = new Address();
					address.setNumber(Integer.parseInt(addressList.get(0)));
					address.setStreet(addressList.get(1));
					address.setCity(addressList.get(2));
					address.setProvince(addressList.get(3));
					address.setPostal(addressList.get(4));
					
					student.changeAddress(address);
					
					college.addStudent(student);
					System.out.println("SUCCESS, Student’s id is: " + student.getStudentID());
										
				}
				if (command.equals("find")){
					System.out.println("Enter the Student number to look up: "); 
					int id = myInput.nextInt();
					Student findStudent = college.findStudent(id);
					if (findStudent != null){
						System.out.println("Name: "+findStudent.getName());
						System.out.println("Student number: "+findStudent.getStudentID());
						System.out.println("Address: "+findStudent.getAddress().getNumber()+ ", " +findStudent.getAddress().getStreet()+ ", " +
								findStudent.getAddress().getCity()+ ", " +findStudent.getAddress().getProvince()+ ", " +
								findStudent.getAddress().getPostal());
						System.out.println("Quiz average: "+findStudent.getAverageQuizScore());
					}else{
						System.out.println("Cannot find student with that id");
					}
					
				}
				if (command.startsWith("addQuiz")){
					System.out.println("Enter the Student number: "); 
					int id = myInput.nextInt();
					Student findStudent = college.findStudent(id);
					if (findStudent != null){
						System.out.println("Enter the quiz score: "); 
						double quizScore= myInput.nextDouble();
						findStudent.addNewQuizScore(quizScore);
					}else{
						System.out.println("Cannot find student with that id");
					}
					
				}
				if (command.startsWith("findHighest")){
					Student higest = college.findHighest();
					if (higest != null){
						System.out.println("Student with highest marks ----");
						System.out.println("Name: "+higest.getName());
						System.out.println("Student number: "+higest.getStudentID());
						System.out.println("Address: "+higest.getAddress().getNumber()+ ", " +higest.getAddress().getStreet()+ ", " +
								higest.getAddress().getCity()+ ", " +higest.getAddress().getProvince()+ ", " +
								higest.getAddress().getPostal());
					}else{
						System.out.println("Cannot find student with highest marks");
					}
					
					
				}
				if (command.startsWith("delete")){
					System.out.println("Enter the Student number: "); 
					int id = myInput.nextInt();
					Student deleteStudent = college.findStudent(id);
					if (deleteStudent != null){
						System.out.println("Deleting student: ");
						System.out.println("Name: "+deleteStudent.getName());
						System.out.println("Student number: "+deleteStudent.getStudentID());
						System.out.println("Address: "+deleteStudent.getAddress().getNumber()+ ", " +deleteStudent.getAddress().getStreet()+ ", " +
								deleteStudent.getAddress().getCity()+ ", " +deleteStudent.getAddress().getProvince()+ ", " +
								deleteStudent.getAddress().getPostal());
						System.out.println("Please confirm with a \"yes\" :");
						String ans = myInput.nextLine();
						ans.trim().toLowerCase();
						if (ans.equals("yes")){
							college.deleteStudent(id);
							System.out.println("Student\""+deleteStudent.getName()+"\" deleted");
						}
					}else{
						System.out.println("Cannot find student with that id");
					}					
				}			
				
				
				}while (!command.equals("quit"));
		        
		  }	
}
