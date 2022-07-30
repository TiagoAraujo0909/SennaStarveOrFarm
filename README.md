League of Legends is a MOBA and Senna is a a playable character in it.
When you play as her there's a chance "souls" drop from minions.
When you kill one (farm) the chance is lower compared to when an ally kills it for you (starve).

Should we farm? Or Should we starve?

Before I begin I just want to clarify a few things I'm aware of and/or want you to understand:
- This test doesn't include many variables such as poke souls, canon/siege minion gold and souls, runes, etc. It is supposed to be an oversimplified overview;
- I assume Senna manages to collect every soul dropped when in practice this would be very hard to happen;

To explain my math, here's how I calculated it:
I assume the average number of minions killed by a single team in a 20-minute ARAM game is 250 (I calculated it from my own games) and that Senna farms on average 44 minions per game, According to MurderBridge Senna Stats tab https://www.murderbridge.com/Champion/Senna.

First, I test how much gold and souls a 0 cs Senna gets. 
I roll a number between 0 and 100, 250 times, and for each, if the number is Lesser or Equal to 27 (28% chance a soul drops from minions Senna doesn't kill) the *soul count (souls)* increments, otherwise the *no soul count (nosoul)* increments.
At the end, the gold Senna gets is calculated by `gold = (souls*(nofarmgold+soulgold)) + (nosoul*nofarmgold);` and the soul count is the counter itself.

`nofarmgold` is the passive gold (6) you get when a minion dies in ARAM.
`soulgold` is the gold you get from collecting the soul (8).

&#x200B;

I then test the average Senna cs of 44.

I do a greedy approach to simplify, where firstly she farms the 44 minions, and then she "starves" for the remainder 206 minions. 

I roll a number between 0 and 100, 44 times, and for each, if the number is Lesser or Equal to 3 (\~2.7% chance a soul drops from minions Senna kills) the *soul count (souls)* increments, otherwise the *no soul count (nosoul)* increments.

The gold Senna gets from these 44 minions is calculated by `gold = (souls*(farmgold+soulgold)) + (nosoul*farmgold);` and the soul count is the counter itself.

\- `farmgold` is the average gold you get for killing a minion in ARAM. (17 for casters, 20 for melee = \~19 gold)

Then I do the same process as before (in the 0 cs section) for the remainder of 206 minions and add it to the previous result to find the final gold Senna gets for farming 44 minions out of 250. `gold += (souls*(nofarmgold+soulgold)) + (nosoul*nofarmgold);`

&#x200B;

Finally, I find the difference between gold and souls you get for starving or farming

I do these 2 steps for *n* amount of times to test it out, \[here's one of the possible results for 10 tests.\](https://cdn.discordapp.com/attachments/230381617972117504/940556340982599720/unknown.png)

\[And here's the results for a sample of 100 000 tests\](https://cdn.discordapp.com/attachments/230381617972117504/940557195936944128/unknown.png)

&#x200B;

We can see that you get on average 766 more gold if you farm and only lose out on 10 souls.

But is it worth it? This gold could go into your team, especially if you have a Veigar or a Nasus that rely on last hitting the minions to achieve their potential, far more than Senna.
