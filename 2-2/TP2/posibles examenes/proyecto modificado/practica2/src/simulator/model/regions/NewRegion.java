package simulator.model.regions;

import simulator.model.animals.Animal;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.Diet;

import java.util.List;

public class NewRegion extends Region {


    @Override
    public void update(double dt) {
    }

    @Override
    public double get_food(Animal a, double dt) {
        double food=0;
        if(a.get_diet()!= Diet.HERBIVORE) {
            List<AnimalInfo> _lista_carnivoros = filtraPorDieta(Diet.CARNIVORE);
            food = 60.0 * Math.exp(-Math.max(0, _lista_carnivoros.size() -5.0) * 2.0) * dt;
        }
        return food;
    }

    public String toString(){
        return "New region";
    }
}
