<h1>Head Soccer Game</h1>

[![HEAD SOCCER GAME](https://img.youtube.com/vi/RueEIrjSXPI/0.jpg)](https://www.youtube.com/watch?v=RueEIrjSXPI "Everything Is AWESOME")

<h2>By Amit Ein-Dor and Adi Gutman</h2>
<h2>General ideas and goals of the project</h2>
<p>A game which every player need to select his character and play against the other player.
the player who scored most goals wins the game.</p>

<p>The problem is making the game movement smooth and real life feeling, 
 adding many options for the player, challenging fun and friendly gameplay,
using the methods learned in class.</p>

<h2>Classes</h2>
<ul>
	<li><p>main - the main class, use to startup the program </p></li>
	<li><p>Controller - the operative class </p></li>
	<li><p>Object - any kind of objects printed on the screen inherit from this basic object class. </p></li>
	<li><p>Board - read from the file and convert the data to an array of objects, then holds and manage the objects </p></li>
	<li><p>Textures\sounds_E - singelton, holds all the textures\sounds needed for the game </p></li>
	<li><p>Resources - cut the animations from the spritesheet </p></li>
	<li><p>Animation\AnimationData - change the texture according to the animation </p></li>
	<li><p>CollisionHandling - In charge of controlling the collision between objects </p></li>
	<li><p>Collision.cpp - external library - make the collision perfectly on pixel </p></li>
</ul>

<h2>objects</h2>
<ul>
	<li><p>MovingObject - a class that inherit from it is an object that can move: all types of characters, ball</p></li>
	<li><p>StaticObject - a class that inherit from it is an object that can't move: foot, yeti, goal</p></li>
</ul>
//----------------------------------------------------------------------------
<h2> Data structures </h2>
<ul>
	<li><p>Board make a vector of Objects and print it each round.</p></li>
	<li><p>CollisionHandling have a map of two object, which is every pair and their unique collision function.</p></li>
	<li><p>every moving object has an animation structure.</p></li>
	<li><p>sound\Texture singelton holds a smart vector of textures\sounds.</p></li>
	<li><p>Factory hold a map of type of object and his function.</p></li>
	<li><p>Menu holds a vector of tuple which holds every button and his command.</p></li>
	</ul>
	
<h2>Algorithems that are worth mentioning</h2>

<ul>
  <li><p>Menu : using the Command design pattern, I was able to create a generic menu that have
	have multiple screens and can move back and forth between them. </p></li>
  <li><p>CollisionHandling : set every pair of object (inside the map) a unique function 
	and call that function when they collide.</p></li>
	<li><p>Factory : create every type registered in a static way in the compiling,
	and create an object using the set function sent in the begginning.
	registering new types is very easy because its generic.</p>	</li>
	<li><p>Singelton : load all the external files needed for the program in the compiling stage,
	in that way I saved alot of cpu.</p>	</li>
	<li><p>to call the CollisionHandling I used STL-like algorithm to run over all pairs of objects</p>	</li>
	<li><p>all Player keys using Template to avoid duplication of code.</p>	</li>
</ul>

<h2>Files</h2>
<p>all files with no description holds the ctrs and methods from headers
-CMakeLists.txt - Cmake file to all src files.</p>

<h2>Known bugs</h2>
<p>none but if you find any please contact us</p>

<h2>Other notes</h2>
<ul>
	<li><p>you have to put a "map.txt" file that contain the map.</p></li>
  <li><p>the log.txt file incase of a failure will be opened inside the out file.</p></li>
</ul>
