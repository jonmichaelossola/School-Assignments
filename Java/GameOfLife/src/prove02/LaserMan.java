package prove02;

import java.awt.*;
import java.util.Random;

public class LaserMan extends Creature implements Aggressor, Movable {

    private Random rand;

    public LaserMan() {
        _health = 10000;
        rand = new Random();
    }

    public void move() {

        int direction = (rand.nextInt(4));

        if (direction == 0)
            _location.y++;
        else if (direction == 1)
            _location.x++;
        else if (direction == 2)
            _location.x--;
        else
            _location.y--;
    }

    public void attack(Creature target) {

        if (target != null) {
            target.takeDamage(10000);
        }
    }

    public Boolean isAlive() { return true; }
    public Color getColor() { return new Color(250, 0, 0); }
    public Shape getShape() { return Shape.Circle; }
}
