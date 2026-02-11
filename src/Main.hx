package;

import flixel.FlxGame;
import openfl.display.Sprite;
import states.BootState;

class Main extends Sprite {
	public function new() {
		super();
		addChild(new FlxGame(0, 0, BootState, 60, 60, true));

		// Initialize the Engine wrapper
		Engine.init();
	}
}
