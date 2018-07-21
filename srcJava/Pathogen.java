import java.util.ArrayList;
import java.util.Random;


public class Pathogen {
	
	private static float contagionProbability;
	private static float deceaseProbability;
	private static int minDaysInfecting;
	private static int maxDaysInfecting;
	private static boolean attributesSet = false;
	private static int pathogenCounter = 0;
	private static Random randomGenerator = new Random(System.currentTimeMillis());
	
	public static void setAttributes(float conProb, float decProb, float recProb, int minDays, int maxDays) {
		contagionProbability = conProb; deceaseProbability = decProb; minDaysInfecting = minDays; maxDaysInfecting = maxDays;
		attributesSet = true;
	}
	
	int daysInfectingHost;
	Individual host;
	boolean alive;
	
	public Pathogen makeNewPathogen(Individual host) {
		if(attributesSet) {
			return new Pathogen(host);
		}
		else return null;
	}
	
	private Pathogen(Individual host) {
			daysInfectingHost = Math.round(randomGenerator.nextFloat()*(maxDaysInfecting - minDaysInfecting) + minDaysInfecting);
			this.host = host;
			pathogenCounter++;
	}
	
	public void attack(Individual newHost) {
		if(this.isAlive() && !(newHost.isImune() || newHost.isInfected()) && randomGenerator.nextFloat() <= contagionProbability) {
			Pathogen newPathogen = new Pathogen(newHost);
			newHost.infectWith(newPathogen);
		}
	}
	
	public void nextDay() {
		if(this.isAlive()) {
			daysInfectingHost--;
			if(daysInfectingHost <= 0) {
				host.recoverFrom(this);
			}
			else if(randomGenerator.nextFloat() <= deceaseProbability) {
				host.dieFrom(this);
			}
			else return;
		}
	}

	public Individual getHost() {
		return host;
	}
	
	public boolean isAlive() {
		return alive;
	}

	
	public static void kill(Pathogen pathogen) {
		pathogenCounter--;
		pathogen.host = null;
		pathogen.alive = false;
		pathogen.daysInfectingHost = 0;
	}
	
}
