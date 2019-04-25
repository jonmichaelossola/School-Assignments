import com.google.gson.annotations.SerializedName;

/**
 * Created by lfalin on 1/14/17.
 */
class User {
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getFollowers() {
        return followers;
    }

    public void setFollowers(int followers) {
        this.followers = followers;
    }

    String name;

    @SerializedName("followers_count")
    int followers;
}
