package life;

import com.google.gson.Gson;

public class Main {

    public static void main(String[] args) {
        Gson g = new Gson();

        Player player = new Player("Taylor");

        player.getMap().put("Basketball", 15);
        player.getMap().put("Sword", 50);
        player.getMap().put("lance", 60);
        player.getMap().put("infinityStone", 2000);

        Game game = new Game(player);
        game.saveGame();

        game.getPlayer().display();

        Game awesome = game.loadGame("saved");

        awesome.getPlayer().display();
    }
}
