import java.io.IOException;
public class Intro{
	public static void main(String args[]){
		String name = "Shakir";
		String background = "JAX-RS and android development";
		String reason = "Get Associates Degree";

		System.out.println();

		System.out.println(name);
		
		try{
			int result = System.in.read();
			int result2 = System.in.read(); //to consume new line from enter
		}catch (IOException e) {
			System.out.println(e);
		}

		System.out.println(background);

		try{
			int result = System.in.read();
			int result2 = System.in.read(); //to consume new line from enter
		}catch (IOException e) {
			System.out.println(e);
		}

			
		System.out.println(reason);

		try{
			int result = System.in.read();
			int result2 = System.in.read(); //to consume new line from enter
		}catch (IOException e) {
			System.out.println(e);
		}
	}
}

			//one more method to consume new line
			/*while(result == 10){
				int result2 = System.in.read();
				if (result2 == 13) break;
				System.out.println("result  2:"+result2);
			}*/

