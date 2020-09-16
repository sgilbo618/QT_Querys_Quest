# Query's Quest
![Game Home Screen](https://dl.dropboxusercontent.com/s/zopofphwmlurkrs/home_screen.png?dl=0 =450x500)<br>
Query's Quest is an adventure game based off of an early 90's computer game called Chip's Challenge. Chip's Challenge was one of the first video games I ever played, so it has a special place in my heart. It started as a simple console version, and now I have developed a GUI for it using Qt. It has been fun to add on new features as my skills have progressed.

The game is played on a 2D game board with several rooms containing different obstacles. Query must collect enough queries (?) in order to unlock the final gate. Along the way, Query may encounter locked doors, slippery ice, or deadly fire and water. Query may also find special boots to protect him from the elements, as well as keys to unlock doors. 

Eventually, I would like to add more levels, just like the game that inspired it. 

## Usage
![Full Game Board](https://dl.dropboxusercontent.com/s/kj2co98mdwinrzp/full_board.png?dl=0 =450x500)<br>
Use the arrow keys to navigate through the game board. 
Collect colored keys to unlock the corresponding doors.
Collect element boots for ability to traverse the corresponding elements.
Collect all the queries to unlock the final door.

## Game Modes
Upon clicking 'Play Game', the user is prompted to select a game mode - either easy or hard. Easy mode displays the entire game board as shown above, so it is easier to figure out an optimal route through the world. As seen below, hard mode separates the world into rooms and will only display the room Query is currently exploring.
![Hard Mode Board](https://dl.dropboxusercontent.com/s/diy5anc6cdnygmg/hard_mode.png?dl=0 =450x500)<br>

## Deployment
For now, to deploy and play this version of Queries Quest you have clone this repository and compile the game code on your own machine. I would recommend using Qt Creator for that part.

Alternatively, you can checkout the console version on [Repl.it](https://repl.it/@sgilbo/Querys-Quest).

Coming soon - I am working on building the Qt version for web assembly to get it hosted online. 

## Built With
C++, Qt

## Author
Samantha Guilbeault
