package prove02;

import java.awt.*;

public class Zombie extends Creature implements Movable, Aggressor {

    public Zombie() { _health = 100; }

    public void move() {
        _location.x++;
    }

    public void attack(Creature target) {

        if (target instanceof Plant) {
            return;
        }
        else {
            if (target != null)
                target.takeDamage(10);
        }
    }

    public Shape getShape() { return Shape.Square; }

    public Color getColor() { return new Color(0, 0, 135); }

    public Boolean isAlive() { return true; }
}
