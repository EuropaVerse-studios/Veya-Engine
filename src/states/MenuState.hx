package states;

import flixel.FlxState;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.FlxG;

class MenuState extends FlxState {
	override public function create():Void {
		super.create();

		var title = new FlxText(0, 100, 0, "Main Menu", 32);
		title.screenCenter(X);
		add(title);

		var prompt = new FlxText(0, 500, 0, "Press ACCEPT to Start", 16);
		prompt.screenCenter(X);
		add(prompt);
	}

	override public function update(elapsed:Float):Void {
		super.update(elapsed);

		if (Engine.input.justPressed("accept")) {
			Engine.scene.switchScene(new GameState());
		}
	}
}
