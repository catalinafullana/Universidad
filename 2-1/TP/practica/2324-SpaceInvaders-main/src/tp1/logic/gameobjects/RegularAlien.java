package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.Game;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

/**
 * 
 * Class representing a regular alien
 *
 *
 */
public class RegularAlien {

	//TODO fill your code
	private int cyclesToMove;
	private int speed;
	private Move dir;
	private AlienManager alienManager;
	
	private Position pos;
	
	
	//TODO fill your code
	public RegularAlien(int x, int y) {
		//alienManager = new AlienManager();
		this.pos = new Position(x,y);
		this.dir = Move.LEFT;
		//
	}
	/**
	 *  Implements the automatic movement of the regular alien	
	 */
	public void automaticMove() {
		if(isInBorder()) {
			if(dir==Move.LEFT) {
				dir= Move.RIGHT;
			}
			else if (dir==Move.RIGHT){
				dir= Move.LEFT;
			}
		}
		performMovement(dir);
	}

	private void descent() {
		//TODO fill your code

	}

	private void performMovement(Move dir) {
		pos.actualiza(dir);

	}

	private boolean isInBorder() {
		//TODO fill your code
		//return pos.getCol()==Game.DIM_X || pos.getCol()==0;
		return false;
	}

	public boolean receiveAttack(UCMLaser laser) {
		//TODO fill your code

		return false;
	}
	public boolean isInPosition(Position position){
		return position.equals(pos);
	}

	public String getSymbol(){
		return Messages.REGULAR_ALIEN_SYMBOL;
	}
}