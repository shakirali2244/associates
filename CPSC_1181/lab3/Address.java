public class Address {
	
	private int number;
	private String street;
	private String city;
	private String province;
	private String postal;
	
	/**
	 * Empty constructor
	 */
	public Address(){}
	
	/**
	 * return Street number
	 */
	public int getNumber(){
		return number;
	}
	
	/**
	 * return Street name
	 */
	public String getStreet(){
		return street;
	}
	
	/**
	 * return City name
	 */
	public String getCity(){
		return city;
	}
	
	/**
	 * return Province
	 */
	public String getProvince(){
		return province;
	}
	
	/**
	 * return postal code
	 */
	public String getPostal(){
		return postal;
	}
	
	/**
	 * add Street number
	 */
	public void setNumber(int number){
		this.number = number;
	}
	
	/**
	 * add Street name
	 */
	public void setStreet(String street){
		this.street = street;
	}
	
	/**
	 * add City name
	 */
	public void setCity(String city){
		this.city = city;
	}
	
	/**
	 * add province
	 */
	public void setProvince(String province){
		this.province = province;
	}
	
	/**
	 * add postal code
	 */
	public void setPostal(String postal){
		this.postal = postal;
	}


}