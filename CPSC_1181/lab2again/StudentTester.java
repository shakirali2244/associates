public class StudentTester{
	
	/**
	 * test instance fields
	 */
	static void getsetTest(Student s){
		Address a = new Address();
		a.setProvince("BC");
		s.changeAddress(a);
		
		if (s.getAddress().getProvince().equals(a.getProvince())){
			System.out.println("getsetTest -- passed");
		}else{
			System.out.println("getsetTest -- failed");
		}
		s.setName("john");
		if (s.getName().equals("john")){
			System.out.println("getsetTest -- passed");
		}else{
			System.out.println("getsetTest -- failed");
		}		
	}
	
	/**
	 * tests the id generation logic
	 */
	static void testId(Student s){
		if (s.getStudentID() >= 10000000){
			//System.out.println(s.getStudentID());
			System.out.println("testId -- passed");
		}else{
			System.out.println("testId -- failed");
		}		
	}
	
	/**
	 * tests the averaging logic
	 */
	static void testAverage(Student s){
		s.addNewQuizScore(0);
		s.addNewQuizScore(10);
		if(s.getAverageQuizScore() == 5 ){
			System.out.println("testAverage -- passed");
		}else{
			System.out.println("testAverage -- failed");
		}
	}
	
	public static void main(String[] args){
		//initialize our student object
		Student s = new Student();
		getsetTest(s);
		testId(s);	
		testAverage(s);
	}
}