package tp1.logic.gameobjects;
import tp1.logic.*;
import tp1.view.Messages;

public class UCMShip{
	private Position pos;
	private int vida=3;
	private Game game;
	public UCMShip(Game game, Position position){
		this.game=game;
		this.pos = position;
	}

	public String getSymbol(){
		String symbol=Messages.UCMSHIP_SYMBOL;
		if(vida<0){
			symbol="#──#";
		}
		return symbol;
	}

	public boolean estaEnPos(Position position){
		return this.pos.equals(position); 
	}
	
	public void mueve(Move movimiento) {
		
		//nueva variable para mover
		Position posicionActualizada = new Position(pos);
		
		//actualizar
		posicionActualizada.actualiza(movimiento);

		//si no esta fuera del mapa
		if(posicionActualizada.esPosicionValida()) {
			//copiar al original
			pos=posicionActualizada;
		} else {
			System.out.println(Messages.INVALID_POSITION);
		}
		
	}

	public boolean recibeAtaque(DestroyerAlien alien){
		if(alien.bombaEnPos(this.pos)){
			vida--;
		}
		return alien.bombaEnPos(this.pos);
	}
	
	public UCMLaser creaLaser(){
		Position copia = new Position(pos);
		return new UCMLaser(copia);
	}
}