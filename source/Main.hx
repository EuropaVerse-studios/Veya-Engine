package;

import flixel.FlxGame;
import openfl.display.Sprite;

class Main extends Sprite {
	public function new() {
		super();
		// Initial game size, starting state, update rate, draw rate, skip splash, start fullscreen
		addChild(new FlxGame(0, 0, EngineState, 60, 60, true, false));
	}
}
