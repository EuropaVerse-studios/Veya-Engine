package;

import flixel.FlxG;
import flixel.input.keyboard.FlxKey;

class InputManager {
	public function new() {}

	public function isPressed(key:String):Bool {
		// Simple mapping example
		switch (key.toLowerCase()) {
			case "up":
				return FlxG.keys.anyPressed([UP, W]);
			case "down":
				return FlxG.keys.anyPressed([DOWN, S]);
			case "left":
				return FlxG.keys.anyPressed([LEFT, A]);
			case "right":
				return FlxG.keys.anyPressed([RIGHT, D]);
			case "accept":
				return FlxG.keys.anyPressed([ENTER, SPACE, Z]);
			default:
				return false;
		}
	}

	public function justPressed(key:String):Bool {
		switch (key.toLowerCase()) {
			case "up":
				return FlxG.keys.anyJustPressed([UP, W]);
			case "down":
				return FlxG.keys.anyJustPressed([DOWN, S]);
			case "left":
				return FlxG.keys.anyJustPressed([LEFT, A]);
			case "right":
				return FlxG.keys.anyJustPressed([RIGHT, D]);
			case "accept":
				return FlxG.keys.anyJustPressed([ENTER, SPACE, Z]);
			default:
				return false;
		}
	}
}
