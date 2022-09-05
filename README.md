video of the game - https://youtu.be/RueEIrjSXPI

<h1>Head Soccer</h1>
//----------------------------------------------------------------------------
2. Creator:
Amit Ein-Dor   ID 208625681
//----------------------------------------------------------------------------
3. General ideas and goals of the project:
A game which every player need to select his character and play against the other player.
the player who scored most goals wins the game.

the problem is making the game movement smooth and real life feeling, 
 adding many options for the player, challenging fun and friendly gameplay,
using the methods learned in class.
//----------------------------------------------------------------------------
4. Files:
all files with no description holds the ctrs and methods from headers
-CMakeLists.txt - Cmake file to all src files.
Classes:
-main -main c++
-Controller - the operative class
-Object - any kind of objects printed on the screen inherit from this basic object class.
-Board - read from the file and convert the data to an array of objects, then holds and manage the objects
-Textures\sounds_E - singelton, holds all the textures\sounds needed for the game
-Resources - cut the animations from the spritesheet
-Animation\AnimationData - change the texture according to the animation
-CollisionHandling - In charge of controlling the collision between objects
-Collision.cpp - external library - make the collision perfectly on pixel


*objects:
-MovingObject - a class that inherit from it is an object that can move 
	: all kinds of players, ball
-StaticObject - a class that inherit from it is an object that can't move
	: foot, yeti, goal

//----------------------------------------------------------------------------
5. Data structures :
-Board make a vector of Objects and print it each round.
-CollisionHandling have a map of two object, which is every pair and their unique 
	collision function.
-every moving object has an animation structure.
-sound\Texture singelton holds a smart vector of textures\sounds.
-Factory hold a map of type of object and his function.
-Menu holds a vector of tuple which holds every button and his command.
//----------------------------------------------------------------------------
6. Algorithems that are worth mentioning:
- Menu : using a Command pattern, I was able to create a generic menu that have
	have multiple screens and can move back and forth between them.
- CollisionHandling : set every pair of object (inside the map) a unique function 
	and call that function when they collide.
- Factory : create every type registered in a static way in the compiling,
	and create an object using the set function sent in the begginning.
	registering new types is very easy because its generic.
- Singelton : load all the external files needed for the program in the compiling stage,
	in that way I saved alot of cpu.
- to call the CollisionHandling I used STL-like algorithm to run over all pairs
- all Player keys using Template to avoid duplication of code and the same thing in the menu.
//----------------------------------------------------------------------------
7. Known bugs:
- none
//----------------------------------------------------------------------------
8. Other notes:
- you have to put a "map.txt" file that contain the map.
- the log.txt file incase of a failure will be opened inside the out file.