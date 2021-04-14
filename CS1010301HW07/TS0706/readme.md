# Subject: Shisensho
## Description:
Shisensho(四川省) is a classic tile-matching game. The objective of the game is to match all the pairs and clear the board.

Rules:
Player choose a pair of identical tiles to connect, and the connection path must not exceed two turns. If the requirements are met, two tiles will be eliminated. The player’s task is to eliminate all the tiles on the board. The game is over if future moves are not possible and tiles are left on the board, or the player successfully removes all the tiles.
Some legal patterns of connection path are shown as follow:
![](https://i.imgur.com/cupNQAf.png)
To simplify the game, we start the game with a 6*6 board and only have 9 different symbols 
(represented by characters :‘1’, ‘2’, ‘3’, … , ‘9’).

Your quest is to determine whether the given pair is legal according to the rules shown above. 
If it is legal, eliminate the pair and print out “pair matched”.
If it is not legal, do nothing and print out “bad pair”.

The status of the board (the remaining tiles) should always be updated when you receive a legal pair, 
which means the same input might have different results over time.


## Input:
[Beginning]
Given 6*6 characters to set all the initial symbol on the board.
[Loop]
Given a pair of coordinates on the board, represented by 4 integers (pos1.x  pos1.y  pos2.x  pos2.y).


## Output:
The result message of each given pair. (“bad pair”or“pair matched”)

| Sample Input	 | Sample Output |
| -------- | -------- |
|9 2 4 8 9 7<br>6 9 1 7 1 5<br>5 3 3 7 2 2<br>3 4 7 1 9 5<br>4 6 8 8 2 6<br>6 5 1 4 3 8<br>2 1 3 3<br>3 1 3 2<br>2 1 3 3<br>5 1 5 3<br>1 1 4 3<br>0 1 5 4<br>3 0 3 4|bad pair<br>pair matched<br>pair matched<br>pair matched<br>pair matched<br>bad pair<br>pair matched|


- [ ]  Eazy,Only basic programming syntax and structure are required.
- [x]  Medium,Multiple programming grammars and structures are required.
- [ ] Hard,Need to use multiple program structures or complex data types.
