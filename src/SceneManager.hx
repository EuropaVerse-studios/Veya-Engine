package;

import flixel.FlxG;
import flixel.FlxState;

class SceneManager {
	public function new() {}

	public function switchScene(state:FlxState):Void {
		FlxG.switchState(state);
	}

	public function resetScene():Void {
		FlxG.resetState();
	}
}
