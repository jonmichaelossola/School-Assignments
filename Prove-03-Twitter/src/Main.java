import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import java.util.Map;

public class Main {

    public static void main(String[] args) {

        TweetLoader loader = new TweetLoader();
        Map<String, BYUITweet> tweets = loader.retrieveTweetsWithHashTag("#byui");

        // Print in order by name. Our keys are automatically sorted because the TweetLoader is
        // using a TreeMap.
        for(String name : tweets.keySet()) {
            BYUITweet theTweet = tweets.get(name);
            System.out.println(String.format("%s (%d followers): %s",
                    name, theTweet.getUser().getFollowers(), theTweet.getText()));
        }

        // Now, to sort the users by their follower counts, we first get the list of keys from the Map
        // and convert it to a List.
        List<String> sortedNames = new ArrayList<>(tweets.keySet());

        // This is a lambda function which sorts the keys by their follower counts.
        // The lambda function starts at the "(o1, o2) -> " part.
        Collections.sort(sortedNames, (o1, o2) -> Integer.compare(tweets.get(o2).getUser().getFollowers(),
                tweets.get(o1).getUser().getFollowers())
        );

        /*
            If you don't like the lambda function syntax, you can use a Comparator class
            to do the sorting. Note that if you use this code, IntelliJ will offer to convert it
            to a lambda function for you.
            Collections.sort(sortedNames, new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    return Integer.compare(tweets.get(o2).getUser().getFollowers(),
                                           tweets.get(o1).getUser().getFollowers());
                }
            });
         */

        // Print the tweets in order by follower count.
        for(String name : sortedNames) {
            BYUITweet theTweet = tweets.get(name);
            System.out.println(String.format("%s (%d followers): %s", name, theTweet.getUser().getFollowers(), theTweet.getText()));
        }

    }
}