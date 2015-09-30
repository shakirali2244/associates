public class AddressTester {
	
	/**
	 * test instance fields
	 */
	static void getsetTest(Address a){
		a.setNumber(100);
		if(a.getNumber() == 100){
			System.out.println("getsetTest -- passed");
		}else{
			System.out.println("getsetTest -- failed");
		}
		a.setStreet("Howe");
		if(a.getStreet().equals("Howe")){
			System.out.println("getsetTest -- passed");
		}else{
			System.out.println("getsetTest -- failed");
		}
		a.setProvince("BC");
		if(a.getProvince().equals("BC")){
			System.out.println("getsetTest -- passed");
		}else{
			System.out.println("getsetTest -- failed");
		}
		a.setPostal("V3B3B5");
		if(a.getPostal().equals("V3B3B5")){
			System.out.println("getsetTest -- passed");
		}else{
			System.out.println("getsetTest -- failed");
		}
	}
	
	public static void main(String[] args){
		Address a = new Address();
		getsetTest(a);
	}

}
