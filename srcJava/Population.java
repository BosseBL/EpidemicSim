import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;

import javax.swing.JPanel;
import javax.swing.JScrollPane;


public class Population extends JPanel {

	Individual[][] individuals;
	
	public Population(int n) {
		super();
		super.setLayout(new GridLayout(n,n));
		
		
		individuals = new Individual[n][n];
		for(int i = 0 ; i < individuals.length ; i++ ) {
			for(int j = 0 ; j < individuals[i].length ; j++) {
				individuals[i][j] = new Individual();
				super.add(individuals[i][j], i*j + j);
			}
		}
		super.setVisible(true);
			
	}
	
	protected void nextDay() {
		updateIndividuals();
	}
	
	private void updateIndividuals() {
		
		for(int i = 0 ; i < individuals.length ; i++ ) {
			for(int j = 0 ; j < individuals[i].length ; j++) {
				individuals[i][j].nextDay();
			}
		}
		
		for(int i = 0 ; i < individuals.length ; i++ ) {
			for(int j = 0 ; j < individuals[i].length ; j++) {
				if(!individuals[i][j].isAlive()) continue;
				
				if(i > 0 && j > 0) individuals[i][j].interactWith(individuals[i-1][j-1]);
				if(j > 0) individuals[i][j].interactWith(individuals[i][j-1]);
				if(i < individuals.length - 1 && j > 0) individuals[i][j].interactWith(individuals[i+1][j-1]);
				if(i < individuals.length - 1) individuals[i][j].interactWith(individuals[i+1][j]);
				if(i < individuals.length - 1 && j < individuals.length - 1) individuals[i][j].interactWith(individuals[i+1][j+1]);
				if(j < individuals.length - 1) individuals[i][j].interactWith(individuals[i][j+1]);
				if(i > 0 && j < individuals.length - 1) individuals[i][j].interactWith(individuals[i-1][j+1]);
				if(i > 0) individuals[i][j].interactWith(individuals[i-1][j]);
			}
		}
		
	}
	
	
	
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		
	}




}
