<h1>Head Soccer Game</h1>

[![HEAD SOCCER GAME](https://img.youtube.com/vi/RueEIrjSXPI/0.jpg)](https://www.youtube.com/watch?v=RueEIrjSXPI "Everything Is AWESOME")

<h2>By Amit Ein-Dor and Adi Gutman</h2>
<h2>General ideas and goals of the project</h2>
<p>A game which every player need to select his character and play against the other player.
the player who scored most goals wins the game.</p>

<p>the problem is making the game movement smooth and real life feeling, 
 adding many options for the player, challenging fun and friendly gameplay,
using the methods learned in class.</p>

<h2>Files</h2>
<p>all files with no description holds the ctrs and methods from headers
-CMakeLists.txt - Cmake file to all src files.</p>

<h2>Classes</h2>
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
<h2>Algorithems that are worth mentioning</h2>
-Menu : using the Command design pattern, I was able to create a generic menu that have
	have multiple screens and can move back and forth between them. 
-<p>CollisionHandling : set every pair of object (inside the map) a unique function 
	and call that function when they collide.</p>
-<p>Factory : create every type registered in a static way in the compiling,
	and create an object using the set function sent in the begginning.
	registering new types is very easy because its generic.</p>
-<p>Singelton : load all the external files needed for the program in the compiling stage,
	in that way I saved alot of cpu.</p>
-<p>to call the CollisionHandling I used STL-like algorithm to run over all pairs</p>
-<p>all Player keys using Template to avoid duplication of code and the same thing in the menu.</p>
//----------------------------------------------------------------------------
<h2>Known bugs</2>
<p> none but if you find any please contact us</p>
//----------------------------------------------------------------------------
8. Other notes:
<p>you have to put a "map.txt" file that contain the map.</p>
<p>the log.txt file incase of a failure will be opened inside the out file.</p>
