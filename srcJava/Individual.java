import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Individual extends JLabel {
	
	private static ImageIcon healthyIcon;
	private static ImageIcon superHealthyIcon;
	private static ImageIcon sickIcon;
	private static ImageIcon deadIcon;
	private static boolean imageLoaded = false;
	
	Pathogen pathogen;
	boolean immune;
	boolean alive;
	
	public Individual() {
		if(!imageLoaded) {
			try {
				healthyIcon = new ImageIcon(ImageIO.read(new File("src/resources/healthyIcon2.png")));
				superHealthyIcon = new ImageIcon(ImageIO.read(new File("src/resources/superHealthyIcon2.png")));
				sickIcon = new ImageIcon(ImageIO.read(new File("src/resources/sickIcon2.png")));
				deadIcon = new ImageIcon(ImageIO.read(new File("src/resources/deadIcon2.png")));
			} catch(IOException e) {
				System.out.println("exception while loading icons in Individual: " + e.toString());
			}
			imageLoaded = true;
		}
		
		pathogen = null;
		immune = false;
		this.alive = true;
		
		super.setIcon(healthyIcon);
	}


	public void nextDay() {
		if(this.isInfected()) {
			pathogen.nextDay();
		}
	}
	
	public void interactWith(Individual otherIndividual) {
		if(this.isAlive() && otherIndividual.isAlive() && this.isInfected()) {
			pathogen.attack(otherIndividual);
		}
	}
	
	public void infectWith(Pathogen pathogen) {
		if(pathogen.getHost() == this) {
			this.pathogen = pathogen;
			super.setIcon(sickIcon);
		}
	}
	
	public void recoverFrom(Pathogen p) {
		if(this.isInfectedWith(p)) {
			Pathogen.kill(pathogen);
			pathogen = null;
			immune = true;
			super.setIcon(superHealthyIcon);
		}
	}

	public void dieFrom(Pathogen p) {
		if(this.isInfectedWith(p)) {
			Pathogen.kill(pathogen);
			pathogen = null;
			immune = false;
			alive = false;
			super.setIcon(deadIcon);
		}
	}
	
	
	public boolean isAlive() {
		return this.alive;
	}
	public boolean isImune() {
		return immune;
	}
	public boolean isInfected() {
		if(pathogen == null) return false;
		else return true;
	}
	public boolean isInfectedWith(Pathogen p) {
		if(pathogen == p) return true;
		else return false;
	}
	
	
}
