import com.google.gson.Gson;
import twitter4j.*;
import twitter4j.conf.ConfigurationBuilder;

import java.util.Map;
import java.util.TreeMap;

/**
 * Created by lfalin on 1/14/17.
 */
public class TweetLoader {

    Twitter _twitter;

    public TweetLoader(){
        configureKeys();
    }

    private void configureKeys() {

        ConfigurationBuilder cb = new ConfigurationBuilder();

        // This continuous set of function calls all connected together is referred to
        // as "method chaining". It is a popular technique amongst web developers and has
        // gradually found its way into other languages.
        //
        // The way it works is that each setter returns a reference to the object.
        // For example, the code in the setDebugEnabled function might look like this:
        //
        //  ConfigurationBuilder setDebugEnabled(Boolean value) {
        //      this.debugEnabled = value;
        //
        //      // Returning "this" allows method chaining.
        //      return this;
        //  }
        //
        cb.setDebugEnabled(true)
                .setOAuthConsumerKey("PUT YOUR CONSUMER KEY HERE")
                .setOAuthConsumerSecret("PUT YOUR CONSUMER SECRET HERE")
                .setOAuthAccessToken("PUT YOUR ACCESS TOKEN HERE")
                .setOAuthAccessTokenSecret("PUT YOUR ACCESS TOKEN SECRET HERE")
                .setJSONStoreEnabled(true);

        TwitterFactory tf = new TwitterFactory(cb.build());
        _twitter = tf.getInstance();
    }

    public Map<String, BYUITweet> retrieveTweetsWithHashTag(String hashtag) {

        Map<String, BYUITweet> tweets = new TreeMap<>();

        Query query = new Query("#byui");
        QueryResult result;

        // Execute the search
        try {
            result = _twitter.search(query);
        } catch (TwitterException e) {
            e.printStackTrace();
            return null;
        }


        // Retrieve the raw JSON from each tweet, deserialize it into a BYUITweet object,
        // then store it in the map, using the user name as the key
        for (Status status : result.getTweets()) {
            String json = TwitterObjectFactory.getRawJSON(status);

            Gson gson = new Gson();
            BYUITweet bt = gson.fromJson(json, BYUITweet.class);

            tweets.put(bt.user.name, bt);

        }

        return tweets;

    }
}
