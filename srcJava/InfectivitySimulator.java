import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JScrollPane;


public class InfectivitySimulator extends JFrame{

	Population population;
	
	public InfectivitySimulator() {
		super("Infectivity simulator");
		super.setDefaultLookAndFeelDecorated(true);
		super.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		super.setResizable(false);
		population = new Population(10);		
		JScrollPane populationContainer = new JScrollPane(population);
		super.add(populationContainer);
		super.pack();
		super.setVisible(true);
	}
	
	public static void main(String[] args) {
		InfectivitySimulator sim = new InfectivitySimulator();
		String input = "";
		Scanner s = new Scanner(System.in);
		while(input.compareTo("quit") != 0) {
			input = s.nextLine();
		}
		System.exit(ABORT);
	}

}
