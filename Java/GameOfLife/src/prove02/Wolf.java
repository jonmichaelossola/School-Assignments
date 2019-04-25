package prove02;

import java.awt.*;
import java.util.Random;
import java.util.ArrayList;
import java.util.List;

public class Wolf extends Creature implements Movable, Aware, Aggressor, Spawner {

    private Point preferredDirection;
    private int direction;
    private Random _rand;
    private int originalDirection;

    public Wolf() {
        _rand = new Random();
        preferredDirection = new Point();
        _health = 100;
        direction = _rand.nextInt(4);
        originalDirection = direction;
        preferredDirection.setLocation(_rand.nextInt(50), _rand.nextInt(50));
    }

    public void attack(Creature target) {

        if (target instanceof Zombie || target instanceof Plant) {
            return;
        }
        else {
            if (target != null)
                target.takeDamage(5);
        }
    }

    public void senseNeighbors(Creature above, Creature below, Creature left, Creature right) {

        // add all elements to a list
        List<Creature> myList = new ArrayList<Creature>();
        myList.add(above);
        myList.add(right);
        myList.add(below);
        myList.add(left);

        int count = 0;
        for (int j = direction; count < 4; count++, j++) {
            if (j == 4)
                j = 0;
            // if it's an instance of an animal, set it to the new preferredDirection
            if (myList.get(j) != null && myList.get(j) instanceof Animal) {
                preferredDirection = myList.get(j).getLocation();
                return;
            }
        }

        // if there are no animals around, just keep going right
        if (direction == 0)
            preferredDirection.setLocation(getLocation().getX(), getLocation().getY()+1);
        else if (direction == 1)
            preferredDirection.setLocation(getLocation().getX()+1, getLocation().getY());
        else if (direction == 2)
            preferredDirection.setLocation(getLocation().getX(), getLocation().getY()-1);
        else if (direction == 3)
            preferredDirection.setLocation(getLocation().getX()-1, getLocation().getY());

        boolean different = false;
    }

    public void move() {

        if (_location.getX() == preferredDirection.getX()-1)
            direction = 1;
        else if (_location.getX() == preferredDirection.getX()+1)
            direction = 3;
        else if (_location.getY() == preferredDirection.getY()+1)
            direction = 2;
        else
            direction = 0;

        _location.setLocation(preferredDirection.getX(), preferredDirection.getY());
    }

    public Creature spawnNewCreature() {

        Wolf wolf = new Wolf();
        Point locationChild = new Point();
        locationChild.setLocation(_location.getX()-1, _location.getY());
        wolf.setLocation(locationChild);
        return wolf;
    }

    public Shape getShape() { return Shape.Square; }

    public Color getColor() { return new Color(94, 100, 96); }

    public Boolean isAlive() { return _health > 0; }

}
