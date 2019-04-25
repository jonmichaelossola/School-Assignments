package life;

import java.util.HashMap;
import java.util.Map;

public class Player {
    private String name;
    private int health;
    private int mana;
    private int gold;
    private Map<String, Integer> map;

    public Player(String name)
    {
        health = 50;
        mana = 100;
        gold = 2;
        this.name = name;

        map = new HashMap<String, Integer>();
    }

    public Player() {
        this.name = "Rachel";
        this.health = 25;
        this.mana = 50;
        this.gold = 1;

        map = new HashMap<String, Integer>();
    }

    public void display()
    {
        System.out.println("Name: " + name);
        System.out.println("Health: " + health);
        System.out.println("Mana: " + mana);
        System.out.println("Gold: " + gold);

        for (String name : map.keySet()){

            System.out.println(name);
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        this.health = health;
    }

    public int getMana() {
        return mana;
    }

    public void setMana(int mana) {
        this.mana = mana;
    }

    public int getGold() {
        return gold;
    }

    public void setGold(int gold) {
        this.gold = gold;
    }

//    Map(Map<String, Integer> map) {
//        this.map = map;
//    }


    public Map<String, Integer> getMap() {
        return map;
    }
}