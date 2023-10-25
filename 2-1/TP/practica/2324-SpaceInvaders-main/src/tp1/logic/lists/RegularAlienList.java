package tp1.logic.lists;

import tp1.logic.Position;
import tp1.logic.gameobjects.RegularAlien;
import tp1.logic.gameobjects.UCMLaser;

/**
 * Container of regular aliens, implemented as an array with a counter
 * It is in charge of forwarding petitions from the game to each regular alien
 * 
 */
public class RegularAlienList {

	private RegularAlien[] objects;
	private int num;
	
	//TODO fill your code
	public RegularAlienList(int num) {
		this.num = num;
		objects = new RegularAlien[num];
	}

	public int getNum(){
		return num;
	}

	public void initializeAlienList(int row){
		for(int i=0;i<getNum();i++){
			objects[i]= new RegularAlien(i, row);
		}
	}

	// @returns si un alien del array esta en posicion -> true
	// @else -> false
	public boolean anAlienInPosition(Position pos){
		int i= 0;

		while(i<num && !objects[i].isInPosition(pos))
			i++;


		return i==num;
	}


}
