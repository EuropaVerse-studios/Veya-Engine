package;

import flixel.FlxState;
import flixel.text.FlxText;
import flixel.FlxG;

/**
 * The base state for the engine. 
 * This is where you will add your custom logic.
 */
class EngineState extends FlxState {
	override public function create():Void {
		super.create();

		var welcomeText = new FlxText(0, 0, 0, "Veya Engine Initialized", 32);
		welcomeText.screenCenter();
		add(welcomeText);

		trace("Engine Ready!");
	}

	override public function update(elapsed:Float):Void {
		super.update(elapsed);

		// Basic hotkeys
		if (FlxG.keys.justPressed.F11) {
			FlxG.fullscreen = !FlxG.fullscreen;
		}
	}
}
