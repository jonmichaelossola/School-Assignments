package life;

import com.google.gson.Gson;

import java.io.*;

public class Game {
    private Player player;
    private String save;

    public Game(Player player) {
        this.player = player;
    }

    public Game() {
        player = null;
        save = null;
    }

    public void saveGame()
    {
        Gson gson = new Gson();
        save = gson.toJson(player);

        try {
            String filename = "saved";
            BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
            writer.write(save);

            writer.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static Game loadGame(String filename)
    {
        Player play = new Player();

        try {
            BufferedReader br = new BufferedReader(new FileReader(filename));

            String st = "";
            String saved = "";

            while ((st = br.readLine()) != null)
                saved += st;

            Gson gson = new Gson();
            play = gson.fromJson(saved, Player.class);
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        Game game = new Game(play);

        return game;
    }

    public Player getPlayer() {
        return player;
    }

    public void setPlayer(Player player) {
        this.player = player;
    }

    public String getSave() {
        return save;
    }

    public void setSave(String save) {
        this.save = save;
    }
}
